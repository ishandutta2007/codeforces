#include <bits/stdc++.h>

using namespace std;

const int NMAX = 250 + 5;
const int MOD = 1000000000 + 7;

void add(int &where, int val) {
    where += val;
    if (where >= MOD)
        where -= MOD;
}

int N, M;
string mat[NMAX];

// dp[lin][col][maskCol][propRight][failsCount]
int dp[2][16][1 << 15][2][2];

int main()
{
    ios_base :: sync_with_stdio(false);
    //freopen("data.in", "r", stdin);

    cin >> N >> M;
    for (int i = 0; i < N; ++ i)
        cin >> mat[i];

    if (N < M) {
        for (int i = N; i < M; ++ i)
            mat[i].resize(M);
        for (int i = 0; i < M; ++ i)
            for (int j = i + 1; j < M; ++ j)
                swap(mat[i][j], mat[j][i]);
        swap(N, M);
    }

    dp[0][0][0][0][0] = 1;
    for (int lin = 0; lin < N; ++ lin) {
        for (int col = 0; col < M; ++ col)
            for (int mask = 0; mask < (1 << M); ++ mask)
                for (int propRight = 0; propRight < 2; ++ propRight)
                    for (int fails = 0; fails < 2; ++ fails) {
                        if (mat[lin][col] == 'x')
                            add(dp[lin & 1][col + 1][mask & (~(1 << col))][0][fails], dp[lin & 1][col][mask][propRight][fails]);
                        else {
                            //Don't place guard
                            bool guarded = false;
                            if (propRight || (mask & (1 << col)))
                                guarded = true;
                            if (fails + !guarded < 2)
                                add(dp[lin & 1][col + 1][mask][propRight][fails + !guarded], dp[lin & 1][col][mask][propRight][fails]);

                            //Place guard
                            add(dp[lin & 1][col + 1][mask | (1 << col)][1][fails], dp[lin & 1][col][mask][propRight][fails]);
                        }
                    }

        //Going out the matrix gets you to the next row
        memset(dp[(lin + 1) & 1], 0, sizeof(dp[(lin + 1) & 1]));
        for (int mask = 0; mask < (1 << M); ++ mask)
            for (int propRight = 0; propRight < 2; ++ propRight)
                for (int fails = 0; fails < 2; ++ fails)
                    add(dp[(lin + 1) & 1][0][mask][0][fails], dp[lin & 1][M][mask][propRight][fails]);
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << M); ++ mask)
        for (int propRight = 0; propRight < 2; ++ propRight)
            for (int fails = 0; fails < 2; ++ fails)
                add(ans, dp[N & 1][0][mask][propRight][fails]);
    cout << ans << '\n';
    return 0;
}
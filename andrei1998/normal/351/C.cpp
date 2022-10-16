#include <bits/stdc++.h>

using namespace std;

const int NMAX = 21;
const int MMAX = 10000000 + 5;
typedef long long int lint;
const lint INF = 1E14;

int N, M;

int a[NMAX];
int b[NMAX];
int sgn[NMAX];

lint trans[3 * NMAX][3 * NMAX];

lint auxx[3 * NMAX][3 * NMAX];
void expo(lint res[3 * NMAX][3 * NMAX], lint mat1[3 * NMAX][3 * NMAX], lint mat2[3 * NMAX][3 * NMAX]) {
    for (int i = 0; i <= 3 * N; ++ i)
        for (int j = 0; j <= 3 * N; ++ j) {
            auxx[i][j] = INF;
            for (int k = 0; k <= 3 * N; ++ k)
                auxx[i][j] = min(auxx[i][j], mat1[i][k] + mat2[k][j]);
        }
    for (int i = 0; i <= 3 * N; ++ i)
        for (int j = 0; j <= 3 * N; ++ j)
            res[i][j] = auxx[i][j];
}

lint ans[3 * NMAX][3 * NMAX];
lint aux[3 * NMAX][3 * NMAX];

int main()
{
    //freopen("data.in", "r", stdin);
    cin >> N >> M;
    for (int i = 0; i < N; ++ i)
        cin >> a[i];
    for (int i = 0; i < N; ++ i)
        cin >> b[i];

    for (int i = 0; i <= 3 * N; ++ i)
        for (int j = 0; j <= 3 * N; ++ j)
            trans[i][j] = INF;

    for (int mask = 0; mask < (1 << N); ++ mask) {
        for (int i = 0; i < N; ++ i)
            if (mask & (1 << i))
                sgn[i] = 1;
            else
                sgn[i] = -1;

        lint cost = 0;
        int delta = 0;
        int min_delta = 0;
        for (int i = 0; i < N; ++ i) {
            if (sgn[i] == 1)
                cost += a[i];
            else
                cost += b[i];
            delta += sgn[i];
            min_delta = min(min_delta, delta);
        }

        for (int init_state = -min(min_delta, 0); init_state <= 3 * N; ++ init_state)
            if (0 <= init_state + delta && init_state + delta <= 3 * N)
                trans[init_state][init_state + delta] = min(trans[init_state][init_state + delta], cost);
    }

    for (int i = 0; i <= 3 * N; ++ i)
        for (int j = 0; j <= 3 * N; ++ j)
            aux[i][j] = trans[i][j],
            ans[i][j] = INF;
    for (int i = 0; i <= 3 * N; ++ i)
        ans[i][i] = 0;

    while (M) {
        if (M & 1)
            expo(ans, ans, aux);
        expo(aux, aux, aux);
        M >>= 1;
    }

    cout << ans[0][0] << '\n';
    return 0;
}
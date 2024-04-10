#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

const int NMAX = 500000 + 5;
const int MOD = 1000000000 + 7;
typedef long long int lint;
const lint INF = 1e18 + 105;

void add(int &nr, int val) {
    nr += val;
    if (nr >= MOD)
        nr -= MOD;
}

void subtr(int &nr, int val) {
    nr -= val;
    if (nr < 0)
        nr += MOD;
}

int N, H, W;
string str;

void solve(lint dr[], char right, char left, int L, bool rev) {
    int x = 0, maxX = 0;

    for (int i = 1; i <= L; ++ i)
        dr[i] = INF;

    for (int i = 1; i <= N; ++i)
        if (str[i] == right) {
            ++x;
            if (x > maxX) {
                maxX = x;
                if (L + 1 - x >= 1)
                    dr[L + 1 - x] = i;
            }
        }
        else if (str[i] == left)
             --x;

    if (x > 0) {
        for (int i = L - maxX; i >= 1; --i)
            dr[i] = N + dr[i + x];
    }

    if (rev)
        reverse(dr + 1, dr + L + 1);
}

lint dr[NMAX];
lint st[NMAX];
lint jos[NMAX];
lint sus[NMAX];

lint cols[NMAX];
lint lines[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);
    //freopen("data.in", "r", stdin);

    cin >> N >> H >> W;
    cin >> str; str = " " + str;

    solve(dr, 'R', 'L', W, false);
    solve(st, 'L', 'R', W, true);
    solve(jos, 'D', 'U', H, false);
    solve(sus, 'U', 'D', H, true);

    bool hasInf1 = false;
    for (int i = 1; i <= W; ++ i) {
        cols[i] = min(st[i], dr[i]);
        if (cols[i] == INF)
            hasInf1 = true;
    }

    bool hasInf2 = false;
    for (int i = 1; i <= H; ++ i) {
        lines[i] = min(jos[i], sus[i]);
        if (lines[i] == INF)
            hasInf2 = true;
    }

    if (hasInf1 && hasInf2) {
        cout << "-1\n";
        return 0;
    }

    int ans = 0;

    int j1 = 0;
    int j2 = W + 1;
    int s = 0;
    int cntCent = W;

    int i;
    for (i = 1; i <= H; ++ i)
        if (i > 1 && lines[i - 1] > lines[i])
            break;
        else {
            while (j1 + 1 < j2 && cols[j1 + 1] <= lines[i] && cols[j1 + 1] >= cols[j1]) {
                add(s, cols[++j1] % MOD);
                -- cntCent;
            }
            while (j2 - 1 > j1 && cols[j2 - 1] <= lines[i] && cols[j2 - 1] >= cols[j2]) {
                add(s, cols[--j2] % MOD);
                -- cntCent;
            }

            add(ans, s);
            add(ans, (cntCent * (lines[i] % MOD)) % MOD);
        }


    for (; i <= H; ++ i) {
        while (j1 && cols[j1] > lines[i]) {
            subtr(s, cols[j1--] % MOD);
            ++ cntCent;
        }

        while (j2 <= W && cols[j2] > lines[i]) {
            subtr(s, cols[j2++] % MOD);
            ++ cntCent;
        }

        add(ans, s);
        add(ans, (cntCent * (lines[i] % MOD)) % MOD);
    }

    cout << ans << '\n';
    return 0;
}
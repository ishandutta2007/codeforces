#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 1005;
const int MOD = 1e9 + 7, INF = 0x3f3f3f3f;

int Pow(int x, int y) {
    int ret = 1;
    while (y > 0) {
        if (y & 1) ret = (int64_t) ret * x % MOD;
        x = (int64_t) x * x % MOD;
        y /= 2;
    }
    return ret;
}

int invMod(int x) {
    return Pow(x, MOD - 2);
}

int A[NMAX][NMAX];
int rowpr[NMAX][NMAX], colpr[NMAX][NMAX];
int d1pr[NMAX][NMAX], d2pr[NMAX][NMAX];

int maxLenC[NMAX][NMAX];
int maxLend1f[NMAX][NMAX], maxLend1b[NMAX][NMAX];
int maxLend2f[NMAX][NMAX], maxLend2b[NMAX][NMAX];
double rowprd[NMAX][NMAX], colprd[NMAX][NMAX];
double d1prd[NMAX][NMAX], d2prd[NMAX][NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        string S;
        cin >> S;
        for (int j = 1; j <= n; ++j) {
            A[i][j] = S[j - 1] - '0';
        }
    }

    double lg[4];
    for (int i = 1; i < 4; ++i) {
        lg[i] = log(i);
    }

    for (int i = 0; i <= n + 1; ++i) {
        rowpr[0][i] = rowpr[i][0] = 1;
        colpr[0][i] = colpr[i][0] = 1;
        d1pr[0][i] = d1pr[i][0] = 1;
        d2pr[0][i] = d2pr[i][n + 1] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int v = A[i][j] == 0 ? 1: A[i][j];
            rowpr[i][j] = (int64_t) rowpr[i][j - 1] * v % MOD;
            colpr[i][j] = (int64_t) colpr[i - 1][j] * v % MOD;
            d1pr[i][j] = (int64_t) d1pr[i - 1][j - 1] * v % MOD;
            d2pr[i][j] = (int64_t) d2pr[i - 1][j + 1] * v % MOD;

            rowprd[i][j] = rowprd[i][j - 1] + lg[v];
            colprd[i][j] = colprd[i - 1][j] + lg[v];
            d1prd[i][j] = d1prd[i - 1][j - 1] + lg[v];
            d2prd[i][j] = d2prd[i - 1][j + 1] + lg[v];
        }
    }

    memset(maxLenC, INF, sizeof maxLenC);

    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if (A[i][j] == 0) {
                cnt = 0;
                maxLenC[i][j] = 0;
            } else {
                maxLenC[i][j] = min(maxLenC[i][j], ++cnt);
            }
        }
    }
    for (int j = 1; j <= n; ++j) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (A[i][j] == 0) {
                cnt = 0;
            } else {
                maxLenC[i][j] = min(maxLenC[i][j], ++cnt);
            }
        }
    }
    for (int j = 1; j <= n; ++j) {
        int cnt = 0;
        for (int i = n; i > 0; --i) {
            if (A[i][j] == 0) {
                cnt = 0;
            } else {
                maxLenC[i][j] = min(maxLenC[i][j], ++cnt);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = n; j > 0; --j) {
            if (A[i][j] == 0) {
                cnt = 0;
            } else {
                maxLenC[i][j] = min(maxLenC[i][j], ++cnt);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i][j] != 0) {
                maxLend1f[i][j] = maxLend1f[i - 1][j - 1] + 1;
                maxLend2f[i][j] = maxLend2f[i - 1][j + 1] + 1;
            }
        }
    }
    for (int i = n; i > 0; --i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i][j] != 0) {
                maxLend1b[i][j] = maxLend1b[i + 1][j + 1] + 1;
                maxLend2b[i][j] = maxLend2b[i + 1][j - 1] + 1;
            }
        }
    }

    int invm[5];
    for (int i = 1; i < 5; ++i) {
        invm[i] = invMod(i);
    }

    int ans = 0;
    double ansd = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i][j] == 0) continue;
            int cnt = maxLenC[i][j];
            int pr = (int64_t) rowpr[i][j + cnt - 1] * invMod(rowpr[i][j - cnt]) % MOD *
                     colpr[i + cnt - 1][j] % MOD * invMod(colpr[i - cnt][j]) % MOD *
                     invm[A[i][j]] % MOD;
            double prd = rowprd[i][j + cnt - 1] - rowprd[i][j - cnt] + 
                        colprd[i + cnt - 1][j] - colprd[i - cnt][j] -
                        lg[A[i][j]];
            if (prd > ansd) {
                ans = pr;
                ansd = prd;
            }
            
            cnt = min({maxLend1f[i][j], maxLend2f[i][j],
                       maxLend1b[i][j], maxLend2b[i][j]});
            pr = (int64_t) d1pr[i + cnt - 1][j + cnt - 1] *
                 invMod(d1pr[i - cnt][j - cnt]) % MOD *
                 d2pr[i + cnt - 1][j - cnt + 1] % MOD *
                 invMod(d2pr[i - cnt][j + cnt]) % MOD *
                 invm[A[i][j]] % MOD;
            prd = d1prd[i + cnt - 1][j + cnt - 1] - d1prd[i - cnt][j - cnt] +
                  d2prd[i + cnt - 1][j - cnt + 1] - d2prd[i - cnt][j + cnt] -
                  lg[A[i][j]];
            if (prd > ansd) {
                ans = pr;
                ansd = prd;
            }

        }
    }

    cout << ans << '\n';
}
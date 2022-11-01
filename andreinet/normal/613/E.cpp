#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
#define WRITE(x) (cerr << #x << ": " << x << endl)
using namespace std;

typedef long long i64;
const int MOD = 1e9 + 7;
const int NMAX = 2005;

int dp[2][NMAX][NMAX];
bool d[2][NMAX][NMAX];

string reverse(string S) {
    reverse(S.begin(), S.end());
    return S;
}

vector<vector<int>> getLcp(const string& S1, const string& S2) {
    int n = SZ(S1), m = SZ(S2);
    vector<vector<int>> lcp(n + 1, vector<int>(m + 1, 0));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (S1[i] == S2[j]) {
                lcp[i][j] = lcp[i + 1][j + 1] + 1;
            }
        }
    }
    return lcp;
}

int solve(vector<string> A, string P, bool ok = true) {
    int n = SZ(A[0]), k = SZ(P);
    memset(dp, 0, sizeof dp);
    memset(d, 0, sizeof d);

    int ans = 0;
    
    for (int u = 0; u < 2; ++u) {
        vector<vector<int>> lcp = getLcp(A[u ^ 1], P);
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            for (int l = 1; l <= k && i - l >= 0 && A[u][i - l] == P[l - 1]; ++l) {
                int p = lcp[i - l][l];
                if (p == 0 || l == 1) continue;
                if (p > l) {
                    dp[u ^ 1][i + 1][2 * l + 1]++;
                } else if (p + l == k && p == l && ok) {
                    ans++;
                    cnt++;
                }
                if (p >= l) {
                    d[u ^ 1][i][2 * l] = true;
                }
            }
        }
        ans %= MOD;
    }

    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i <= n; ++i) {
            dp[j][i][0] = 1;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int l = 1; l <= k; ++l) {
                if (A[j][i - 1] == P[l - 1]) {
                    dp[j][i][l] = (dp[j][i][l] + dp[j][i - 1][l - 1]) % MOD;
                }
            }
        }
        for (int l = k; l > 1; --l) {
            for (int j = 0; j < 2; ++j) {
                if (k == 2 && j == 1) continue;
                if (A[j][i - 1] == P[l - 1]) {
                    dp[j][i][l] = (dp[j][i][l] + dp[j ^ 1][i][l - 1]) % MOD;
                }
            }
        }
    }
    for (int j = 0; j < 2; ++j) {
        for (int i = 1; i <= n; ++i) {
            //cerr << dp[j][i][3] << ' ';
            ans = (ans + dp[j][i][k]) % MOD;
        }
        //cerr << endl;
    }

    for (int u = 0; u < 2; ++u) {
        vector<vector<int>> lcp = getLcp(reverse(A[u ^ 1]), reverse(P));
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            for (int l = 1; l <= k && i + l - 2 < n && A[u][i + l - 2] == P[k - l]; ++l) {
                int p = lcp[n - (i + l - 2) - 1][l];
                if (l == 1) continue;
                if (p > l) {
                    ans = (ans + dp[u ^ 1][i - 1][k - 2 * l]) % MOD;
                } else if (p + l == k && p == l && ok) {
                    ans = (ans + 1) % MOD;
                    cnt++;
                }
                if (p >= l) {
                    ans = (ans + d[u ^ 1][i - 1][k - 2 * l]) % MOD;
                }
            }
        }
    }

    return ans;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    string S1, S2;
    cin >> S1 >> S2;

    string P;
    cin >> P;

    int ans = solve({S1, S2}, P);
    if (SZ(P) > 1) {
        ans = (ans + solve({S1, S2}, reverse(P), false)) % MOD;
    }

    ans %= MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 2005, MOD = 1000 * 1000 * 1000 + 7, P = 131, M = 1048613741;
int dp[MAXN][2][MAXN], powp[MAXN], h[3][MAXN], rh[3][MAXN];
string c[3], s;

void add(int &a, int b) {
    a += b;
    if(a >= MOD)
        a -= MOD;
}

int getHash(int id, int l, int r) {
    return (h[id][r] + M - (long long)h[id][l] * powp[r - l] % M) % M;
}

int getRevHash(int id, int l, int r) {
    return (rh[id][l] + M - (long long)rh[id][r] * powp[r - l] % M) % M;
}

int solve() {
    int n = c[0].length(), m = s.length();
    c[2] = s;
    for(int id = 0; id < 3; id++) {
        h[id][0] = 0;
        for(size_t i = 0; i < c[id].length(); i++)
            h[id][i + 1] = ((long long)h[id][i] * P + (c[id][i] - 'a' + 1)) % M;
        rh[id][(int)c[id].length()] = 0;
        for(int i = (int)c[id].length() - 1; i >= 0; i--)
            rh[id][i] = ((long long)rh[id][i + 1] * P + (c[id][i] - 'a' + 1)) % M;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < m; k++)
                dp[i][j][k] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < m; k++) {
                if(s[k] != c[j][i])
                    continue;
                if(!(k & 1) && i >= k / 2) {
                    int hc = ((long long)getRevHash(j ^ 1, i - k / 2, i) *
                              powp[k / 2] + getHash(j, i - k / 2, i)) % M;
                    if(hc == getHash(2, 0, k))
                        add(dp[i][j][k], 1);
                }
                if(m > 2 && !(m & 1) && k == m - 1 && i >= k / 2) {
                    int hc = ((long long)getRevHash(j ^ 1, i - k / 2, i + 1) *
                              powp[k / 2] + getHash(j, i - k / 2, i)) % M;
                    if(hc == getHash(2, 0, k))
                        add(dp[i][j][k], 1);
                }
                if(k + 1 < m && i + 1 < n) {
                    if(c[j][i + 1] == s[k + 1])
                        add(dp[i + 1][j][k + 1], dp[i][j][k]);
                    if(k > 0 && k + 2 < m && c[j ^ 1][i] == s[k + 1] &&
                       c[j ^ 1][i + 1] == s[k + 2])
                        add(dp[i + 1][j ^ 1][k + 2], dp[i][j][k]);
                }
                if(!((m - k) & 1) && n - i >= (m - k) / 2) {
                    int hc = ((long long)getHash(j, i + 1, i + (m - k) / 2) *
                              powp[(m - k) / 2] +
                              getRevHash(j ^ 1, i, i + (m - k) / 2)) % M;
                    if(hc == getHash(2, k + 1, m))
                        add(dp[i][j ^ 1][m - 1], dp[i][j][k]);
                }
            }
    int res = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 2; j++)
            add(res, dp[i][j][m - 1]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    powp[0] = 1;
    for(int i = 1; i < MAXN; i++)
        powp[i] = (long long)powp[i - 1] * P % M;
    cin >> c[0] >> c[1] >> s;
    int n = c[0].length(), m = s.length();
    int ans = solve();
    reverse(s.begin(), s.end());
    if(m > 1)
        add(ans, solve());
    if(!(m & 1)) {
        for(int i = 0; i + m / 2 <= n; i++)
            for(int j = 0; j < 2; j++)
                if(((long long)getHash(j, i, i + m / 2) * powp[m / 2] +
                    getRevHash(j ^ 1, i, i + m / 2)) % M == getHash(2, 0, m))
                    add(ans, MOD - 1);
        if(m > 2)
            for(int i = m / 2; i <= n; i++)
                for(int j = 0; j < 2; j++)
                    if(((long long)getRevHash(j, i - m / 2, i) * powp[m / 2] +
                        getHash(j ^ 1, i - m / 2, i)) % M == getHash(2, 0, m))
                        add(ans, MOD - 1);
    }
    cout << ans << '\n';
    return 0;
}
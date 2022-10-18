#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 705;
int ans = 0, mod = 1e9 + 7;
int cnt[10], st[maxn], in[11][maxn];
int dp[10][maxn][maxn], C[maxn][maxn];
int F[10][maxn], goal[10][maxn];
int rev[maxn], sz;

inline int add(int start, int j, int k, int N) {
    return F[j][N] * k % mod * rev[maxn - 1 - (sz - start - 1)] % mod;
}

void solve(int N) {
    if (N == 0) {
        int l = 0;
        for (int j = 0; j <= 9; ++j) {
            if (cnt[j]) {
                ans = (ans + dp[j][l][l + cnt[j] - 1]) % mod;
                l += cnt[j];
            }
        }
        return;
    }
    int L_sum = cnt[0];
    for (int j = 1; j <= 9; ++j) {
        for (int k = 0; k <= N; ++k) {
            int w = C[N][k] * in[j][k] % mod;
            if (cnt[j] != 0) {
                ans = (ans + w * dp[j][L_sum + k][L_sum + k + cnt[j] - 1] % mod * in[9 - j + 1][N - k]) % mod;
            }
            ans = (ans + add(L_sum + k + cnt[j], j, w, N - k)) % mod;
        }
        L_sum += cnt[j];
    }
}

int go(int x, int y) {
    if (y == 0) return 1;
    if (y % 2 == 0) {
        int c = go(x, y / 2);
        return c * c % mod;
    }
    return x * go(x, y - 1) % mod;
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    sz = s.size();
    st[(int)s.size() - 1] = 1;
    for (int i = (int)s.size() - 2; i >= 0; --i) {
        st[i] = st[i + 1] * 10 % mod;
    }
    for (int j = 0; j <= 10; ++j) {
        in[j][0] = 1;
        for (int i = 1; i < maxn; ++i) in[j][i] = in[j][i - 1] * j % mod;
    }
    for (int i = 0; i < maxn; ++i) rev[i] = go(in[10][i], mod - 2);
    for (int i = 0; i < maxn; ++i) C[i][0] = 1;
    for (int i = 1; i < maxn; ++i) {
        for (int j = 1; j < maxn; ++j) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }
    for (int t = 0; t < 10; ++t) {
        for (int i = 0; i < (int)s.size(); ++i) {
            for (int j = i; j < (int)s.size(); ++j) {
                if (i == j) dp[t][i][j] = t * st[i] % mod;
                else dp[t][i][j] = (dp[t][i][j - 1] + t * st[j]) % mod;
            }
        }
    }
    for (int i = 0; i <= 9; ++i) {
        for (int j = 1; j < maxn; ++j) {
            goal[i][j] = (goal[i][j - 1] + i * in[10][maxn - j]) % mod;
        }
    }
    for (int i = 0; i <= 9; ++i) {
        for (int z = 0; z <= (int)s.size(); ++z) {
            for (int c = 1; c <= z; ++c) {
                F[i][z] = (F[i][z] + C[z][c] * in[9 - i][z - c] % mod * goal[i][c]) % mod;
            }
        }
    }
    for (int i = 0; i < (int)s.size(); ++i) {
        int stop;
        if (i == (int)s.size() - 1) stop = s[i] - '0';
        else stop = s[i] - '0' - 1;
        for (int j = 0; j <= stop; ++j) {
            if (i == 0 && j == 0) continue;
            cnt[j]++;
            solve((int)s.size() - i - 1);
            cnt[j]--;
        }
        cnt[s[i] - '0']++;
    }
    //cout << answ << endl;
    for (int i = 1; i < (int)s.size(); ++i) {
        for (int j = i; j < (int)s.size(); ++j) {
            for (int w = 0; w <= 9; ++w) {
                ans = (ans + dp[w][i][j] * in[w][i - 1] % mod
                    * in[9 - w][(int)s.size() - j - 1] % mod
                    * C[(int)s.size() - 1][i - 1] % mod
                    * C[(int)s.size() - i][j - i + 1]) % mod;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
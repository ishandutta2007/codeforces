#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define X first
#define Y second
#define test(args...) abc("[" + string(#args) + "]", args)
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; l++) cout << *l << " \n"[l + 1 == r];
}
const int mod = 998244353, N = 18;

int dp[1 << N], cnt[1 << N], pre[N][1 << N];
bool edge[N][N], fail[1 << N];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        edge[u][v] = true;
    }
    vector <int> bit(1 << n, -1);
    for (int s = 0; s < 1 << n; ++s) {
        for (int i = 0; i < n; ++i) if (s >> i & 1) {
            for (int j = 0; j < n; ++j) if (s >> j & 1) {
                fail[s] |= edge[i][j];
            }
        } 
        fail[s] = !fail[s];
        if (s) {
            int lowbit = s & (-s);
            bit[s] = bit[s ^ lowbit] * -1;
        }
    }
    for (int s = 1; s < 1 << n; ++s) {
        if (fail[s]) {
            dp[s] = 1;
        } else {
            for (int t = s; t > 0; t = (t - 1) & s) if (fail[t] && s != t) {
                if (bit[t] == 1) {
                    dp[s] += dp[s ^ t];
                    if (dp[s] >= mod) dp[s] -= mod;
                } else {
                    dp[s] -= dp[s ^ t];
                    if (dp[s] < 0) dp[s] += mod;
                }
            }
        }
    }
    cout << 1ll * dp[(1 << n) - 1] * m % mod * ((mod + 1) / 2) % mod << endl;
}
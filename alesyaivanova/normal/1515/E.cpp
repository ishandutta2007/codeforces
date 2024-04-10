#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 400 + 9;
int cnt[maxn];
int dp[maxn][maxn];
int n;
int mod;
int C[maxn][maxn];

int mult(int a, int b) {
    return (a * 1ll * b) % mod;
}

int add(int a, int b) {
    return (a + b) % mod;
}

void solve() {
    cin >> n >> mod;
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i][0] = 1;
        for (int e = 1; e <= n; e++) {
            C[i][e] = add(C[i - 1][e], C[i - 1][e - 1]);
        }
    }
    cnt[1] = 1;
    for (int len = 2; len <= n; len++) {
        cnt[len] = mult(cnt[len - 1], 2);
    }
    for (int len = 1; len <= n; len++) {
        dp[len][len] = cnt[len];
        for (int num = len - 1; num >= 1; num--) {
            for (int lst = 1; lst <= len - 2 && lst <= num - 1; lst++) {
                dp[len][num] = add(dp[len][num], mult(mult(dp[len - lst - 1][num - lst], cnt[lst]), C[num][lst]));
            }
        }
    }
    int ans = 0;
    for (int num = 1; num <= n; num++)
        ans = add(ans, dp[n][num]);
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}
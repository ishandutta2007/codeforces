#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << endl;\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 105, logN = 18, K = 600, C = 100, M = 1e9;

vector <lli> a;

lli dp[N][N][N];
string s;

lli solve(int l, int r, int k) {
    if (l >= r) return 0;
    if (dp[l][r][k] != -1) return dp[l][r][k];
    dp[l][r][k] = a[k] + solve(l + 1, r, 1);
    for (int i = l + 1; i < r; ++i) {
        if (s[i] == s[l]) {
            dp[l][r][k] = max(dp[l][r][k], solve(l + 1, i, 1) + solve(i, r, k + 1));
        }
    }
    return dp[l][r][k];
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fop (i,0,N) fop (j,0,N) fop (k,0,N) dp[i][j][k] = -1;
    int n;
    cin >> n;
    cin >> s;
    a.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = 1; j < i; ++j) {
            a[i] = max(a[i], a[j] + a[i - j]);
        }
    }
    cout << solve(0, n, 1) << endl;
}
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 1 << 21, logN = 17, K = 90002;

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    fop (i,0,n) cin >> a[i];
    if (n == 1) {
        cout << a[0] << endl;
        return;
    }
    int dp[n][2];
    dp[0][0] = a[0] == 1;
    dp[0][1] = 1 << 30;
    dp[1][0] = (a[0] == 1) + (a[1] == 1);
    dp[1][1] = a[0] == 1;
    fop (i,2,n) {
        dp[i][0] = min(dp[i - 1][1] + (a[i] == 1), (i - 2 >= 0 ? dp[i - 2][1] + (a[i] == 1) + (a[i - 1] == 1) : 1 << 30));
        dp[i][1] = min(dp[i - 1][0], (i - 2 >= 0 ? dp[i - 2][0] : 1 << 30));
    }
    //fop (i,0,n) cout << dp[i][0] << ' ' << dp[i][1] << endl;
    cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
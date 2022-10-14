#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pdd pair<ld,ld>
typedef long double ld;
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 300087, logN = 17, K = 500;

void solve() {
    int n, m;
    cin >> n >> m;
    lli a[n][m];
    fop (i,0,n) fop (j,0,m) cin >> a[i][j];
    lli ans = 0;
    for (int i = 0; i <= n - i - 1; ++i) {
        for (int j = 0; j <= m - j - 1; ++j) {
            vector <lli> v;
            if (i == n - i - 1 && j == m - j - 1) continue;
            else if (i == n - i - 1) {
                v = {a[i][j], a[i][m - j - 1]};

            } else if (j == m - j - 1) {
                v = {a[i][j], a[n - i - 1][j]};
            } else {
                v = {a[i][j], a[n - i - 1][j], a[i][m - j - 1], a[n - i - 1][m - j - 1]};
            }
            sort(all(v));
            int m = v.size();
            fop (i,0,m) ans += abs(v[i] - v[m >> 1]);
        }
    }
    cout << ans << endl;
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
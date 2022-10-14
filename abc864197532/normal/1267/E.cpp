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

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a[m][n], all[n] = {};
    fop (i,0,m) fop (j,0,n) cin >> a[i][j], all[j] += a[i][j];
    vector <int> dp(n - 1, 1 << 30);
    fop (i,0,n - 1) {
        vector <int> d;
        fop (j,0,m) {
            d.pb(a[j][i] - a[j][n - 1]);
        }
        sort(all(d));
        int de = all[n - 1] - all[i];
        if (de <= 0) {
            dp[i] = 0;
            break;
        }
        fop (j,0,m) {
            de += d[j];
            if (de <= 0) {
                dp[i] = j + 1;
                break;
            }
        }
    }
    int i = min_element(all(dp)) - dp.begin();
    vector <pii> d;
    fop (j,0,m) {
        d.eb(a[j][i] - a[j][n - 1], j + 1);
    }
    sort(all(d));
    vector <int> ans;
    int de = all[n - 1] - all[i];
    if (de <= 0) {
        cout << 0 << endl;
        return 0;
    }
    fop (j,0,m) {
        de += d[j].X;
        ans.pb(d[j].Y);
        if (de <= 0) {
            break;
        }
    }
    cout << ans.size() << endl;
    printv(ans);
}
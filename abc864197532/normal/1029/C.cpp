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
    int n;
    cin >> n;
    vector <int> l(n), r(n);
    fop (i,0,n) cin >> l[i] >> r[i];
    int p = 0, q = 0;
    fop (i,1,n) {
        if (l[p] < l[i] || (l[p] == l[i] && r[p] > r[i])) p = i;
    }
    fop (i,1,n) {
        if (r[q] > r[i] || (r[q] == r[i] && l[q] < l[i])) q = i;
    }
    int mn = 1 << 30, mx = -1 << 30, ans = 0;
    fop (i,0,n) if (i != p) {
            mn = min(mn, r[i]);
            mx = max(mx, l[i]);
        }
    ans = max(ans, mn - mx);
    mn = 1 << 30, mx = -1 << 30;
    fop (i,0,n) if (i != q) {
        mn = min(mn, r[i]);
        mx = max(mx, l[i]);
    }
    ans = max(ans, mn - mx);
    cout << ans << endl;
}
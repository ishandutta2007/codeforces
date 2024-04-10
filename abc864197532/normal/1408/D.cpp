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
    vector <pii> a(n), b(m);
    fop (i,0,n) cin >> a[i].X >> a[i].Y;
    fop (i,0,m) cin >> b[i].X >> b[i].Y;
    vector <pii> add;
    add.eb(0, 0);
    fop (i,0,n) fop (j,0,m) {
        int x = max(0, b[j].X - a[i].X + 1), y = max(0, b[j].Y - a[i].Y + 1);
        add.eb(x, y);
    }
    sort(all(add));
    int ans = 1 << 30;
    vector <int> suf(n * m + 2, 0);
    FOP (i,n * m + 1,0) suf[i] = max(suf[i + 1], add[i].Y);
    fop (i,0,n * m + 1) {
        ans = min(ans, add[i].X + suf[i + 1]);
    }
    cout << ans << endl;
}
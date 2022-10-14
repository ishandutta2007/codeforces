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
const int mod = 998244353, x = 864197532, N = 500001, logN = 17, K = 500;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    map <int, int> mn, mx;
    fop (i,0,n) {
        cin >> a[i];
        if (!mn.count(a[i])) {
            mn[a[i]] = i;
            mx[a[i]] = i;
        } else {
            mx[a[i]] = max(mx[a[i]], i);
        }
    }
    vector <pii> seg;
    for (pii A : mn) {
        int x, y;
        tie(x, y) = A;
        seg.eb(y, mx[x]);
    }
    sort(all(seg));
    vector <pii> seg2;
    for (pii A : seg) {
        if (seg2.empty() || seg2.back().Y < A.X) seg2.pb(A);
        else seg2.back().Y = max(seg2.back().Y, A.Y);
    }
    lli ans = 1;
    seg2.pop_back();
    while (seg2.size()) ans = ans * 2 % mod, seg2.pop_back();
    cout << ans << endl;
}
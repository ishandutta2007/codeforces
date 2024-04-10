#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
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
const int mod = 1000007, x = 864197532, N = 200000;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x, y, z, q, xx, yy;
    cin >> n >> m >> x >> y >> z >> q;
    x %= 4; y %= 2; z %= 4;
    z = (4 - z) % 4;
    while (q--) {
        cin >> xx >> yy;
        if (x == 1) {
            tie(xx, yy) = mp(yy, n + 1 - xx);
        } else if (x == 2) {
            tie(xx, yy) = mp(n + 1 - xx, m + 1 - yy);
        } else if (x == 3) {
            tie(xx, yy) = mp(m + 1 - yy, xx);
        }
        if (y) {
            if (x % 2 == 1) {
                yy = n + 1 - yy;
            } else {
                yy = m + 1 - yy;
            }
        }
        if (x % 2 == 1) swap(n, m);
        if (z == 1) {
            tie(xx, yy) = mp(yy, n + 1 - xx);
        } else if (z == 2) {
            tie(xx, yy) = mp(n + 1 - xx, m + 1 - yy);
        } else if (z == 3) {
            tie(xx, yy) = mp(m + 1 - yy, xx);
        }
        if (x % 2 == 1) swap(n, m);
        cout << xx << ' ' << yy << endl;
    }
}
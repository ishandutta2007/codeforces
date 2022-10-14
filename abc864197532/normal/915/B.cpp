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
#define ld double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 30087, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p, l, r;
    cin >> n >> p >> l >> r;
    int k = 0;
    if (l != 1 && r != n) {
        if (p < l) {
            cout << r - p + 2 << endl;
        } else if (r < p) {
            cout << p - l + 2 << endl;
        } else {
            cout << min(r - p, p - l) + r - l + 2 << endl;
        }
    } else if (l != 1) {
        cout << abs(p - l) + 1 << endl;
    } else if (r != n) {
        cout << abs(p - r) + 1 << endl;
    } else {
        cout << 0 << endl;
    }
}
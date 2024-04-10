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
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 5000, logN = 17, K = 90002;

struct Move {
    int i, j, x;
};

void solve() {
    int n;
    cin >> n;
    vector <int> a(n + 1, 0);
    fop (i,1,n + 1) cin >> a[i];
    int all = accumulate(all(a), 0);
    if (all % n) {
        cout << -1 << endl;
        return;
    }
    vector <Move> ans;
    fop (i,2,n + 1) {
        int need = (i - a[i] % i) % i;
        assert(need <= a[1]);
        ans.pb({1, i, need});
        a[1] -= need;
        a[i] += need;
        ans.pb({i, 1, a[i] / i});
        a[1] += a[i];
        a[i] = 0;
    }
    fop (i,2,n + 1) {
        ans.pb({1, i, all / n});
    }
    cout << ans.size() << endl;
    for (Move &m : ans) cout << m.i << ' ' << m.j << ' ' << m.x << endl;
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
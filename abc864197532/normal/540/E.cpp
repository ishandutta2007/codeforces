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
const int mod = 1e9 + 7, x = 864197532, N = 200087, logN = 17;

lli bit[N] = {};

void add(int p, int v) {
    for (int i = p; i <= N; i += i & (-i)) bit[i] += v;
}

lli query(int p) {
    lli ans = 0;
    for (int i = p; i > 0; i -= i & (-i)) ans += bit[i];
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <pii> q(n);
    vector <int> v;
    fop (i,0,n) cin >> q[i].X >> q[i].Y, v.pb(q[i].X), v.pb(q[i].Y);
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    vector <int> cur(v.size(), 0);
    iota(all(cur), 0);
    fop (i,0,n) {
        int a = lower_bound(all(v), q[i].X) - v.begin(), b = lower_bound(all(v), q[i].Y) - v.begin();
        swap(cur[a], cur[b]);
    }
    lli ans = 0;
    fop (i,0,v.size()) {
        ans += query(N) - query(cur[i] + 1);
        add(cur[i] + 1, 1);
    }
    fop (i,0,N) bit[i] = 0;
    fop (i,0,v.size()) {
        if (i < cur[i]) {
            ans += v[cur[i]] - v[i] - (lower_bound(all(v), v[cur[i]]) - lower_bound(all(v), v[i]));
        } else if (i > cur[i]) {
            ans += v[i] - v[cur[i]] - (lower_bound(all(v), v[i]) - lower_bound(all(v), v[cur[i]]));
        }
    }
    cout << ans << endl;
}
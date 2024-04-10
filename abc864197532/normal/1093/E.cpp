#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << endl;\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 200087, logN = 18, K = 600, C = 100, M = 1e9;

struct query {
    int id, p, v;
};

struct BIT {
    int val[N];
    vector <pair <int, int>> change;
    void init() {
        for (int i = 0; i < N; ++i) {
            val[i] = 0;
        }
    }
    void add(int p, int v, bool is = true) {
        for (int i = p; i < N; i += i & (-i)) val[i] += v;
        if (is) change.eb(p, v);
    }
    int query(int p) {
        int ans = 0;
        for (int i = p; i > 0; i -= i & (-i)) ans += val[i];
        return ans;
    }
    void reset() {
        while (change.size()) {
            add(change.back().X, -change.back().Y, false);
            change.pop_back();
        }
    }
} bit;

vector <query> Q;
vector <int> ans;

void cdq(int l, int r) {
    if (r - l == 1) return;
    int m = l + r >> 1, i, j;
    cdq(l, m); cdq(m, r);
    vector <query> now;
    for (i = l, j = m; i < m && j < r; ) {
        if (Q[i].p <= Q[j].p) {
            if (Q[i].id < 0) {
                if (Q[i].v > 0) bit.add(Q[i].v + 1, 1);
                else bit.add(-Q[i].v + 1, -1);
            }
            now.pb(Q[i++]);
        } else {
            if (Q[j].id >= 0) ans[Q[j].id] += bit.query(Q[j].v + 1);
            now.pb(Q[j++]);
        }
    }
    for (; i < m; ) now.pb(Q[i++]);
    for (; j < r; ) {
        if (Q[j].id >= 0) ans[Q[j].id] += bit.query(Q[j].v + 1);
        now.pb(Q[j++]);
    }
    for (int k = l; k < r; ++k) {
        Q[k] = now[k - l];
    }
    bit.reset();
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector <int> a(n + 1), p(n + 1), b(n + 1);
    fop (i,1,n + 1) cin >> a[i], p[a[i]] = i;
    iota(all(a), 0);
    fop (i,1,n + 1) cin >> b[i], b[i] = p[b[i]], Q.pb({-1, i, b[i]});
    vector <bool> is(q, false);
    fop (i,0,q) {
        int t, l, r, lb, rb;
        cin >> t >> l >> r;
        if (t == 1) {
            is[i] = true;
            cin >> lb >> rb, lb--, l--;
            Q.pb({4 * i, rb, r});
            Q.pb({4 * i + 1, lb, r});
            Q.pb({4 * i + 2, rb, l});
            Q.pb({4 * i + 3, lb, l});
        } else {
            Q.pb({-1, l, -b[l]});
            Q.pb({-1, r, -b[r]});
            Q.pb({-1, r, b[l]});
            Q.pb({-1, l, b[r]});
            swap(b[l], b[r]);
        }
    }
    ans.assign(4 * q, 0);
    cdq(0, Q.size());
    fop (i,0,q) {
        if (!is[i]) continue;
        cout << ans[4 * i] - ans[4 * i + 1] - ans[4 * i + 2] + ans[4 * i + 3] << '\n';
    }
}
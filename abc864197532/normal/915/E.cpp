#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 587, logN = 17;

vector <int> pre;

struct Seg {
    int l, r, m, sum, lz;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
        sum = pre[r] - pre[l];
        lz = -1;
    }
    void pull() {
        sum = ch[0]->sum + ch[1]->sum;
    }
    void push() {
        if (r - l > 1 && ~lz) {
            ch[0]->lz = lz;
            ch[0]->sum = (lz ? pre[m] - pre[l] : 0);
            ch[1]->lz = lz;
            ch[1]->sum = (lz ? pre[r] - pre[m] : 0);
        }
        lz = -1;
    }
    void add(int a, int b, int v) {
        if (a <= l && r <= b) {
            lz = v;
            sum = (v ? pre[r] - pre[l] : 0);
        } else {
            push();
            if (a < m) ch[0]->add(a, b, v);
            if (m < b) ch[1]->add(a, b, v);
            pull();
        }
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, l, r, k;
    cin >> n >> q;
    vector <pair<pair <int, int>, int>> v(q);
    vector <int> p;
    fop (i,0,q) {
        cin >> v[i].X.X >> v[i].X.Y >> v[i].Y;
        v[i].X.X--, v[i].Y--;
        p.pb(v[i].X.X);
        p.pb(v[i].X.Y);
    }
    p.pb(0);
    p.pb(n);
    sort(all(p));
    p.resize(unique(all(p)) - p.begin());
    pre = p;
    Seg root(0, p.size() - 1);
    fop (i,0,q) {
        //l = uniform_int_distribution<int>(1, n)(rng) - 1;
        //r = uniform_int_distribution<int>(1, n)(rng);
        //k = uniform_int_distribution<int>(1, 2)(rng) - 1;
        tie(l, r) = v[i].X;
        k = v[i].Y;
        l = lower_bound(all(p), l) - p.begin();
        r = lower_bound(all(p), r) - p.begin();
        root.add(l, r, k);
        cout << root.sum << '\n';
    }
}
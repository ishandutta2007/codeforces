#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
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
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 200000, logN = 17, K = 350;

struct Seg {
    int l, r, m, sum = 0;
    Seg* ch[2] = {NULL, NULL};
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1) {
        if (r - l != 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
            pull();
        }
    }
    void pull() {
        sum = ch[0]->sum ^ ch[1]->sum;
    }
    void set(int p, int v) {
        if (r - l == 1) sum = v;
        else {
            ch[p >= m]->set(p, v);
            pull();
        }
    }
    int query(int a, int b) {
        if (a <= l && r <= b) return sum;
        int ans = 0;
        if (a < m) ans ^= ch[0]->query(a, b);
        if (m < b) ans ^= ch[1]->query(a, b);
        return ans;
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, y, q;
    cin >> n;
    vector <int> a(n), pre(n + 1, 0);
    fop (i,0,n) cin >> a[i], pre[i + 1] = pre[i] ^ a[i];
    cin >> q;
    vector <pii> Q[n];
    fop (i,0,q) {
        cin >> x >> y; x--; y--;
        Q[y].eb(x, i);
    }
    Seg root(0, n);
    map <int, int> m1;
    vector <int> ans(q);
    fop (i,0,n) {
        if (m1.count(a[i])) {
            root.set(m1[a[i]], 0);
        }
        root.set(i, a[i]);
        m1[a[i]] = i;
        for (pii A : Q[i]) {
            ans[A.Y] = pre[i + 1] ^ pre[A.X] ^ root.query(A.X, i + 1);
        }
    }
    printv(ans);
}
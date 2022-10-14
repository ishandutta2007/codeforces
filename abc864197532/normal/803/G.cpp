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
const int mod = 1e9 + 7, x = 864197532, N = 100087, logN = 18, K = 500, C = 1e5 + 87;

vector <int> a;
int st[N][logN];

void build() {
    for (int i = 1; i < logN; ++i) {
        for (int j = 0; j + (1 << i) <= N; ++j) {
            st[j][i] = min(st[j][i - 1], st[j + (1 << i - 1)][i - 1]);
        }
    }
}

int query(int l, int r) {
    if (l == r) return 1 << 30;
    int g = __lg(r - l);
    return min(st[l][g], st[r - (1 << g)][g]);
}

int n;

int Query(int a, int b) {
    //cout << a << ' ' << b << endl;
    if (b - a >= n) return query(0, n);
    a %= n, b %= n;
    if (a < b) return query(a, b);
    return min(query(a, n), query(0, b));
}

struct Seg {
    int l, r, m, lz, sum;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1) {
        ch[0] = ch[1] = NULL;
        lz = 0;
        sum = Query(l, r);
    }
    void pull() {sum = min((ch[0] ? ch[0]->sum : Query(l, m)), (ch[1] ? ch[1]->sum : Query(m, r)));}
    void push() {
        if (lz) {
            if (!ch[0]) ch[0] = new Seg(l, m);
            ch[0]->sum = lz;
            ch[0]->lz = lz;
            if (!ch[1]) ch[1] = new Seg(m, r);
            ch[1]->sum = lz;
            ch[1]->lz = lz;
        }
        lz = 0;
    }
    void add(int a, int b, int v) {
        //cout << a << ' ' << b << ' ' << l << ' ' << r << endl;
        if (a <= l && r <= b) {
            sum = v;
            lz = v;
        } else {
            push();
            if (a < m) {
                if (!ch[0]) ch[0] = new Seg(l, m);
                ch[0]->add(a, b, v);
            }
            if (m < b) {
                if (!ch[1]) ch[1] = new Seg(m, r);
                ch[1]->add(a, b, v);
            }
            pull();
        }
    }
    int query(int a, int b) {
        // cout << l << ' ' << r << endl;
        push();
        if (a <= l && r <= b) return sum;
        int ans = 1 << 30;
        if (a < m) {
            if (ch[0]) ans = min(ans, ch[0]->query(a, b));
            else ans = min(ans, Query(a, min(m, b)));
        }
        if (m < b) {
            if (ch[1]) ans = min(ans, ch[1]->query(a, b));
            else ans = min(ans, Query(max(m, a), b));
        }
        pull();
        return ans;
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k, q, l, r, t, x;
    cin >> n >> k;
    a.resize(n);
    fop (i,0,n) cin >> a[i], st[i][0] = a[i];
    fop (i,n,N) st[i][0] = 1 << 30;
    build();
    Seg root(0, n * k);
    cin >> q;
    while (q--) {
        cin >> t >> l >> r, l--;
        if (t == 1) {
            cin >> x;
            root.add(l, r, x);
        } else {
            int tmp = root.query(l, r);
            cout << tmp << endl;
        }
    }
    
}
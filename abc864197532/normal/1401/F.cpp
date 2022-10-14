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
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 1000000, logN = 17;

vector <pii> v;

int n;

struct Seg {
    int l, r, m;
    lli sum = 0;
    Seg* ch[2];
    Seg (int _l, int _r, vector <int> &a) : l(_l), r(_r), m(l + r >> 1) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m, a);
            ch[1] = new Seg(m, r, a);
            pull();
        } else {
            sum = a[l];
        }
    }
    void pull() {sum = ch[0]->sum + ch[1]->sum;}
    void set(int p, int v) {
        if (r - l == 1) sum = v;
        else {
            ch[p >= m]->set(p, v);
            pull();
        }
    }
    lli query(int a, int b) {
        if (a <= l && r <= b) return sum;
        lli ans = 0;
        if (a < m) ans += ch[0]->query(a, b);
        if (m < b) ans += ch[1]->query(a, b);
        return ans;
    }
    void query(int a, int b, int k) {
        if (a <= l && r <= b) {
            k &= ((1 << n) - 1) ^ ((1 << __lg(r - l)) - 1);
            v.eb(l ^ k, (r - 1) ^ k);
        } else {
            if (a < m) ch[0]->query(a, b, k);
            if (m < b) ch[1]->query(a, b, k);
        }
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q, t, l, r, k = 0;
    cin >> n >> q;
    vector <int> a(1 << n);
    for (int &i : a) cin >> i;
    Seg root(0, 1 << n, a);
    while (q--) {
        cin >> t >> l;
        if (t == 1) {
            cin >> r; l--;
            root.set(l ^ k, r);
        } else if (t == 2) {
            k ^= ((1 << l) - 1);
        } else if (t == 3) {
            k ^= (1 << l);
        } else {
            cin >> r; l--;
            v.clear();
            root.query(l, r, k);
            lli ans = 0;
            for (auto A : v) {
                if (A.X > A.Y) swap(A.X, A.Y);
                ans += root.query(A.X, A.Y + 1);
            }
            cout << ans << endl;
        }
    }
}
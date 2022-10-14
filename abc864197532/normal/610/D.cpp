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
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 1 << 30, logN = 17, K = 90002;

struct Seg {
    int l, r, m;
    Seg* ch[2];
    lli sum = 0, vv = 0;
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1) {
        ch[0] = ch[1] = NULL;
    }
    void pull() {sum = (ch[0] ? ch[0]->sum : 0) + (ch[1] ? ch[1]->sum : 0);}
    void add(int p, int v) {
        if (r - l == 1) {
            vv += v;
            sum = (vv ? 1 : 0);
        } else {
            if (p < m) {
                if (!ch[0]) ch[0] = new Seg(l, m);
                ch[0]->add(p, v);
            } else {
                if (!ch[1]) ch[1] = new Seg(m, r);
                ch[1]->add(p, v);
            }
            pull();
        }
    }
    lli query(int a, int b) {
        if (a <= l && r <= b) return sum;
        lli ans = 0;
        if (a < m && ch[0]) ans += ch[0]->query(a, b);
        if (m < b && ch[1]) ans += ch[1]->query(a, b);
        return ans;
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b, c, d;
    cin >> n;
    lli ans = 0;
    vector <pair <pii, pii>> v;
    vector <pair <int, pii>> row;
    vector <pair <int, pii>> col;
    fop (i,0,n) {
        cin >> a >> b >> c >> d;
        if (a == c) {
            if (b > d) swap(b, d);
            row.pb({a, {b, d + 1}});
        } else {
            if (a > c) swap(a, c);
            col.pb({b, {a, c + 1}});
        }
    }
    auto run = [&](vector <pair <int, pii>> a, bool is) {
        lli ans = 0;
        sort(all(a));
        for (int i = 0, j = 0; i < a.size(); i = j) {
            while (j < a.size() && a[i].X == a[j].X) j++;
            vector <pii> vv;
            fop (k,i,j) {
                if (vv.empty() || vv.back().Y < a[k].Y.X) vv.pb({a[k].Y.X, a[k].Y.Y});
                else vv.back().Y = max(vv.back().Y, a[k].Y.Y);
            }
            for (pii A : vv) {
                ans += A.Y - A.X;
                if (is) {
                    v.pb({{A.X, -1}, {a[i].X, 1}});
                    v.pb({{A.Y, -1}, {a[i].X, -1}});
                } else {
                    v.pb({{a[i].X, 1}, {A.X, A.Y}});
                }
            }
        }
        return ans;
    };
    ans += run(row, true);
    ans += run(col, false);
    Seg root(-N, N);
    sort(all(v));
    for (auto A : v) {
        if (A.X.Y == -1) {
            root.add(A.Y.X, A.Y.Y);
        } else {
            ans -= root.query(A.Y.X, A.Y.Y);
        }
    }
    cout << ans << endl;
}
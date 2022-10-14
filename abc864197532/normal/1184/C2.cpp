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
const int mod = 1e9 + 7, x = 864197532, N = 300087, logN = 18, K = 500, C = 1 << 20;

template <typename T>
struct Seg {
    int l, r, m;
    T sum, addTag;
    Seg* ch[2];
    Seg (int l, int r): l(l), r(r), m(l + r >> 1) {
        sum = 0, addTag = 0;
        ch[0] = ch[1] = NULL;
    }
    int size() {return r - l;}
    void pull() {sum = max((ch[0] ? ch[0]->sum : 0), (ch[1] ? ch[1]->sum : 0));}
    void addValue(T v) {sum += v;};
    void push() {
        if (addTag) {
            if (r - l != 1) {
                if (!ch[0]) ch[0] = new Seg(l, m);
                ch[0]->addValue(addTag);
                ch[0]->addTag += addTag;
                if (!ch[1]) ch[1] = new Seg(m, r);
                ch[1]->addValue(addTag);
                ch[1]->addTag += addTag;
            }
            addTag = 0;
        }
    }
    void set(int p, T v) {
        if (r - l == 1) {
            sum = v;
        } else {
            push();
            if (p < m) {
                ch[0]->set(p,v);
            } else {
                ch[1]->set(p,v);
            }
            pull();
        }
    }
    void add(int a, int b, T v) {
        if (a >= b) return;
        if (a <= l and r <= b) {
            addValue(v);
            addTag += v;
        } else {
            push();
            if (a < m) {
                if (!ch[0]) ch[0] = new Seg(l, m);
                ch[0]->add(a,b,v);
            }
            if (m < b) {
                if (!ch[1]) ch[1] = new Seg(m, r);
                ch[1]->add(a,b,v);
            }
            pull();
        }
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, r, x, y;
    cin >> n >> r;
    r *= 2;
    vector <pii> p(n);
    Seg <lli> root(-1 << 21, 1 << 21);
    fop (i,0,n) {
        cin >> x >> y;
        p[i] = {x - y, x + y};
    }
    sort(all(p));
    lli ans = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j < i && p[j].X + r < p[i].X) {
            root.add(p[j].Y - r, p[j].Y + 1, -1);
            j++;
        }
        root.add(p[i].Y - r, p[i].Y + 1, 1);
        ans = max(ans, root.sum);
    }
    cout << ans << endl;
}
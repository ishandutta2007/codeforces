#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 998244353, abc = 864197532, N = 100087, logN = 17, K = 333;

vector <lli> v;

struct Seg {
    int l, r, m, val, lz1, lz2;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), val(0), lz1(-1), lz2(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    void pull() {val = ch[0]->val + ch[1]->val;}
    void push() {
        if (r - l > 1 && ~lz1) {
            ch[0]->lz1 = lz1;
            ch[1]->lz1 = lz1;
            ch[0]->lz2 = 0;
            ch[1]->lz2 = 0;
            ch[0]->val = lz1 * (m - l);
            ch[1]->val = lz1 * (r - m);
            lz1 = -1;
        }
        if (r - l > 1 && lz2) {
            ch[0]->lz2 ^= lz2;
            ch[1]->lz2 ^= lz2;
            ch[0]->val = m - l - ch[0]->val;
            ch[1]->val = r - m - ch[1]->val;
            lz2 = 0;
        }
    }
    void add(int a, int b, int v) {
        if (a <= l && r <= b) {
            if (v == 2) lz2 ^= 1, val = r - l - val;
            else lz1 = v, lz2 = 0, val = lz1 * (r - l);
        } else {
            push();
            if (a < m) ch[0]->add(a, b, v);
            if (m < b) ch[1]->add(a, b, v);
            pull();
        }
    }
    int query() {
        if (r - l == 1) return l;
        push();
        if (ch[0]->val == m - l) return ch[1]->query();
        return ch[0]->query();
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    vector <pair <int, pll>> Q(q);
    v.pb(1);
    for (int i = 0; i < q; ++i) cin >> Q[i], Q[i].Y.Y++, v.pb(Q[i].Y.X), v.pb(Q[i].Y.Y);
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    Seg root(0, v.size());
    for (int i = 0; i < q; ++i) {
        Q[i].Y.X = lower_bound(all(v), Q[i].Y.X) - v.begin();
        Q[i].Y.Y = lower_bound(all(v), Q[i].Y.Y) - v.begin();
        if (Q[i].X <= 2) Q[i].X = 3 - Q[i].X;
        root.add(Q[i].Y.X, Q[i].Y.Y, Q[i].X - 1);
        cout << v[root.query()] << endl;
    }
}
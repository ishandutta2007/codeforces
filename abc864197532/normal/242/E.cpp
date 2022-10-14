#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
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
const int mod = 998244353, abc = 864197532, N = 200005, K = 111;

struct Seg {
    int l, r, m, lz, sz;
    vector <int> val;
    Seg* ch[2];
    Seg (int _l, int _r, vector <int> &a) : l(_l), r(_r), m(l + r >> 1), lz(0), sz(r - l) {
        val.resize(20);
        if (r - l > 1) {
            ch[0] = new Seg(l, m, a);
            ch[1] = new Seg(m, r, a);
            pull();
        } else {
            for (int i = 0; i < 20; ++i) val[i] = a[l] >> i & 1;
        }
    }
    void pull() {
        for (int i = 0; i < 20; ++i) val[i] = ch[0]->val[i] + ch[1]->val[i];
    }
    lli toSum() {
        lli ans = 0;
        for (int i = 0; i < 20; ++i) ans += (1ll << i) * val[i];
        return ans;
    }
    void give(int t) {
        for (int i = 0; i < 20; ++i) if (t >> i & 1) {
            val[i] = sz - val[i];
        }
        lz ^= t;
    }
    void push() {
        ch[0]->give(lz), ch[1]->give(lz);
        lz = 0;
    }
    void add(int a, int b, int v) {
        if (a <= l && r <= b) give(v);
        else {
            push();
            if (a < m) ch[0]->add(a, b, v);
            if (m < b) ch[1]->add(a, b, v);
            pull();
        }
    }
    lli query(int a, int b) {
        if (a <= l && r <= b) return toSum();
        lli ans = 0;
        push();
        if (a < m) ans += ch[0]->query(a, b);
        if (m < b) ans += ch[1]->query(a, b);
        return ans;
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    Seg root(0, n, a);
    cin >> q;
    while (q--) {
        int t, l, r, x;
        cin >> t >> l >> r, --l;
        if (t == 1) {
            cout << root.query(l, r) << endl;
        } else {
            cin >> x;
            root.add(l, r, x);
        }
    }
}
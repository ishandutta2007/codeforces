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
const int mod = 1e9 + 7, abc = 864197532, N = 2000, logN = 20, K = 333;

vector <int> p, inv;

struct Seg1 {
    int l, r, m;
    lli val, lz;
    Seg1* ch[2];
    Seg1 (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), val(0), lz(0) {
        if (r - l > 1) {
            ch[0] = new Seg1(l, m);
            ch[1] = new Seg1(m, r);
        }
    }
    void pull() {val = ch[0]->val | ch[1]->val;}
    void give(lli v) {
        val |= v;
        lz |= v;
    }
    void push() {
        if (!lz) return;
        ch[0]->give(lz), ch[1]->give(lz);
        lz = 0;
    }
    void add(int a, int b, lli v) {
        if (a <= l && r <= b) give(v);
        else {
            push();
            if (a < m) ch[0]->add(a, b, v);
            if (m < b) ch[1]->add(a, b, v);
            pull();
        }
    }
    lli query(int a, int b) {
        if (a <= l && r <= b) return val;
        lli ans = 0;
        push();
        if (a < m) ans |= ch[0]->query(a, b);
        if (m < b) ans |= ch[1]->query(a, b);
        return ans;
    }
};

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

struct Seg2 {
    int l, r, m;
    lli val, lz;
    Seg2* ch[2];
    Seg2(int _l, int _r, vector <int> &a) : l(_l), r(_r), m(l + r >> 1), val(1), lz(1) {
        if (r - l > 1) {
            ch[0] = new Seg2(l, m, a);
            ch[1] = new Seg2(m, r, a);
            pull();
        } else {
            val = a[l];
        }
    }
    void pull() {val = ch[0]->val * ch[1]->val % mod;}
    void give(lli t) {
        lz = lz * t % mod;
        val = val * modpow(t, r - l) % mod;
    }
    void push() {
        if (lz == 1) return;
        ch[0]->give(lz), ch[1]->give(lz);
        lz = 1;
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
        if (a <= l && r <= b) return val;
        push();
        lli ans = 1;
        if (a < m) ans = ch[0]->query(a, b);
        if (m < b) ans = ans * ch[1]->query(a, b) % mod;
        return ans;
    }
};


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 2; i <= 300; ++i) {
        bool is = false;
        for (int j : p) is |= i % j == 0;
        if (!is) p.pb(i), inv.pb(modpow(i, mod - 2));
    }
    int m = p.size();
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    Seg1 rootp(0, n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        lli v = 0;
        for (int j = 0; j < m; ++j) {
            if (a[i] % p[j] == 0) {
                v |= 1ll << j;
            }
        }
        rootp.add(i, i + 1, v);
    }
    Seg2 rootmul(0, n, a);
    string s;
    int l, r, x;
    while (q--) {
        cin >> s >> l >> r, l--;
        if (s[0] == 'T') {
            lli mul = rootmul.query(l, r);
            lli val = rootp.query(l, r);
            for (int j = 0; j < m; ++j) if (val >> j & 1) {
                mul -= (mul * inv[j] % mod);
                if (mul < 0) mul += mod;
            }
            cout << mul << '\n';
        } else {
            cin >> x;
            lli v = 0;
            for (int j = 0; j < m; ++j) {
                if (x % p[j] == 0) {
                    v |= 1ll << j;
                }
            }
            rootp.add(l, r, v);
            rootmul.add(l, r, x);
        }
    }
}
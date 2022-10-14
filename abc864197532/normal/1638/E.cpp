#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 1e6 + 87, logN = 20, K = 111, M = N * 20;

lli ad[N];

struct Seg {
    int l, r, m, mn, mx, lz1;
    lli val, lz2;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), mn(1), mx(1), lz1(-1), lz2(0), val(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    void give(int v, lli x) {
        lz2 += x, val += x;
        if (v != -1)
            mn = mx = lz1 = v;
    }
    void push() {
        ch[0]->give(lz1, lz2), ch[1]->give(lz1, lz2);
        lz1 = -1, lz2 = 0;
    }
    void pull() {
        mn = min(ch[0]->mn, ch[1]->mn);
        mx = max(ch[0]->mx, ch[1]->mx);
    }
    void add(int a, int b, int v) {
        if (a <= l && r <= b && mn == mx) {
            give(v, ad[mn] - ad[v]);
        } else {
            push();
            if (a < m)
                ch[0]->add(a, b, v);
            if (m < b)
                ch[1]->add(a, b, v);
            pull();
        }
    }
    lli query(int p) {
        if (r - l == 1)
            return val + ad[mn];
        push();
        return ch[p >= m]->query(p);
    }
};

int main () {
    owo;
    int n, q;
    cin >> n >> q;
    Seg root(0, n);
    while (q--) {
        string s;
        cin >> s;
        if (s == "Color") {
            int l, r, c;
            cin >> l >> r >> c, --l;
            root.add(l, r, c);
        } else if (s == "Add") {
            int c, x;
            cin >> c >> x;
            ad[c] += x;
        } else {
            int p; cin >> p, p--;
            cout << root.query(p) << '\n';
        }
    }
}
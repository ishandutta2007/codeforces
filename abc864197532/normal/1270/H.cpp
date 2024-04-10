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
const int mod = 998244353, N = 1e6 + 5, logN = 20, K = 111, C = 7;

struct Seg {
    int l, r, m, mn, cnt, lz, val;
    bool active;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), lz(0), active(false), val(0), mn(1 << 30), cnt(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    void pull() {
        if (ch[0]->mn > ch[1]->mn)
            mn = ch[1]->mn, cnt = ch[1]->cnt;
        else if (ch[0]->mn < ch[1]->mn)
            mn = ch[0]->mn, cnt = ch[0]->cnt;
        else
            mn = ch[0]->mn, cnt = ch[0]->cnt + ch[1]->cnt;
    }
    void give(int v) {
        lz += v, val += v, mn += v;
    }
    void push() {
        ch[0]->give(lz), ch[1]->give(lz), lz = 0;
    }
    void update(int p, bool chg) {
        if (r - l == 1) {
            active = chg;
            if (active)
                mn = val, cnt = 1;
            else
                mn = 1 << 30, cnt = 0;
        } else {
            push();
            ch[p >= m]->update(p, chg);
            pull();
        }
    }
    void add(int a, int b, int v) {
        if (a <= l && r <= b)
            give(v);
        else {
            push();
            if (a < m)
                ch[0]->add(a, b, v);
            if (m < b)
                ch[1]->add(a, b, v);
            pull();
        }
    }
};

int main () {
    owo;
    int n, q;
    cin >> n >> q;
    vector <int> a(n + 2);
    a[0] = N, a[n + 1] = 0;
    for (int i = 1; i <= n; ++i) 
        cin >> a[i];
    Seg root(0, N);
    auto upd = [&](int i, int v) {
        int l = a[i], r = a[i + 1];
        if (l > r)
            swap(l, r);
        root.add(l, r, v);
    };
    for (int i = 0; i <= n; ++i) {
        upd(i, 1);
    }
    for (int i = 1; i <= n; ++i)
        root.update(a[i], true);
    while (q--) {
        int p, v; cin >> p >> v;
        upd(p - 1, -1), upd(p, -1), root.update(a[p], false);
        a[p] = v;
        upd(p - 1, 1), upd(p, 1), root.update(a[p], true);
        cout << root.cnt << '\n';
    }
}
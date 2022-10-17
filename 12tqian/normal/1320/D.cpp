#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#ifdef LOCAL
#define dbg(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define dbg(...) 17;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) { bool f = true; os << "{"; for (const auto &x : c) { if (!f) os << ", "; f = false; os << x; } return os << "}"; }
template<typename T> void debug(string s, T x) { cerr << s << " = " << x << "\n"; }
template<typename T, typename... Args> void debug(string s, T x, Args... args) { cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...); }
const int MOD = 1e9 + 7;
typedef decay<decltype(MOD)>::type T;
struct mi {
    T val;
    explicit operator T() const { return val; }
    mi() { val = 0; }
    mi(const long long& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD; }
    friend ostream& operator<<(ostream& os, const mi& a) { return os << a.val; }
    friend bool operator==(const mi& a, const mi& b) { return a.val == b.val; }
    friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
    friend bool operator<(const mi& a, const mi& b) { return a.val < b.val; }
    mi operator-() const { return mi(-val); }
    mi& operator+=(const mi& m) {
        if ((val += m.val) >= MOD) val -= MOD;
        return *this; }
    mi& operator-=(const mi& m) {
        if ((val -= m.val) < 0) val += MOD;
        return *this; }
    mi& operator*=(const mi& m) { val = (long long) val * m.val % MOD;
        return *this; }
    friend mi pow(mi a, long long p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
        return ans; }
    friend mi inv(const mi& a) { assert(a != 0); return pow(a, MOD - 2); }
    mi& operator/=(const mi& m) { return (*this) *= inv(m); }
    friend mi operator+(mi a, const mi& b) { return a += b; }
    friend mi operator-(mi a, const mi& b) { return a -= b; }
    friend mi operator*(mi a, const mi& b) { return a *= b; }
    friend mi operator/(mi a, const mi& b) { return a /= b; }
};
const int SZ = (1 << 18);
vector<mi> po;
struct Node {
    int l, r, lsz, rsz, lval, rval;
    int tot = -1;
    mi hsh;
    Node() {
        l = r = lsz = rsz = lval = rval = 0;
        tot = -1;
        hsh = 0;
    }
    Node(int idx, int val) {
        l = r = idx;
        lsz = rsz = 1;
        lval = rval = val;
        hsh = val;
        tot = 0;
    }
    mi get() {
        return hsh + po[tot] - 1;
    }
} node[2 * SZ], ID;
Node comb(Node a, Node b) {
    if (a.tot == -1) {
        return b;
    } else if (b.tot == -1) {
        return a;
    }
    Node res;
    res.l = a.l;
    res.r = b.r;
    res.lval = a.lval;
    res.rval = b.rval;
    if (a.rval != b.lval) {
        res.lsz = a.lsz;
        res.rsz = b.rsz;
        res.hsh = a.hsh * po[b.tot] + b.hsh * po[a.r - a.l + 1];
        res.tot = a.tot + b.tot;
        return res;
    } 
    if (a.rsz == a.r - a.l + 1 && b.lsz == b.r - b.l + 1) {
        int len = res.r - res.l + 1;
        res.lsz = len;
        res.rsz = len;
        if (res.lval == 0) {
            res.tot = 0;
            return res;
        } else {
            res.tot = len / 2 * 2;
            if (len % 2 == 1) {
                res.hsh = po[len - 1];
            }
            return res;
        }
    } else if (a.rsz == a.r - a.l + 1) {
        res.lsz = a.rsz + b.lsz;
        res.rsz = b.rsz;
    } else if (b.lsz == b.r - b.l + 1) {
        res.lsz = a.lsz;
        res.rsz = a.rsz + b.lsz;
    } else {
        res.lsz = a.lsz;
        res.rsz = b.rsz;
    }
    if (a.rval == 0) {
        res.hsh = a.hsh * po[b.tot] + b.hsh * po[a.r - a.l + 1];
        res.tot = a.tot + b.tot;
        return res;             
    } 
    if (a.rsz % 2 == 0 && b.lsz % 2 == 0) {
        res.hsh = a.hsh * po[b.tot] + b.hsh * po[a.r - a.l + 1];
        res.tot = a.tot + b.tot;
        return res; 
    } else if (a.rsz % 2 == 1 && b.lsz % 2 == 1) {
        res.hsh = (a.hsh - po[a.r - a.l]) * po[b.tot + 2] + (b.hsh - po[b.tot]) * po[a.r - a.l + 1];
        res.tot = a.tot + b.tot + 2;
        return res;
    } else if (a.rsz % 2 == 1) {
        res.hsh = a.hsh * po[b.tot] + b.hsh * po[a.r - a.l + 1];
        res.tot = a.tot + b.tot;
        return res; 
    } else {
        res.hsh = a.hsh * po[b.tot] + (b.hsh - po[b.tot]) * po[a.r - a.l + 1];
        res.hsh += po[a.r - a.l + 1 + b.tot];
        res.tot = a.tot + b.tot;
        return res;
    }
}
void pull(int ind) {
    node[ind] = comb(node[2 * ind], node[2 * ind + 1]);
}
void build() {
    for (int i = SZ - 1; i >= 1; i--) {
        pull(i);
    }
}
Node query(int lo, int hi, int ind = 1, int L = 0, int R = SZ - 1) {
    if (lo > R || L > hi) return ID;
    if (lo <= L && R <= hi) {
        return node[ind];
    }
    int M = (L + R) / 2;
    return comb(query(lo, hi, 2 * ind, L, M), query(lo, hi, 2 * ind + 1, M + 1, R));
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string t;
    cin >> t;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        s[i] = t[i] - '0';
    }
    po.resize(2 * SZ + 5);
    po[0] = 1;
    ID.tot = -1;
    for (int i = 1; i < 2 * SZ + 5; i++) {
        po[i] = po[i - 1] * 2;
    }
    for (int i = 0; i < n; i++) {
        node[i + SZ] = Node(i, t[i] - '0');
    }
    for (int i = n; i < SZ; i++) {
        node[i + SZ] = Node(i, 0);
    }
    build();
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l1, l2, len;
        cin >> l1 >> l2 >> len;
        l1--, l2--;
        int r1 = l1 + len - 1;
        int r2 = l2 + len - 1;
        Node one = query(l1, r1);
        Node two = query(l2, r2);
        if (one.get() == two.get()) {
            cout << "Yes\n" ;
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
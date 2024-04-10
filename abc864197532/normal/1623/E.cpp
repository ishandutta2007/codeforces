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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 101, logN = 18, B = 1 << 8, M = 1 << 21;

template <typename T>
struct Seg {
    // range add value, range query sum
    // 0-indexed, [l, r)
    int l, r, m;
    T val;
    long long lz;
    Seg *ch[2];
    Seg () = default;
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), val(0), lz(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    Seg (int _l, int _r, vector <T> &a) : l(_l), r(_r), m(l + r >> 1), lz(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m, a);
            ch[1] = new Seg(m, r, a);
            pull();
        } else {
            val = a[l];
        }
    }
    void pull() {
        val = ch[0]->val + ch[1]->val;
    }
    void give(long long x) {
        lz += x, val += x * (r - l);
    }
    void push() {
        ch[0]->give(lz), ch[1]->give(lz), lz = 0;
    }
    void set(int p, T v) {
        if (r - l == 1) {
            val = v;
        } else {
            ch[p >= m]->set(p, v), pull();
        }
    }
    void add(int a, int b, long long v) {
        if (a <= l && r <= b) {
            give(v);
        } else {
            push();
            if (a < m)
                ch[0]->add(a, b, v);
            if (m < b)
                ch[1]->add(a, b, v);
            pull();
        }
    }
    T query(int a, int b) {
        if (a <= l && r <= b)
            return val;
        push();
        T ans = 0;
        if (a < m)
            ans = ans + ch[0]->query(a, b);
        if (m < b)
            ans = ans + ch[1]->query(a, b);
        return ans;
    }
};

int main () {
    owo;
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector <int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i], --l[i], --r[i];
    }
    vector <int> in(n), out(n), par(n), ord(n), dep(n);
    int _t = 0, _t2 = 0;
    vector <int> rev;
    function <void(int)> dfs = [&](int v) {
        in[v] = _t++;
        if (l[v] != -1)
            par[l[v]] = v, dep[l[v]] = dep[v] + 1, dfs(l[v]);
        ord[v] = _t2++, rev.pb(v);
        if (r[v] != -1)
            par[r[v]] = v, dep[r[v]] = dep[v] + 1, dfs(r[v]);
        out[v] = _t++;
    };
    dfs(0);
    stack <int> stk;
    vector <bool> ok(n, false);
    for (int i = 0, j = 0; i < n; i = j) {
        while (j < n && s[rev[i]] == s[rev[j]])
            j++;
        if (j != n) {
            if (s[rev[i]] < s[rev[j]]) {
                for (int k = i; k < j; ++k)
                    ok[rev[k]] = true;
            }
        }
    }
    Seg <lli> root(0, n * 2);
    vector <bool> ans(n, false);
    for (int i = 0; i < n; ++i) {
        int v = rev[i];
        if (ans[v])
            continue;
        if (ok[v]) {
            lli x = root.query(in[v], in[v] + 1);
            lli need = dep[v] + 1 - x;
            if (k >= need) {
                k -= need;
                int now = v;
                while (!ans[now]) {
                    ans[now] = true;
                    root.add(in[now], out[now] + 1, 1);
                    now = par[now];
                }
            }
        } else {
            root.add(in[v], out[v] + 1, -n);
        }
    }
    for (int v : rev) {
        if (ans[v])
            cout << s[v] << s[v];
        else
            cout << s[v];
    }
    cout << endl;
}
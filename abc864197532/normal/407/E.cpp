
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
const int mod = 998244353, N = 1005, logN = 20, M = 6e6;

struct Seg {
    int l, r, m;
    lli val, lz; // mx - mn - r + l <= k => (mx - mn - r) <= k - l
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), val(0), lz(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
            pull();
        } else {
            val = -l;
        }
    }
    void pull() {
        val = min(ch[0]->val, ch[1]->val);
    }
    void push() {
        ch[0]->give(lz), ch[1]->give(lz), lz = 0;
    }
    void give(lli x) {
        val += x, lz += x;
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
    int query(int a, int b, int x) {
        if (r - l == 1)
            return (val <= x ? l : -1);
        push();
        if (a <= l && r <= b) {
            if (ch[1]->val <= x)
                return ch[1]->query(a, b, x);
            if (ch[0]->val <= x)
                return ch[0]->query(a, b, x);
            return -1;
        } else {
            if (m < b) {
                int res = ch[1]->query(a, b, x);
                if (res != -1)
                    return res;
            }
            if (a < m) {
                int res = ch[0]->query(a, b, x);
                if (res != -1)
                    return res;
            }
            return -1;
        }
    }
};

int main () {
    owo;
    int n, k, d;
    cin >> n >> k >> d;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i], a[i] += 1000000000;
    if (d == 0) {
        pii ans = mp(0, 0);
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && a[i] == a[j])
                j++;
            if (ans.Y - ans.X < j - i)
                ans = mp(i, j);
        }
        cout << ans.X + 1 << ' ' << ans.Y << endl;
        return 0;
    }
    vector <int> r(n, n);
    for (int i = 0, j = 0; i < n; i = j) {
        while (j < n && a[i] % d == a[j] % d)
            j++;
        for (int k = i; k < j; ++k)
            r[k] = j;
    }
    for (int &i : a)
        i /= d;
    set <int> S;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j < n && !S.count(a[j]))
            S.insert(a[j++]);
        if (j < r[i])
            r[i] = j;
        S.erase(a[i]);
    }
    Seg root(0, n);
    vector <array <int, 3>> stk_mx, stk_mn; // [l, r), val
    pii ans = mp(0, 0);
    auto upd = [&](int l, int r) {
        if (ans.Y - ans.X <= r - l)
            ans = mp(l, r);
    };
    for (int l = n - 1; ~l; --l) {
        // update mx
        while (!stk_mx.empty() && a[l] >= stk_mx.back()[2]) {
            int L = stk_mx.back()[0], R = stk_mx.back()[1], val = stk_mx.back()[2];
            root.add(L, R, a[l] - val), stk_mx.pop_back();
        }
        stk_mx.pb({l, stk_mx.empty() ? n : stk_mx.back()[0], a[l]});
        // update mn
        while (!stk_mn.empty() && a[l] <= stk_mn.back()[2]) {
            int L = stk_mn.back()[0], R = stk_mn.back()[1], val = stk_mn.back()[2];
            root.add(L, R, val - a[l]), stk_mn.pop_back();
        }
        stk_mn.pb({l, stk_mn.empty() ? n : stk_mn.back()[0], a[l]});
        // query
        int p = root.query(l, r[l], k - l);
        if (p == -1) 
            continue;
        // [l, p]
        upd(l, p);
    }
    cout << ans.X + 1 << ' ' << ans.Y + 1 << endl;
}
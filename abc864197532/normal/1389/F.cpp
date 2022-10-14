/*
 *   ##   #####   ####      ####  #    #  ####
 *  #  #  #    # #    #    #    # #    # #    #
 * #    # #####  #         #    # #    # #    #
 * ###### #    # #         #    # # ## # #    #
 * #    # #    # #    #    #    # ##  ## #    #
 * #    # #####   ####      ####  #    #  ####
 */
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
#define info() cout << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
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
template <typename T> struct vvvv : vector <vvv <T>> {
    vvvv(int n, int m, int k, int t, T v) : vector <vvv <T>> (n, vvv <T>(m, k, t, v)) {}
    vvvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1000001, logN = 20, K = 111;

struct seg {
    int l, r, t;
    bool operator < (const seg &o) {
        if (r != o.r)
            return r < o.r;
        if (l != o.l)
            return l < o.l;
        return t < o.t;
    }
};

struct Seg {
    int l, r, m, lz, val;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), lz(0), val(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    void pull() {
        val = max(ch[0]->val, ch[1]->val);
    }
    void give(int v) {
        lz += v, val += v;
    }
    void push() {
        ch[0]->give(lz), ch[1]->give(lz);
        lz = 0;
    }
    void add(int a, int b, int v) {
        if (a >= b)
            return;
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
    void upd(int p, int v) {
        if (r - l == 1) {
            val = max(val, v);
        } else {
            ch[p >= m]->upd(p, v);
            pull();
        }
    }
    int query(int a, int b) {
        if (a >= b)
            return 0;
        if (a <= l && r <= b)
            return val;
        push();
        int ans = 0;
        if (a < m)
            ans = max(ans, ch[0]->query(a, b));
        if (m < b)
            ans = max(ans, ch[1]->query(a, b));
        return ans;
    }
};

int main () {
    owo;
    int n;
    cin >> n;
    vector <seg> a(n);
    vector <int> v;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].l >> a[i].r >> a[i].t, --a[i].t, --a[i].l;
        v.pb(a[i].l), v.pb(a[i].r);
    }
    sort(all(v)), v.resize(unique(all(v)) - v.begin());
    for (int i = 0; i < n; ++i) {
        a[i].l = lower_bound(all(v), a[i].l) - v.begin() + 1;
        a[i].r = lower_bound(all(v), a[i].r) - v.begin() + 1;
    }
    sort(all(a));
    Seg *root[2];
    for (int t : {0, 1})
        root[t] = new Seg(0, v.size() + 1);
    vector <int> dp(n, 0);
    vector <int> cnt(2, 0);
    for (int i = 0; i < n; ++i) {
        cnt[a[i].t]++, dp[i] = cnt[a[i].t];
        dp[i] = max(dp[i], root[a[i].t ^ 1]->query(0, a[i].l) + 1);
        root[a[i].t ^ 1]->add(0, a[i].l, 1);
        root[a[i].t]->upd(a[i].r - 1, dp[i]);
    }
    cout << *max_element(all(dp)) << endl;
}
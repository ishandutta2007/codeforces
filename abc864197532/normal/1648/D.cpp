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
const int mod = 998244353, N = 200087, logN = 20, K = 111, C = 7;

struct Seg {
    int l, r, m;
    lli mx;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), mx(-1ll << 60) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
            pull();
        }
    }
    void pull() {mx = max(ch[0]->mx, ch[1]->mx);}
    void modify(int p, lli v) {
        if (r - l == 1)
            mx = max(mx, v);
        else
            ch[p >= m]->modify(p, v), pull();
    }
    lli query(int a, int b) {
        if (a <= l && r <= b)
            return mx;
        lli ans = -1ll << 60;
        if (a < m)
            ans = max(ans, ch[0]->query(a, b));
        if (m < b)
            ans = max(ans, ch[1]->query(a, b));
        return ans;
    }
};

struct Seg2 {
    struct node {
        lli a, b, ab;
        node() : a(-1ll << 60), b(-1ll << 60), ab(-1ll << 60) {}
        node operator + (const node &o) {
            node res;
            res.a = max(a, o.a);
            res.b = max(b, o.b);
            res.ab = max({ab, o.ab, a + o.b});
            return res;
        }
    };
    int l, r, m;
    node res;
    Seg2* ch[2];
    Seg2 (int _l, int _r) : l(_l), r(_r), m(l + r >> 1) {
        if (r - l > 1) {
            ch[0] = new Seg2(l, m);
            ch[1] = new Seg2(m, r);
            pull();
        }
    }
    void pull() {
        res = ch[0]->res + ch[1]->res;
    }
    void modify(int p, lli A, lli B) {
        if (r - l == 1)
            res.a = max(res.a, A), res.b = max(res.b, B);
        else
            ch[p >= m]->modify(p, A, B), pull();
    }
    node query(int a, int b) {
        if (a <= l && r <= b)
            return res;
        node res;
        if (a < m)
            res = res + ch[0]->query(a, b);
        if (m < b)
            res = res + ch[1]->query(a, b);
        return res;
    }
};


int main () {
    owo;
    /*
     f(l, r) = pre0[l] - 0 + pre2[n] - pre2[r] + cost(l, r) + pre1[r] - pre1[l]
     f(l, r) = pre[l] + pre2[r] - cost(l, r)
     */

    /*
     dp[l] = 0, dp[i]
     */
    int n, m;
    cin >> n >> m;
    vector <lli> pre0(n + 1), pre1(n + 1), pre2(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> pre0[i], pre0[i] += pre0[i - 1];
    for (int i = 1; i <= n; ++i)
        cin >> b[i], pre1[i] = pre1[i - 1] + b[i];
    for (int i = 1; i <= n; ++i)
        cin >> pre2[i], pre2[i] += pre2[i - 1];
    vector <vector <pair <int, lli>>> seg(n + 1);
    for (int i = 0, l, r, v; i < m; ++i) {
        cin >> l >> r >> v, --l;
        seg[r].eb(l, v);
    }
    vv <lli> dp(n + 1, 2, -1ll << 60);
    dp[0][0] = 0;
    for (int i = 1; i < n; ++i)
        dp[i][0] = pre0[i + 1] - pre0[1] - pre1[i];
    Seg root(0, n + 1);
    for (int i = 0; i < n; ++i)
        root.modify(i, dp[i][0]);
    for (int i = 1; i <= n; ++i) {
        for (auto [l, v] : seg[i]) {
            dp[i][1] = max(dp[i][1], root.query(l, i) - v);   
        }
        root.modify(i, dp[i][1]);
    }
    Seg2 root2(0, n + 1);
    for (int i = 0; i <= n; ++i) {
        root2.modify(i, max(dp[i][0], dp[i][1]), pre2[n] - pre2[i - 1] + pre1[i]);
    }
    lli ans = -1ll << 60;
    for (int i = 1; i <= n; ++i) {
        for (auto [l, v] : seg[i]) {
            ans = max(ans, root2.query(l, i + 1).ab - v);
        }
    }
    cout << ans + pre0[1] << endl;
}
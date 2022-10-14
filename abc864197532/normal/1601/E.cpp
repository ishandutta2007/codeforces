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
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1 << 18, logN = 19, K = 1 << 9, G = 3;

struct Seg {
    int l, r, m, mn, mx, lz;
    lli val;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), mn(1 << 30), val(1 << 30), mx(0), lz(-1) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
            pull();
        }
    }
    void pull() {
        mn = min(ch[0]->mn, ch[1]->mn);
        mx = max(ch[0]->mx, ch[1]->mx);
        val = ch[0]->val + ch[1]->val;
    }
    void give(int v) {
        lz = v, mn = mx = v, val = 1ll * v * (r - l);
    }
    void push() {
        if (lz == -1)
            return;
        ch[0]->give(lz), ch[1]->give(lz);
        lz = -1;
    }
    void add(int p, int v) {
        if (v >= mx)
            return;
        if (r <= p && mn > v) {
            give(v);
        } else if (r - l > 1) {
            push();
            ch[0]->add(p, v);
            if (m < p)
                ch[1]->add(p, v);
            pull();
        }
    }
    void set(int p, int v) {
        if (r - l == 1)
            val = mn = mx = v;
        else
            push(), ch[p >= m]->set(p, v), pull();
    }
    lli query(int a, int b) {
        if (a <= l && r <= b)
            return val;
        push();
        lli ans = 0;
        if (a < m)
            ans += ch[0]->query(a, b);
        if (m < b)
            ans += ch[1]->query(a, b);
        return ans;
    }
};

int main () {
    owo;
    int n, q, k;
    cin >> n >> q >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector <int> mn(n - k + 1);
    deque <int> dq;
    for (int i = 0; i < k; ++i) {
        while (!dq.empty() && a[dq.back()] >= a[i])
            dq.pop_back();
        dq.push_back(i);
    } 
    mn[0] = a[dq.front()];
    for (int i = k; i < n; ++i) {
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while (!dq.empty() && a[dq.back()] >= a[i])
            dq.pop_back();
        dq.push_back(i);
        mn[i - k + 1] = a[dq.front()];
    }
    vector <vector <pii>> Q(n + 1);
    for (int i = 0, l, r; i < q; ++i) {
        cin >> l >> r, --l;
        Q[l].eb(r, i);
    }
    int bound = (n + k - 1) / k;
    vector <Seg*> roots(k);
    vector <int> cur(k, 0);
    for (auto &i : roots) {
        i = new Seg(0, bound);
    }
    vector <lli> ans(q, 0);
    for (int l = n - 1; ~l; --l) {
        // add i
        int re = l % k;
        if (cur[re]) {
            roots[re]->add(cur[re], mn[l]);
        }
        roots[re]->set(cur[re]++, a[l]);
        for (auto [r, id] : Q[l]) {
            ans[id] = roots[re]->query(cur[re] - (r - l + k - 1) / k, cur[re]);
        }
    }
    for (lli i : ans)
        cout << i << '\n';
}
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
const int mod = 998244353, N = 1000001, logN = 20, K = 15;

struct BIT {
    lli bit[N];
    void init() {
        for (int i = 0; i < N; ++i)
            bit[i] = 0;
    }
    void add(int p, lli x) {
        for (int i = p; i < N; i += i & (-i))
            bit[i] += x;
    }
    lli query(int p) {
        lli ans = 0;
        for (int i = p; i > 0; i -= i & (-i))
            ans += bit[i];
        return ans;
    }
} bit1, bit2;

int main () {
    owo;
    int n, q;
    cin >> n >> q;
    vector <int> p(n), l(n), r(n), ql(q), qr(q);
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    for (int i = 0; i < q; ++i)
        cin >> ql[i], ql[i]--;
    for (int i = 0; i < q; ++i)
        cin >> qr[i];
    stack <int> stk;
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && p[stk.top()] <= p[i])
            stk.pop();
        l[i] = stk.empty() ? 0 : stk.top() + 1;
        stk.push(i);
    }
    while (!stk.empty())
        stk.pop();
    for (int i = n - 1; ~i; --i) {
        while (!stk.empty() && p[stk.top()] <= p[i])
            stk.pop();
        r[i] = stk.empty() ? n : stk.top();
        stk.push(i);
    }
    // min(r[i], qr) - max(l[i], ql);
    vector <lli> ans(q, 0);
    vector <int> ord(q), ord2(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) {
        if (qr[i] != qr[j])
            return qr[i] < qr[j];
        return i < j;
    });
    iota(all(ord2), 0);
    sort(all(ord2), [&](int i, int j) {
        if (r[i] != r[j])
            return r[i] < r[j];
        return i < j;
    });
    bit1.init(), bit2.init();
    for (int i = 0; i < n; ++i) {
        bit2.add(i + 1, 1);
    }
    int j = 0;
    for (int i : ord) {
        while (j < n && r[ord2[j]] < qr[i]) {
            bit1.add(ord2[j] + 1, r[ord2[j]]);
            bit2.add(ord2[j] + 1, -1);
            j++;
        }
        ans[i] += bit1.query(qr[i]) - bit1.query(ql[i]) + 1ll * (bit2.query(qr[i]) - bit2.query(ql[i])) * qr[i];
    }
    sort(all(ord), [&](int i, int j) {
        if (ql[i] != ql[j])
            return ql[i] < ql[j];
        return i < j;
    });
    sort(all(ord2), [&](int i, int j) {
        if (l[i] != l[j])
            return l[i] < l[j];
        return i < j;
    });
    bit1.init(), bit2.init();
    for (int i = 0; i < n; ++i) {
        bit1.add(i + 1, l[i]);
    }
    j = 0;
    for (int i : ord) {
        while (j < n && l[ord2[j]] < ql[i]) {
            bit1.add(ord2[j] + 1, -l[ord2[j]]);
            bit2.add(ord2[j] + 1, 1);
            j++;
        }
        ans[i] -= bit1.query(qr[i]) - bit1.query(ql[i]) + 1ll * (bit2.query(qr[i]) - bit2.query(ql[i])) * ql[i];
    }
    printv(all(ans));
}
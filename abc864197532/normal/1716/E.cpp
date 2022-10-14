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
    vv (int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv (int n, int m) : vector <vector <T>> (n, vector <T>(m)) {}
    vv () {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv (int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv (int n, int m, int k) : vector <vv <T>> (n, vv <T>(m, k)) {}
    vvv () {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1 << 18, logN = 18, G = 3;

struct state {
    lli pre, suf, sum, ans;
    state (lli x) {
        pre = max(x, 0ll);
        suf = pre;
        sum = x;
        ans = pre;
    }
    state operator + (const state &o) {
        state res(0);
        res.pre = max(pre, sum + o.pre);
        res.suf = max(suf + o.sum, o.suf);
        res.sum = sum + o.sum;
        res.ans = max({ans, o.ans, suf + o.pre});
        return res;
    }
};

int a[N];

vector <state> solve(int l, int r) {
    if (r - l == 1) {
        return {state(a[l])};
    }
    int m = l + r >> 1;
    vector <state> L = solve(l, m), R = solve(m, r);
    vector <state> ans;
    int high = __lg(r - l) - 1;
    for (int i = 0; i < r - l; ++i) {
        if (i >> high & 1) {
            ans.pb(R[i ^ (1 << high)] + L[i ^ (1 << high)]);
        } else {
            ans.pb(L[i] + R[i]);
        }
    }
    return ans;
}

int main () {
    owo;
    int n, q;
    cin >> n;
    for (int i = 0; i < 1 << n; ++i)
        cin >> a[i];
    vector <state> ans = solve(0, 1 << n);
    int x = 0;
    cin >> q;
    while (q--) {
        int k; cin >> k;
        x ^= 1 << k;
        cout << ans[x].ans << '\n';
    }
}
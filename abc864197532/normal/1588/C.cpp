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
const int mod = 998244353, N = 100001, logN = 20, K = 580;

void solve() {
    int n;
    cin >> n;
    vector <lli> a(n), r(n, n), pre1(n + 1, 0), pre2(n + 1, 0);
    // 1 -+-+ 2 +-+-
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pre1[i + 1] = pre1[i] + (i & 1 ? 1 : -1) * a[i];
        pre2[i + 1] = pre2[i] + (i & 1 ? -1 : 1) * a[i];
    }
    // a[i] > a[j] -> bad
    vector <pair <lli, int>> stk;
    for (int i = n - 1; ~i; --i) {
        int f = i & 1;
        if (!f) {
            while (!stk.empty() && stk.back().X >= pre1[i])
                stk.pop_back();
            stk.eb(pre1[i], i);
        }
        auto it = lower_bound(all(stk), mp(pre1[i], -1));
        if (it != stk.begin()) {
            --it;
            r[i] = min(r[i], 1ll * (it->Y));
        }
    }
    stk.clear();
    for (int i = n - 1; ~i; --i) {
        int f = i & 1;
        if (f) {
            while (!stk.empty() && stk.back().X >= pre2[i])
                stk.pop_back();
            stk.eb(pre2[i], i);
        }
        auto it = lower_bound(all(stk), mp(pre2[i], -1));
        if (it != stk.begin()) {
            --it;
            r[i] = min(r[i], 1ll * (it->Y));
        }
    }
    vector <lli> v = pre1;
    sort(all(v)), v.resize(unique(all(v)) - v.begin());
    vector <vector <int>> m1(v.size());
    for (int i = 0; i <= n; ++i) {
        pre1[i] = lower_bound(all(v), pre1[i]) - v.begin();
        m1[pre1[i]].pb(i);
    }
    lli ans = 0;
    for (int i = 0; i < n; ++i) {
        test(m1[pre1[i]], i, r[i]);
        ans += upper_bound(all(m1[pre1[i]]), r[i]) - upper_bound(all(m1[pre1[i]]), i);
    }
    cout << ans << endl;
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
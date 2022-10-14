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
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, int v = 0) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, int v = 0) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo
#else
#define test(args...)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1000001, logN = 20, K = 111;

int main () {
    owo;
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
    deque <int> cur[n];
    int ans = 0;
    vector <int> pre, dp;
    pre.assign(n + 1, 1 << 30);
    pre[0] = 0;
    int L = 0, R = 0;
    function<void(int, int, int, int)> solve = [&](int l, int r, int A, int B) {
        if (l >= r) return;
        int mid = l + r >> 1;
        int k = -1;
        for (int i = min(B, mid) - 1; i >= A; --i) {
            while (R < mid) {
                if (!cur[a[R]].empty()) ans += R - cur[a[R]].back();
                cur[a[R]].pb(R);
                R++;
            }
            while (L > i) {
                --L;
                if (!cur[a[L]].empty()) ans += cur[a[L]].front() - L;
                cur[a[L]].push_front(L);
            }
            while (R > mid) {
                --R;
                cur[a[R]].pop_back();
                if (!cur[a[R]].empty()) ans -= R - cur[a[R]].back();
            }
            while (L < i) {
                cur[a[L]].pop_front();
                if (!cur[a[L]].empty()) ans -= cur[a[L]].front() - L;
                L++;
            }
            if (dp[mid] > pre[i] + ans) {
                dp[mid] = pre[i] + ans;
                k = i;
            }
        }
        assert(k != -1);
        solve(l, mid, A, k + 1);
        solve(mid + 1, r, k, B);
    };
    for (int i = 0; i < k; ++i) {
        dp.assign(n + 1, 1 << 30);
        dp[0] = 0;
        solve(1, n + 1, 0, n + 1);
        swap(dp, pre);
    }
    cout << pre[n] << endl;
}
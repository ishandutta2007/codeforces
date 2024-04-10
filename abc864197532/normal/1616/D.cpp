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
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    if (a.empty())
        return o << "{}";
    bool is = false;
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
const int mod = 1e9 + 7, N = 5001, logN = 17, M = N * 40;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n;
        vector <int> a(n);
        vector <lli> pre = {0};
        for (int i = 0; i < n; ++i)
            cin >> a[i], pre.pb(pre.back() + a[i]);
        cin >> x;
        for (int i = 0; i <= n; ++i)
            pre[i] -= 1ll * x * i;
        vector <int> p(n + 1, 0);
        iota(all(p), 0);
        sort(all(p), [&](int i, int j) {
            if (pre[i] == pre[j])
                return i > j;
            return pre[i] > pre[j];
        });
        set <int> s;
        vector <int> pt(n + 1, 0);
        for (int i : p) {
            auto it = s.upper_bound(i - 2);
            if (it == s.begin())
                pt[i] = 0;
            else
                pt[i] = *prev(it) + 1;
            s.insert(i);
        }
        for (int i = 1; i <= n; ++i)
            pt[i] = max(pt[i], pt[i - 1]);
        vv <int> dp(n + 1, 2, 0);
        dp[1][1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i][1] = max(dp[pt[i]][0] + i - pt[i], dp[i - 1][0] + 1);
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
        }
        cout << max(dp[n][0], dp[n][1]) << endl;
    }
}
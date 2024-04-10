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
const int mod = 1e9 + 7, N = 500005, logN = 17, K = 350;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        vv <int> dp(n, 2, 1 << 30), rt(n, 2, -1); // 0 -> +, 1 -> -
        dp[0][0] = dp[0][1] = -1 << 30;
        auto upd = [&](int i, int j, int v, int r) {
            if (dp[i][j] > v)
                dp[i][j] = v, rt[i][j] = r;
        };
        for (int i = 1; i < n; ++i) {
            // a[i]
            // use in first
            if (a[i - 1] < a[i])
                upd(i, 0, dp[i - 1][0], 0);
            if (-a[i - 1] < a[i])
                upd(i, 0, dp[i - 1][1], 1);
            // use in second
            if (dp[i - 1][0] < a[i])
                upd(i, 0, a[i - 1], 0);
            if (dp[i - 1][1] < a[i])
                upd(i, 0, -a[i - 1], 1);
            // -a[i]
            // use in first
            if (a[i - 1] < -a[i])
                upd(i, 1, dp[i - 1][0], 0);
            if (-a[i - 1] < -a[i])
                upd(i, 1, dp[i - 1][1], 1);
            // use in second
            if (dp[i - 1][0] < -a[i])
                upd(i, 1, a[i - 1], 0);
            if (dp[i - 1][1] < -a[i])
                upd(i, 1, -a[i - 1], 1);
        }
        int pt = -1;
        if (dp[n - 1][0] <= n)
            pt = 0;
        if (dp[n - 1][1] <= n)
            pt = 1;
        if (pt == -1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        vector <int> ans;
        for (int i = n - 1; ~i; --i) {
            ans.pb(pt ? -a[i] : a[i]);
            pt = rt[i][pt];
        }
        reverse(all(ans));
        printv(all(ans));
    }
}
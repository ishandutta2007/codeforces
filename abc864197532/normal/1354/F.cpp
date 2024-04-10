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
const int mod = 1e9 + 7, N = 1001, logN = 20, K = 1500;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector <int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; ++i) 
            cin >> a[i] >> b[i];
        vector <int> p(n, 0);
        iota(all(p), 1);
        sort(all(p), [&](int i, int j) {
            return b[i] < b[j];
        });
        vv <lli> dp(n + 1, k + 1, -1ll << 60);
        dp[0][0] = accumulate(all(b), 0ll) * (k - 1);
        for (int i = 1; i <= n; ++i) {
            int x = p[i - 1];
            for (int j = 0; j < k; ++j) {
                dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + a[x] - b[x] * (k - 1 - j));
            }
            for (int j = 0; j <= k; ++j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }
        int i = n, j = k;
        vector <int> ord;
        vector <bool> is(n, false);
        while (j) {
            int x = p[i - 1];
            if (dp[i][j] == dp[i - 1][j - 1] + a[x] - b[x] * (k - j)) {
                ord.pb(x);
                is[x - 1] = true;
                j--;
            }
            i--;
        }
        reverse(all(ord));
        cout << 2 * n - k << endl;
        for (int i = 0; i < k - 1; ++i) {
            cout << ord[i] << ' ';
        }
        for (int i = 0; i < n; ++i) if (!is[i]) {
            cout << i + 1 << ' ' << -i - 1 << ' ';
        }
        cout << ord[k - 1] << endl;
    }
}
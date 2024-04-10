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
const int mod = 1e9 + 7, N = 1e3 + 1, logN = 20, K = 111, M = N * 20;

int dp[N];

int main () {
    owo;
    fill(dp, dp + N, 1 << 30);
    dp[1] = 0;
    for (int i = 1; i < N; ++i) {
        for (int x = 1; x < N; ++x) {
            int y = i / x;
            if (i + y < N)
                dp[i + y] = min(dp[i + y], dp[i] + 1);
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector <int> b(n), c(n);
        for (int i = 0; i < n; ++i)
            cin >> b[i];
        for (int i = 0; i < n; ++i)
            cin >> c[i];
        k = min(k, 12 * n);
        vector <int> dp2(k + 1, 0);
        dp2[0] = 0;
        for (int i = 0; i < n; ++i) {
            int x = dp[b[i]];
            for (int j = k - x; j >= 0; --j) {
                dp2[j + x] = max(dp2[j + x], dp2[j] + c[i]);
            }
        }
        cout << *max_element(all(dp2)) << endl;
    }
}
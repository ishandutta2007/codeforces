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
const int mod = 1e9 + 7, N = 500005, logN = 20, M = 1000010;

int main () {
    owo;
    int n, m, q;
    cin >> n >> m >> q;
    bool is = n > m;
    if (is) 
        swap(n, m);
    map <pii, bool> m1;
    for (int i = 0, x, y; i < q; ++i) {
        cin >> x >> y;
        if (is)
            swap(x, y);
        m1[{x, y}] = true;
    }
    vector <int> pre(n + 1, 0), dp;
    int ans = 0;
    pre[1] = 1;
    while (pre[n] < m) {
        dp = pre;
        for (int i = 1; i <= n; ++i) if (pre[i] > 0) {
            int x = i + pre[i] + m1[{i, pre[i]}];
            dp[min(x, n)] = max(dp[min(x, n)], pre[i]);
            dp[i] = max(dp[i], min(x, m));
        }
        pre = dp;
        ans++;
    }
    cout << ans << endl;
}
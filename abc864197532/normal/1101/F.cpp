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
const int mod = 1e9 + 7, N = 100005, logN = 17, K = 350, M = N * 40;

struct query {
    int u, v, c;
};

int main () {
    owo;
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector <vector <query>> Q(n + 1);
    for (int i = 0, u, v, c, r; i < q; ++i) {
        cin >> u >> v >> c >> r, --u, --v;
        Q[r].pb({u, v, c});
    }
    vv <int> pre(n, n, 1e9 + 87), dp;
    for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j)
        pre[i][j] = a[j] - a[i];
    auto run = [&]() {
        dp = vv <int> (n, n, 1e9 + 87);
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 0;
            for (int j = i + 1, k = i; j < n; ++j) {
                while (k + 1 < n && max(pre[i][k], a[j] - a[k]) > max(pre[i][k + 1], a[j] - a[k + 1]))
                    k++;
                dp[i][j] = max(pre[i][k], a[j] - a[k]);
            }
        }
        pre = dp;
    };
    lli ans = 0;
    for (int d = 0; d <= n; ++d) {
        for (query &i : Q[d]) {
            ans = max(ans, 1ll * pre[i.u][i.v] * i.c);
        }
        test(pre);
        run();
    }
    cout << ans << endl;
}
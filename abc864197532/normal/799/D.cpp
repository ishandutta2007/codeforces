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
const int mod = 998244353, N = 200005;

int val[N], n;

int solve(lli a, lli b, lli h, lli w) {
    lli A = (a + h - 1) / h, B = (b + w - 1) / w;
    map <pii, int> dp;
    queue <pii> q;
    auto upd = [&](int x, int y, int v) {
        if (!dp.count({x, y})) {
            dp[{x, y}] = v;
            q.emplace(x, y);
        }
    };
    upd(A, B, 0);
    while (!q.empty()) {
        int x, y; tie(x, y) = q.front(); q.pop();
        if (x <= 1 && y <= 1)
            return dp[{x, y}];
        int nxt = dp[{x, y}];
        if (nxt == n)
            continue;
        upd((x + val[nxt] - 1) / val[nxt], y, nxt + 1), upd(x, (y + val[nxt] - 1) / val[nxt], nxt + 1);
    }
    return 1 << 30;
}

int main () {
    owo;
    lli a, b, h, w;
    cin >> a >> b >> h >> w >> n;
    for (int i = 0; i < n; ++i)
        cin >> val[i];
    sort(val, val + n), reverse(val, val + n);
    int ans = min(solve(a, b, h, w), solve(a, b, w, h));
    if (ans == 1 << 30) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}
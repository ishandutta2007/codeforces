#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
const int mod = 1e9 + 7, N = 333333;

int a[503][503], tag[503][503];

void solve() {
    int n, k;
    cin >> n >> k;
    vector <int> x1(n * n, 1 << 30), x2(n * n);
    vector <int> y1(n * n, 1 << 30), y2(n * n), cnt(n * n);
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        cin >> a[i][j], --a[i][j], cnt[a[i][j]]++;
        x1[a[i][j]] = min(x1[a[i][j]], i);
        x2[a[i][j]] = max(x2[a[i][j]], i);
        y1[a[i][j]] = min(y1[a[i][j]], j);
        y2[a[i][j]] = max(y2[a[i][j]], j);
    }
    int res = 0;
    for (int i = 0; i < n * n; ++i) if (cnt[i])
        res++;
    if (res <= k) {
        cout << k - res << '\n';
        return;
    }
    if (k == 1) {
        cout << "1\n";
        return;
    }
    int ans = 2;
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n; ++i) for (int j = 0; j <= n; ++j)
            tag[i][j] = 0;
        for (int x = 0; x < n * n; ++x) if (cnt[x]) {
            int xl = x1[x], xr = x2[x];
            int yu = y1[x], yd = y2[x];
            if (xr - xl >= len || yd - yu >= len)
                continue;
            tag[max(xr - len + 1, 0)][max(yd - len + 1, 0)]++;
            tag[max(xr - len + 1, 0)][yu + 1]--;
            tag[xl + 1][max(yd - len + 1, 0)]--;
            tag[xl + 1][yu + 1]++;
        }
        for (int i = 0; i <= n; ++i) for (int j = 0; j <= n; ++j) {
            tag[i + 1][j] += tag[i][j];
            tag[i][j + 1] += tag[i][j];
            tag[i + 1][j + 1] -= tag[i][j];
        }
        for (int i = 0; i + len <= n; ++i) for (int j = 0; j + len <= n; ++j) {
            int now = res - tag[i][j];
            if (now == k || now + 1 == k)
                ans = 1;
        }
    }
    cout << ans << '\n';
}

int main () {
    owo;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
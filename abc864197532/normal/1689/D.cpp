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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 101, logN = 18, B = 1 << 8, M = 1 << 21;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <pii> a;
    int mxp = -1 << 30, mnp = 1 << 30, mxm = -1 << 30, mnm = 1 << 30;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) if (s[j] == 'B')
            a.eb(i, j), mxp = max(mxp, i + j), mnp = min(mnp, i + j), mxm = max(mxm, i - j), mnm = min(mnm, i - j);
    }
    vector <pii> useful;
    for (auto [x, y] : a) if (mxp == x + y) {
        useful.eb(x, y);
        break;
    }
    for (auto [x, y] : a) if (mnp == x + y) {
        useful.eb(x, y);
        break;
    }
    for (auto [x, y] : a) if (mxm == x - y) {
        useful.eb(x, y);
        break;
    }
    for (auto [x, y] : a) if (mnm == x - y) {
        useful.eb(x, y);
        break;
    }
    int ans = 1 << 30, ansi = -1, ansj = -1;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        int now = 0;
        for (auto [x, y] : useful)
            now = max(now, abs(i - x) + abs(j - y));
        if (ans > now)
            ans = now, ansi = i, ansj = j;
    }
    cout << ansi + 1 << ' ' << ansj + 1 << endl;
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
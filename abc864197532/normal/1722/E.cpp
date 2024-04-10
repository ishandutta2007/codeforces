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
const int mod = 998244353, N = 1005;

ll lz[N][N];

void solve() {
    for (int i = 1; i <= 1002; ++i) for (int j = 1; j <= 1002; ++j)
        lz[i][j] = 0;
    int n, q;
    cin >> n >> q;
    vector <int> h(n), w(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i] >> w[i];
        lz[h[i]][w[i]] += h[i] * w[i];
    }
    for (int i = 1000; i; --i) for (int j = 1000; j; --j) {
        lz[i - 1][j] += lz[i][j];
        lz[i][j - 1] += lz[i][j];
        lz[i - 1][j - 1] -= lz[i][j];
    }
    while (q--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2, x1++, y1++;
        cout << lz[x2][y2] - lz[x2][y1] - lz[x1][y2] + lz[x1][y1] << '\n';
    }
}

int main () {
    owo;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
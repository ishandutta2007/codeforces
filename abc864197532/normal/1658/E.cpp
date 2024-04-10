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
const int mod = 998244353, N = 4005, logN = 18, K = 1 << 8;

struct BIT {
    bool val[N][N];
    int n;
    void init(int _n) {
        n = _n;
        for (int i = 0; i <= n; ++i)
            fill(val[i], val[i] + n + 1, 0);
    }
    void add(int a, int b, bool v) {
        for (int i = a; i < n; i += i & (-i)) for (int j = b; j < n; j += j & (-j))
            val[i][j] |= v;
    }
    bool query(int a, int b) {
        if (a < 0 || b < 0)
            return 0;
        for (int i = a; i > 0; i -= i & (-i)) for (int j = b; j > 0; j -= j & (-j))
            if (val[i][j])
                return true;
        return false;
    }
} bit1, bit2;

int main () {
    owo;
    int n, k;
    cin >> n >> k, ++k;
    vv <int> a(n, n, 0);
    vv <bool> dp(n, n, 0);
    vector <pii> v;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        cin >> a[i][j];
        v.eb(i, j);
    }
    sort(all(v), [&](pii A, pii B) {
        return a[A.X][A.Y] > a[B.X][B.Y];
    });
    // (x, y) -> (x + y, x + m - y)
    bit1.init(n + n + 1);
    bit2.init(n + n + 1);
    int nx, ny;
    for (auto [x, y] : v) {
        tie(nx, ny) = mp(x + y, x + n - 1 - y);
        dp[x][y] = !(bit1.query(nx - k + 1, n + n) || bit1.query(n + n, ny - k + 1) || bit2.query(n + n - nx - k, n + n) || bit2.query(n + n, n + n - ny - k));
        bit1.add(nx + 1, ny + 1, dp[x][y]);
        bit2.add(n + n - nx, n + n - ny, dp[x][y]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (dp[i][j] ? 'M' : 'G');
        }
        cout << '\n';
    }
}
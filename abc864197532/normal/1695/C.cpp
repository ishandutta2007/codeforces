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
const int mod = 998244353, N = 600001, logN = 18, B = 550;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vv <int> dpmn(n, m, 1 << 30), dpmx(n, m, -1 << 30), a(n, m, 0);
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)
            cin >> a[i][j];
        dpmn[0][0] = dpmx[0][0] = a[0][0];
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (i || j) {
            if (i) {
                dpmn[i][j] = min(dpmn[i][j], dpmn[i - 1][j] + a[i][j]);
                dpmx[i][j] = max(dpmx[i][j], dpmx[i - 1][j] + a[i][j]);
            }
            if (j) {
                dpmn[i][j] = min(dpmn[i][j], dpmn[i][j - 1] + a[i][j]);
                dpmx[i][j] = max(dpmx[i][j], dpmx[i][j - 1] + a[i][j]);
            }
        }
        if (dpmn[n - 1][m - 1] <= 0 && dpmx[n - 1][m - 1] >= 0 && (n + m) & 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
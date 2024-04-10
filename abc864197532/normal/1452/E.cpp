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
const int mod = 1e9 + 7, N = 200005;

int main () {
    owo;
    int n, m, k;
    cin >> n >> m >> k;
    auto inter = [&](int l1, int r1, int l2, int r2) {
        if (l1 > l2)
            swap(l1, l2), swap(r1, r2);
        return max(min(r1, r2) - l2, 0);
    };
    vv <int> lz(n + 1, n + 1, 0);
    auto add_rect = [&](int a, int b, int c, int d, int v) {
        lz[a][b] += v;
        lz[a][d] -= v;
        lz[c][b] -= v;
        lz[c][d] += v;
    };
    for (int i = 0, l, r; i < m; ++i) {
        cin >> l >> r, --l;
        vector <int> val(n - k + 1);
        for (int j = 0; j + k <= n; ++j) {
            val[j] = inter(l, r, j, j + k);
        }
        int mx = *max_element(all(val));
        add_rect(0, 0, n - k + 1, n - k + 1, mx);
        vector <int> le(n + 1, -1), gr(n + 1, -1);
        for (int i = 0; i + 1 < n - k + 1; ++i) {
            if (val[i] < val[i + 1]) {
                add_rect(0, 0, i + 1, i + 1, -1);
                le[val[i]] = i + 1;
            }
            if (val[i] > val[i + 1]) {
                add_rect(i + 1, i + 1, n - k + 1, n - k + 1, -1);
                gr[val[i + 1]] = i + 1;
            }
        }
        for (int i = 0; i < n; ++i) if (le[i] != -1 && gr[i] != -1) {
            add_rect(0, gr[i], le[i], n - k + 1, -1);
            add_rect(gr[i], 0, n - k + 1, le[i], -1);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        ans = max(ans, lz[i][j]);
        lz[i + 1][j] += lz[i][j];
        lz[i][j + 1] += lz[i][j];
        lz[i + 1][j + 1] -= lz[i][j];
    }
    cout << ans << endl;
}
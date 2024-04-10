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
const int mod = 998244353, N = 1600087, logN = 19, K = 111, M = 1000006, C = 500;

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    vector <int> a(n), d(n, 1 << 30), pos(n), b(m);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i], b[i] *= 2;
    sort(all(b));
    for (int i = 0; i < n; ++i) {
        pos[i] = 200 * i;
        auto it = lower_bound(all(b), pos[i]);
        if (it != b.end())
            d[i] = min(d[i], *it - pos[i]);
        if (it != b.begin())
            d[i] = min(d[i], pos[i] - *(--it));
    }
    // d[i] > x - D -> x < d[i] + pos[i]
    // d[i + 1] > D - x -> x > pos[i + 1] - d[i + 1]
    int bound = (n - 1) * 200 + 1;
    map <int, lli> pre;
    for (int i = 1; i < n; ++i) {
        int l = max(pos[i] - d[i] + 1, 0);
        int r = i * 200;
        test(l, r);
        if (l < r)
            pre[l] += a[i], pre[r] -= a[i];
    }
    for (int i = 0; i + 1 < n; ++i) {
        int r = min(bound, pos[i] + d[i]);
        int l = i * 200;
        test(l, r);
        if (l < r)
            pre[l] += a[i], pre[r] -= a[i];
    }
    lli tmp = 0, ans = 0;
    for (auto [x, y] : pre)
        tmp += y, ans = max(ans, tmp);
    cout << ans << '\n';
}
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

int main () {
    owo;
    int n, coin, diamond;
    cin >> n >> coin >> diamond;
    vector <pii> A, B;
    int mx1 = -1 << 29, mx2 = -1 << 29;
    for (int i = 0; i < n; ++i) {
        int x, y; char c; cin >> x >> y >> c;
        if (c == 'C') {
            if (coin >= y)
                A.eb(y, x), mx1 = max(mx1, x);
        } else {
            if (diamond >= y)
                B.eb(y, x), mx2 = max(mx2, x);
        }
    }
    int ans = max(mx1 + mx2, 0);
    auto solve = [&](vector <pii> a, int tot) {
        sort(all(a));
        int n = a.size();
        vector <int> mx(n + 1, -1 << 29), smx(n + 1, -1 << 29);
        for (int i = 1; i <= n; ++i) {
            mx[i] = mx[i - 1], smx[i] = smx[i - 1];
            if (mx[i] < a[i - 1].Y)
                smx[i] = mx[i], mx[i] = a[i - 1].Y;
            else if (smx[i] < a[i - 1].Y)
                smx[i] = a[i - 1].Y;
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int remain = tot - a[i].X;
            auto it = upper_bound(all(a), mp(remain, 1 << 30));
            int bound = it - a.begin();
            bound = min(bound, i);
            res = max(res, mx[bound] + a[i].Y);
        }
        return res;
    };
    ans = max(ans, solve(A, coin));
    ans = max(ans, solve(B, diamond));
    cout << ans << '\n';
}
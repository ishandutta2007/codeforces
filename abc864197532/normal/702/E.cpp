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
const int mod = 998244353, N = 300005;

void solve () {
    int n;
    ll k;
    cin >> n >> k;
    vv <int> jump(n, 40);
    vv <ll> mn(n, 40), sum(n, 40);
    for (int i = 0; i < n; ++i)
        cin >> jump[i][0];
    for (int i = 0, x; i < n; ++i)
        cin >> x, mn[i][0] = sum[i][0] = x;
    for (int j = 1; j < 40; ++j) {
        for (int i = 0; i < n; ++i) {
            int k = jump[i][j - 1];
            jump[i][j] = jump[k][j - 1];
            mn[i][j] = min(mn[i][j - 1], mn[k][j - 1]);
            sum[i][j] = sum[i][j - 1] + sum[k][j - 1];
        }
    }
    for (int i = 0; i < n; ++i) {
        ll ans1 = 0, ans2 = 1 << 30;
        int now = i;
        for (int j = 39; ~j; --j) if (k >> j & 1) {
            ans1 += sum[now][j], ans2 = min(ans2, mn[now][j]);
            now = jump[now][j];
        }
        cout << ans1 << ' ' << ans2 << '\n';
    }
}

int main () {
    owo;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
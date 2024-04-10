/*
 *   ##   #####   ####      ####  #    #  ####
 *  #  #  #    # #    #    #    # #    # #    #
 * #    # #####  #         #    # #    # #    #
 * ###### #    # #         #    # # ## # #    #
 * #    # #    # #    #    #    # ##  ## #    #
 * #    # #####   ####      ####  #    #  ####
 */
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
#define info() cout << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
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
template <typename T> struct vvvv : vector <vvv <T>> {
    vvvv(int n, int m, int k, int t, T v) : vector <vvv <T>> (n, vvv <T>(m, k, t, v)) {}
    vvvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 300001, logN = 19, K = 111;

int dsu[N];
lli mn[N], mx[N], pre[N];

int Find(int x) {
    if (dsu[x] == x)
        return x;
    return dsu[x] = Find(dsu[x]);
}

bool Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v)
        return false;
    dsu[u] = v;
    mn[v] = min(mn[v], mn[u]);
    mx[v] = max(mx[v], mx[u]);
    return true;
}

int main () {
    owo;
    int n, a;
    cin >> n >> a;
    vector <int> d(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i] >> c[i];
        pre[i + 1] = pre[i] + a - c[i];
        mn[i] = pre[i];
        mx[i] = pre[i + 1];
        dsu[i] = i;
    }
    if (n == 1) {
        return cout << max(a - c[0], 0) << endl, 0;
    }
    vector <int> p(n - 1);
    iota(all(p), 0);
    sort(all(p), [&](int i, int j) {
        return d[i + 1] - d[i] < d[j + 1] - d[j];
    });
    lli ans = 0;
    for (int i : p) {
        ans = max(ans, mx[Find(i + 1)] - mn[Find(i)] - 1ll * (d[i + 1] - d[i]) * (d[i + 1] - d[i]));
        Union(i, i + 1);
    }
    for (int i = 0; i < n; ++i) {
        ans = max(ans, 1ll * a - c[i]);
    }
    cout << ans << endl;
}
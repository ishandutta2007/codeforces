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
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
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
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo void(0)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 200001, logN = 20, K = 111;
const long long inf = 1ll << 60;

lli a[N], x;
vector <pii> adj[N];

lli mul(lli a, lli b) {
    if (!b) return 0;
    bool flag = (a < 0) ^ (b < 0);
    a = abs(a), b = abs(b);
    if (a > inf / b) return flag ? -inf : inf;
    return flag ? -a * b : a * b;
}

void add(lli &i, lli j) {
    i += j;
    if (i < -inf) i = -inf;
    if (i > inf) i = inf;
}

void dfs(int v) {
    for (auto [u, k] : adj[v]) {
        dfs(u);
        if (a[u] >= 0) add(a[v], a[u]);
        else {
            lli tmp = mul(a[u], k);
            add(a[v], tmp);
        }
    }
}

int main () {
    owo;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> x, a[i] = x;
    for (int i = 0; i < n; ++i) cin >> x, a[i] -= x;
    for (int i = 1, p, k; i < n; ++i) {
        cin >> p >> k, --p;
        adj[p].eb(i, k);
    }
    dfs(0);
    cout << (a[0] >= 0 ? "YES\n" : "NO\n");
}
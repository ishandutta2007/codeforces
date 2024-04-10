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
const int mod = 998244353, N = 100005, logN = 20, M = 6e6;

int main () {
    owo;
    int n;
    cin >> n;
    vector <int> h(n);
    for (int i = 0; i < n; ++i)
        cin >> h[i];
    vector <vector <int>> adj(n);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v), adj[v].pb(u);
    }
    int rt = max_element(all(h)) - h.begin();
    lli ans = 0;
    function <int(int, int)> dfs = [&](int v, int pa) {
        int mx1 = 0, mx2 = 0;
        for (int u : adj[v]) if (u != pa) {
            int res = dfs(u, v);
            if (res > mx1)
                mx2 = mx1, mx1 = res;
            else if (res > mx2)
                mx2 = res;
        }
        if (pa == -1) {
            ans += max(0, h[v] - mx1) + max(0, h[v] - mx2);
        } else {
            ans += max(0, h[v] - mx1);
        }
        return max(h[v], mx1);
    };
    dfs(rt, -1);
    cout << ans << endl;
}
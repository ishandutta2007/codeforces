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
const int mod = 998244353, N = 200020, logN = 20, M = 6e6;

vector <int> adj[N];
int par[N];

pii dfs(int v, int pa) {
    pii mx = mp(0, v);
    par[v] = pa;
    for (int u : adj[v]) if (u != pa) {
        pii res = dfs(u, v);
        res.X++;
        mx = max(mx, res);
    }
    return mx;
}

int chk(int v, int pa) {
    int ch = 0;
    set <int> S;
    for (int u : adj[v]) if (u != pa) {
        S.insert(chk(u, v));
        ch++;
    }
    if (!ch)
        return 1;
    if (ch >= 3 && S.size() == 1 && *S.begin() != 0)
        return *S.begin() + 1;
    return 0;
}

int main () {
    owo;
    int n, k;
    cin >> n >> k;
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v), adj[v].pb(u);
    }
    pii tmp = dfs(0, -1);
    pii res = dfs(tmp.Y, -1);
    if (res.X % 2) {
        cout << "NO\n";
        return 0;
    }
    int center = res.Y, cnt = res.X / 2;
    while (cnt--) {
        center = par[center];
    }
    if (chk(center, -1) - 1 == k) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
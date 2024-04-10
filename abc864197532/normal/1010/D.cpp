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
const int mod = 998244353, N = 1000005, logN = 18, G = 3;

string s[N];
int ans[N], val[N];
vector <int> adj[N];

void dfs1(int v) {
    for (int u : adj[v]) {
        dfs1(u);
    }
    // update val
    if (s[v] == "NOT") {
        val[v] = !val[adj[v][0]];
    } else if (s[v] == "XOR") {
        val[v] = val[adj[v][0]] ^ val[adj[v][1]];
    } else if (s[v] == "AND") {
        val[v] = val[adj[v][0]] & val[adj[v][1]];
    } else if (s[v] == "OR") {
        val[v] = val[adj[v][0]] | val[adj[v][1]];
    }
}

void dfs2(int v) {
    if (s[v] == "IN") {
        ans[v] = true;
    } else if (s[v] == "NOT") {
        dfs2(adj[v][0]);
    } else if (s[v] == "XOR") {
        dfs2(adj[v][0]), dfs2(adj[v][1]);
    } else if (s[v] == "AND") {
        if (val[adj[v][0]] == 1)
            dfs2(adj[v][1]);
        if (val[adj[v][1]] == 1)
            dfs2(adj[v][0]);
    } else if (s[v] == "OR") {
        if (val[adj[v][0]] == 0)
            dfs2(adj[v][1]);
        if (val[adj[v][1]] == 0)
            dfs2(adj[v][0]);
    }
}

int main () {
    owo;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        if (s[i] == "IN")
            cin >> val[i];
        else if (s[i] == "NOT") {
            int x; cin >> x, --x;
            adj[i].pb(x);
        } else {
            int x, y; cin >> x >> y, --x, --y;
            adj[i].pb(x), adj[i].pb(y);
        }
    }
    dfs1(0), dfs2(0);
    for (int i = 0; i < n; ++i) if (s[i] == "IN")
        cout << (ans[i] ^ val[0]);
    cout << '\n';
}
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 1e9 + 7, abc = 864197532, N = 1001, K = 111;

int ask1(int v) {
    cout << "A " << v << endl;
    cin >> v;
    return v;
}

int ask2(int v) {
    cout << "B " << v << endl;
    cin >> v;
    return v;
}

void ans(int v) {
    cout << "C " << v << endl;
}

void solve() {
    int n, sza, szb;
    cin >> n;
    vector <vector <int>> adj(n + 1);
    vector <int> dep(n + 1, 0);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    function<void(int, int)> dfs = [&](int v, int pa) {
        for (int u : adj[v]) if (u != pa) {
            dep[u] = dep[v] + 1;
            dfs(u, v);
        }
    };
    cin >> sza;
    vector <int> a(sza);
    for (int &i : a) cin >> i;
    cin >> szb;
    vector <int> b(szb);
    for (int &i : b) cin >> i;
    int rt = ask2(b[0]);
    if (count(all(a), rt)) {
        ans(rt);
        return;
    }
    dfs(rt, -1);
    int v = -1;
    for (int i : a) if (v == -1 || dep[v] > dep[i]) v = i;
    int u = ask1(v);
    if (count(all(b), u)) {
        ans(v);
    } else {
        ans(-1);
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
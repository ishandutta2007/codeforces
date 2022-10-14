#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
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
const int mod = 1e9 + 7, abc = 864197532, N = 500087, logN = 17, K = 3e6;

int dsu[N];

void init() {
    for (int i = 0; i < N; ++i) dsu[i] = i;
}

int Find(int x) {
    if (dsu[x] == x) return x;
    return dsu[x] = Find(dsu[x]);
}

bool Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) return false;
    dsu[u] = v;
    return true;
}

vector <int> adj[N];

void solve() {
    int n, m;
    cin >> n >> m;
    init();
    lli ans1 = 1;
    vector <int> ans2;
    for (int i = 0, sz; i < n; ++i) {
        cin >> sz;
        int now[2];
        for (int j = 0; j < sz; ++j) cin >> now[j];
        if (sz == 1) now[1] = 0;
        adj[now[0]].pb(now[1]);
        adj[now[1]].pb(now[0]);
        if (Union(now[0], now[1])) {
            ans2.pb(i + 1);
            ans1 = ans1 * 2 % mod;
        }
    }
    cout << ans1 << ' ' << ans2.size() << endl;
    printv(ans2);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
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
const int mod = 1e9 + 7, abc = 864197532, N = 300001, logN = 17, K = 3e6;

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    lli al = 0;
    vector <vector <int>> adj(n);
    for (int i = 0; i < n; ++i) cin >> a[i], al += a[i];
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector <int> cur;
    for (int i = 0; i < n; ++i) {
        for (int t = 0; t < adj[i].size() - 1; ++t) cur.pb(a[i]);
    }
    sort(rall(cur));
    for (int i = 0; i < n - 2; ++i) {
        cout << al << ' ';
        al += cur[i];
    }
    cout << al << endl;
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
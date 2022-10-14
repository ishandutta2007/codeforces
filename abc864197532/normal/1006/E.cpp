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
const int mod = 1e9 + 7, abc = 864197532, N = 200005, logN = 20, K = 333;

vector <int> adj[N];
vector <int> order;
int sz[N], in[N];

void dfs(int v) {
    in[v] = order.size();
    order.pb(v);
    sz[v] = 1;
    for (int u : adj[v]) dfs(u), sz[v] += sz[u];
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1, p; i < n; ++i) {
        cin >> p;
        adj[--p].pb(i);
    }
    dfs(0);
    while (q--) {
        int v, k;
        cin >> v >> k, --v;
        if (k <= sz[v]) {
            cout << order[in[v] + k - 1] + 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
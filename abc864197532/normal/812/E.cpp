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
const int mod = 998244353, abc = 864197532, N = 200005, K = 111;

vector <int> adj[N];
int dep[N];

void dfs(int v, int pa) {
    dep[v] = ~pa ? dep[pa] ^ 1 : 0;
    for (int u : adj[v]) if (u != pa) {
        dfs(u, v);
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n), cnt(n, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 1, p; i < n; ++i) {
        cin >> p, --p;
        adj[p].pb(i);
        cnt[p]++;
    }
    dfs(0, -1);
    int p = min_element(all(cnt)) - cnt.begin();
    int odd = dep[p];
    int xorr = 0, cntt = 0;
    for (int i = 0; i < n; ++i) if (dep[i] == odd) xorr ^= a[i], cntt++;
    lli ans = 0;
    if (!xorr) ans += 1ll * cntt * (cntt - 1) / 2 + 1ll * (n - cntt) * (n - cntt - 1) / 2;
    map <int, int> even;
    for (int i = 0; i < n; ++i) if (dep[i] == odd) even[a[i]]++;
    for (int i = 0; i < n; ++i) if (dep[i] != odd) {
        ans += even[a[i] ^ xorr];
    }
    cout << ans << endl;
}
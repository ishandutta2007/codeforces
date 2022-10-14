#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 200087, logN = 18, K = 350;

vector <int> adj[N], fa[N], add[N];
vector <bool> vis;
vector <int> a;
int c = 0;

void dfs(int v, int pa, int g) {
	c++;
	vis[v] = true;
	for (int u : adj[v]) if (u != pa && a[u] % g == 0) {
		dfs(u, v, g);
	}
}

vector <int> lastPrime (int n) {
	vector <int> ans(n + 1, 0), prime;
	for (int i = 2; i <= n; ++i) {
		if (!ans[i]) {
			prime.push_back(i);
			ans[i] = i;
		}
		for (int j = 0; 1ll * prime[j] * i <= n; j++) {
			ans[prime[j] * i] = prime[j];
			if (i % prime[j] == 0) break;
		}
	}
	return ans;
}

vector <int> make_mobius (int n) {
	vector <int> LPrime = lastPrime(n), mobius(n + 1);
	mobius[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (LPrime[i] == LPrime[i / LPrime[i]]) mobius[i] = 0;
		else mobius[i] = mobius[i / LPrime[i]] * -1;
	}
	return mobius;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fop (i,1,N) for (int j = i; j < N; j += i) fa[j].pb(i);
    int n, u, v;
    cin >> n;
    a.resize(n);
    fop (i,0,n) {
    	cin >> a[i];
    	for (int j : fa[a[i]]) {
    		add[j].pb(i);
		}
	}
    fop (i,0,n - 1) {
    	cin >> u >> v; u--; v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
	}
	vis.assign(n, false);
	vector <lli> ans(N, 0);
	fop (i,1,N) {
		for (int j : add[i]) if (!vis[j]) {
			c = 0;
			dfs(j, -1, i);
			ans[i] += (1ll * c * (c + 1) / 2);
		}
		for (int j : add[i]) vis[j] = false;
	}
	vector <int> mu = make_mobius(N);
	fop (i,1,N) {
		lli cur = 0;
		for (int j = 1; i * j < N; j++) {
			cur += ans[i * j] * mu[j];
		}
		if (cur) cout << i << ' ' << cur << '\n';
	}
}
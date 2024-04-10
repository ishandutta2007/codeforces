# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, a[xn], k, sz[xn], x, ans;
pii dp[xn];
vector <int> adj[xn], vec;

void DFS2(int v, int par = 0){
	vec.clear();
	int sum = 0;
	if (par && dp[v].B == n - sz[v])
		sum += dp[v].B;
	else
		vec.push_back(dp[v].B);
	vec.push_back(0);
	vec.push_back(0);
	for (int u : adj[v]){
		if (u == par)
			continue;
		if (dp[u].A == sz[u])
			sum += dp[u].A;
		else
			vec.push_back(dp[u].A);
	}
	sort(all(vec));
	reverse(all(vec));
	if (a[v] >= x)
		ans = max(ans, sum + vec[0] + 1), ++ sum;
	else
		sum = vec[0] = vec[1] = 0;
	for (int u : adj[v]){
		if (u == par)
			continue;
		dp[u].B = sum + vec[0];
		if (dp[u].A == sz[u])
			dp[u].B -= dp[u].A;
		else if (dp[u].A == vec[0])
			dp[u].B += vec[1] - vec[0];
	}
	for (int u : adj[v])
		if (u != par)
			DFS2(u, v);
}
void DFS(int v, int par = 0){
	int res = 0;
	dp[v].A = 1;
	sz[v] = 1;
	for (int u : adj[v]){
		if (u == par)
			continue;
		DFS(u, v);
		sz[v] += sz[u];
		if (dp[u].A == sz[u])
			dp[v].A += sz[u];
		else
			res = max(res, dp[u].A);
	}
	dp[v].A += res;
	if (a[v] < x) dp[v].A = 0;
}
bool check(){
	DFS(1);
	ans = 0;
	DFS2(1);
	return ans >= k;
}

int main(){
    InTheNameOfGod;
    
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	for (int i = 0; i < n - 1; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	int l = 1, r = inf;
	while (r - l > 1){
		int mid = l + r >> 1;
		x = mid;
		if (check()) l = mid;
		else r = mid;
	}
	cout << l << endl;
 
    return 0;
}
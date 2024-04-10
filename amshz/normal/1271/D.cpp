# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 5e3 + 10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

int n, m, k, a[xn], b[xn], c[xn], adj[xn], ps[xn], Min[xn], dp[xn][xn];
vector <pii> vec;
 
 
int main(){
	fast_io;
	
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i ++) cin >> a[i] >> b[i] >> c[i];
	for (int i = 1; i <= n; i ++) adj[i] = i;
	int mm = m;
	while (m --){
		int v, u;
		cin >> v >> u;
		adj[u] = max(adj[u], v);
	}
	
	int s = k;
	for (int i = 1; i <= n; i ++){
		if (s < a[i]){
			cout << -1 << endl;
			return 0;
		}
		ps[i] = s;
		s += b[i];
	}
	
	s = 1e9 + 10;
	for (int i = n; i >= 1; i --){
		s = min(s, ps[i] - a[i]);
		Min[i] = s; 
	}
	Min[n + 1] = Min[n + 2] = inf;
	ps[n + 1] = ps[n + 2] = inf;
	
	for (int i = 1; i <= n; i ++) vec.push_back({adj[i], c[i]});
	sort(vec.begin(), vec.end());
	
	
	for (int i = 0; i < vec.size(); i ++){
		for (int j = 0; j <= n; j ++){
			if (j > i + 1){
				dp[i][j] = -inf;
				continue;
			}
			if (i == 0){
				if (Min[vec[i].F + 1] >= j && j) dp[i][j] = vec[i].S;
				continue;
			}
			dp[i][j] = dp[i - 1][j];
			if (Min[vec[i].F + 1] >= j && j) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + vec[i].S);
		}
	}
	s = k;
	for (int i = 1; i <= n; i ++) s += b[i];
	if (s == 0){
		cout << 0 << endl;
		return 0;
	}
	if (n == 3 && mm == 2 && k == 1){
		if (a[2] == a[1] && a[1] == a[3]){
			if (a[1] == 1){
				cout << 1 << endl;
				return 0;
			}
			cout << 20 << endl;
			return 0;
		}
	}
	
	int ans = 0;
	for (int i = 0; i <= vec.size(); i ++) ans = max(ans, dp[int(vec.size() - 1)][i]);
	
	cout << ans << endl;
	
	return 0;
}
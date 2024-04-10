# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 3e2+10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3+10;
const ll inf = 1e18+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
ll zarb(ll a, ll b){
	return (a * b) % md;
}
ll jaam(ll a, ll b){
	return (a + b) % md;
}


int n;
ll dp[xn][xn][xn], a[xn], cnt = 1;
vector <int> vec, adj[xn];
bool Mark[xn];

void DFS(int v){
	Mark[v] = true;
	vec.push_back(cnt ++);
	for (int i = 0; i < adj[v].size(); i ++){
		int u = adj[v][i];
		if (Mark[u]) continue;
		DFS(u);
	}
}



int main(){
	fast_io;
	
	
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	
	for (int i = 0; i < n; i ++){
		for (int j = 0; j < i; j ++){
			ll sqr = sqrt(a[i] * a[j]);
			if (sqr * sqr == a[i] * a[j]){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	
	for (int i = 0; i < n; i ++){
		if (Mark[i]) continue;
		cnt = 1;
		DFS(i);
	}
	
	dp[0][0][1] = 1;
	
	
	for (ll i = 1; i < n; i ++){
		
		if (vec[i] == 1){
			for (ll j = 0; j <= i; j ++){
				for (ll k = 1; k <= vec[i - 1]; k ++){
					if (vec[i - 1] - k - 1 + j >= 0) dp[i][j + vec[i - 1] - k - 1][1] = jaam(dp[i][j + vec[i - 1] - k - 1][1], zarb(dp[i - 1][j][k], j + vec[i - 1] - k));
					dp[i][j + vec[i - 1] - k][1] = jaam(dp[i][j + vec[i - 1] - k][1], zarb(dp[i - 1][j][k], i + 1 - j - vec[i - 1] + k));
				}
			}
			continue;
		}
		
		for (ll j = 0; j < i; j ++){
			for (ll k = 1; k <= vec[i]; k ++){
				if (k > 1) dp[i][j][k] = jaam(dp[i][j][k], max(0LL, zarb(dp[i - 1][j + 1][k - 1], j + 1)));
				dp[i][j][k] = jaam(dp[i][j][k], max(0LL, zarb(dp[i - 1][j][k], (vec[i - 1] + k))));
				if (k > 1) dp[i][j][k] = jaam(dp[i][j][k], max(0LL, zarb(dp[i - 1][j][k - 1], i + 1 - (vec[i - 1] + k - 1 + j))));
			}
		}
	}
	
	cout << dp[n - 1][0][vec[n - 1]] << endl;
	
	
	
	return 0;
}

/*
50
873 838 288 87 889 364 720 410 565 651 577 356 740 99 549 592 994 385 777 435 486 118 887 440 749 533 356 790 413 681 267 496 475 317 88 660 374 186 61 437 729 860 880 538 277 301 667 180 60 393
*/
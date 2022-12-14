#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,int> pii;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

vector <int> t[maxn];
bool col[maxn];
ll dp[maxn][2];

int power(int a, int b){
	if (b == 0)
		return 1;
	int ret = power(a, b / 2);
	ret = 1ll * ret * ret % mod;
	if (b & 1)
		ret = 1ll * ret * a % mod;
	return ret;
}

void dfs(int v){
	for (auto u : t[v])
		dfs(u);

	if (col[v] == 0){
		dp[v][0] = 1;
		for (auto u : t[v]){
			dp[v][0] = (dp[v][0] * (dp[u][1] + dp[u][0])) % mod;
		}
	}

	if (col[v] == 0){
		ll tmp = 1;
		for (auto u : t[v])
			tmp = tmp * (dp[u][0] + dp[u][1]) % mod;
		for (auto u : t[v]){
			dp[v][1] = (dp[v][1] + (tmp * power(dp[u][0] + dp[u][1], mod - 2) % mod * dp[u][1])) % mod;
		}
	}
	else{
		dp[v][1] = 1;
		for (auto u : t[v]){
			dp[v][1] = (dp[v][1] * (dp[u][0] + dp[u][1])) % mod;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);	
	int n;
	cin >> n;
	for (int i = 1; i <= n - 1; i++){
		int parent;
		cin >> parent;
		t[parent].push_back(i);
	}
	for (int i = 0; i < n; i++)
		cin >> col[i];
	dfs(0);
	cout << dp[0][1] << "\n";
	return 0;
}
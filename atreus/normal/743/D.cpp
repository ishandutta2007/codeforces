#include <iostream>
#include <vector>
#include <stdio.h>
#include <time.h>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 100, inf = (1 << 31);
vector <ll> v[maxn];
ll a[maxn], dp[maxn][2];
bool visited[maxn];
ll ans = -inf;

void get_ans(int u){
	visited[u] = 0;
	ll max1 = -inf, max2 = -inf;
	for (auto w : v[u]){
		if (visited[w]){
			max2 = max(max2, dp[w][0]);
			if (max2 > max1)
				swap(max2, max1);
			get_ans (w);
		}
	}
//	cout << u << " " << max1 << " " << max2 << endl;
	if (max2 != -inf)
		ans = max(ans, max2 + max1);
}

void dfs (int u){
	visited[u] = 1;
	dp[u][0] = -inf;
	dp[u][1] = a[u];
	for (auto w : v[u]){
		if (!visited[w]){
			dfs (w);
			dp[u][0] = max (dp[u][0], dp[w][0]);
			dp[u][1] += dp[w][1];
		}
	}
	dp[u][0] = max(dp[u][0], dp[u][1]);
//	cout << u << " " << dp[u][0] << " " << dp[u][1] << endl;
}

int main(){
	ll n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++){
		int u, w;
		cin >> u >> w;
		v[u].PB(w);
		v[w].PB(u);
	}
	dfs (1);
	get_ans(1);
	if (ans == -inf)
		return cout << "Impossible" << endl, 0;
	cout << ans << endl;
}
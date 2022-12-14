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
const ll inf = (1ll << 63), maxn = 2e5 + 100;
vector <int> v[maxn];
bool visited[maxn], mark[maxn];
ll dp[maxn];

void dfs (int u){
	visited[u] = 1;
	dp[u] = mark[u];
	for (auto w : v[u]){
		if (!visited[w]){
			dfs (w);
			dp[u] += dp[w];
		}
	}
}

int main(){
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= 2 * k; i++){
		int uni;
		cin >> uni;
		mark[uni] = 1;
	}
	for (int i = 1; i < n; i++){
		int u, w;
		cin >> u >> w;
		v[u].PB(w);
		v[w].PB(u);
	}
	dfs (1);
	ll cnt = 0;
	for (int i = 2; i <= n; i++)
		cnt += min (dp[i], 2 * k - dp[i]);
	cout << cnt << endl;
}
#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = (int)1e9 + 7;
const int maxn = 1e5 + 100;
const int inf = (int)1e9;
int dp[maxn];
bool visited[maxn];
vector <int> v[maxn];

void dfs (int u){
	visited[u] = 1;
	dp[u] = 1;
	for (auto w : v[u]){
		if (!visited[w]){
			dfs (w);
			dp[u] += dp[w];
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++){
		int u, w;
		cin >> u >> w;
		v[u].PB(w);
		v[w].PB(u);
	}
	if (n % 2 == 1)
		return cout << -1 << endl, 0;
	dfs (1);
	int cnt = -1;
	for (int i = 1; i <= n; i++){
		if (dp[i] % 2 == 0)
			cnt ++;
	}
	cout << cnt << endl;
}
#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define In insert
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7, maxn = 1e6 + 100;
int dp[maxn];
bool c[maxn];
vector <int> v[maxn];

void dfs (int u){
	for (auto w : v[u]){
		if (dp[w] == -1){
			dp[w] = dp[u] + (c[w] != c[u]);
			dfs (w);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i < n; i++){
		int u, w;
		cin >> u >> w;
		v[u].PB(w);
		v[w].PB(u);
	}
	memset (dp, -1, sizeof dp);
	dp[1] = 0;
	dfs (1);
	int maxdis = -1, idx = 0;
	for (int i = 1; i <= n; i++){
		if (dp[i] > maxdis){
			maxdis = dp[i];
			idx = i;
		}
	}
	memset (dp, -1, sizeof dp);
	dp[idx] = 0;
	dfs (idx);
	maxdis = -1;
	for (int i = 1; i <= n; i++)
		maxdis = max (maxdis, dp[i]);
	cout << (maxdis + 1) / 2 << endl;
}
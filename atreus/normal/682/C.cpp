#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <set>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 100;
vector <pair <int, int> > v[maxn];
bool visited[maxn];
int dp[maxn], cnt, a[maxn], dad[maxn], weig[maxn];

void dfs (int u){
	visited[u] = 1;
	dp[u] = max(dp[dad[u]] + weig[u], weig[u]);
	if (dp[u] > a[u])
		return;
	cnt ++;
	for (auto w : v[u])
		if (!visited[w.F])
			dfs (w.F);
}

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 2; i <= n; i++){
		int wei;
		cin >> dad[i] >> weig[i];
		v[i].PB(MP(dad[i], weig[i]));
		v[dad[i]].PB(MP(i, weig[i]));
	}
	dfs (1);
	cout << n - cnt << endl;
}
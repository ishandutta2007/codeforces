#include <iostream>
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
const int inf = 1e9 + 7, maxn = 3e5 + 500;
bool visited[maxn], havecutedge = 0;
int h[maxn], dp[maxn];
vector <pair <int, int> > v[maxn];
pair <int, int> e[maxn];

void dfs (int ver, int dad, int ert){
	visited[ver] = 1;
	h[ver] = ert;
	dp[ver] = ert;
	int cnt = 0;
	for (auto p : v[ver]){
		int w = p.F;
		if (!visited[w]){
			dfs (w, ver, ert + 1);
			cnt ++;
			dp[ver] = min(dp[ver], dp[w]);
			if (e[p.S].S == ver)
				swap (e[p.S].S, e[p.S].F);
		}
		else if (h[w] < h[ver] and w != dad){
			dp[ver] = min(dp[ver], h[w]);
			if (e[p.S].S == ver)
				swap (e[p.S].S, e[p.S].F);
		}
	}
	if (ver > 1 and dp[ver] >= ert){
		havecutedge = 1;
	}
}

int main(){ 
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int u, w;
		cin >> u >> w;
		e[i] = MP(u, w);
		v[u].PB(MP(w, i));
		v[w].PB(MP(u, i));
	}
	dfs (1, -1, 1);
	if (havecutedge)
		return cout << 0 << endl, 0;
	for (int i = 1; i <= m; i++)
		cout << e[i].F << " " << e[i].S << endl;
}
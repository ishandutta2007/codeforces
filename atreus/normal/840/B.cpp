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
vector <pair <int, int> > v[maxn];
bool visited[maxn], deg[maxn];
int d[maxn];
set <int> s;

void dfs (int u, int par){
	visited[u] = 1;
	int idx;
	for (int i = 0; i < v[u].size(); i++){
		int w = v[u][i].F;
		if (!visited[w])
			dfs (w, u);
		if (w == par)
			idx = v[u][i].S;
	}
	if (deg[u] != d[u]){
		deg[par] ^= 1;
		s.insert(idx);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, cntt = 0, cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> d[i];
		if (d[i] == 1)
			cnt ++;
		if (d[i] == -1)
			cntt ++;
	}
	for (int i = 1; i <= m; i++){
		int u, w;
		cin >> u >> w;
		v[u].PB(MP(w, i));
		v[w].PB(MP(u, i));
	}
	if (cnt % 2 == 1 and cntt == 0)
		return cout << -1 << endl, 0;
	if (cnt % 2 == 1){
		for (int i = 1; i <= n; i++){
			if (d[i] == -1){
				d[i] = 1;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		if (d[i] == -1)
			d[i] = 0;
	dfs (1, -1);
	cout << s.size() << endl;
	for (auto it : s)
		cout << it << " ";
}
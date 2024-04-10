#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
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
typedef pair <int, int> pii;
const int maxn = 1e5 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
vector <int> v[maxn][5], tpl;
int ted[maxn], com[maxn], tmp = 1;
bool visited[maxn];

bool dfs (int u, int d){
	visited[u] = 1;
	bool rz = (ted[com[u]] == 1);
	if (d == 1){
		com[u] = tmp;
		ted[tmp] ++;
	}
	for (auto w : v[u][d]){
		if (!visited[w]){
			rz &= dfs (w, d);
		}
	}
	if (d == 0)
		tpl.PB (u);
	return rz;
}

bool dfs1 (int u){
	visited[u] = 1;
	bool rz = (ted[com[u]] == 1);
	for (auto w : v[u][0])
		if (!visited[w])
			rz &= dfs1 (w);
	for (auto w : v[u][1])
		if (!visited[w])
			rz &= dfs1 (w);
	return rz;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		v[a][0].PB (b);
		v[b][1].PB (a);
	}

	for (int i = 1; i <= n; i++)
		if (!visited[i])
			dfs (i, 0);
	
	memset (visited, 0, sizeof visited);
	for (int i = n - 1; i >= 0; i--){
		int u = tpl[i];
		if (!visited[u]){
			dfs (u, 1);
			tmp ++;
		}
	}
	memset (visited, 0, sizeof visited);
	ll ans = n;
	for (int i = 1; i <= n; i++){
		if (!visited[i]){
			bool k = dfs1 (i);
			ans -= k;
		}
	}
	cout << ans << endl;
}
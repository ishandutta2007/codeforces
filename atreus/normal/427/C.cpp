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
vector <int> tpl, in[maxn], out[maxn];
bool visited[maxn];
int a[maxn];

pii merge (pii p, pii ret){
	if (p.F == ret.F)
		return {p.F, p.S + ret.S};
	return min (p, ret);
}

pii dfs1 (int u){
	visited[u] = 1;
	pair <int, int> ret = {a[u], 1};	
	for (auto w : in[u]){
		if (visited[w])
			continue;
		pair <int, int> p;
		p = dfs1 (w);
		ret = merge (p, ret);
	}
	return ret;
}

void dfs (int u){
	visited[u] = 1;
	for (auto w : out[u])
		if (!visited[w])
			dfs (w);
	tpl.PB (u);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++){
		int j1, j2;
		cin >> j1 >> j2;
		out[j1].PB (j2);
		in[j2].PB (j1);
	}
	for (int i = 1; i <= n; i++)
		if (!visited[i])
			dfs (i);
	memset (visited, 0, sizeof visited);
	ll num = 1, cost = 0;
	for (int i = n - 1; i >= 0; i--){
		if (!visited[tpl[i]]){
			pair <int, int> p = dfs1 (tpl[i]);
			num *= p.S;
			num %= mod;
			cost += p.F;
		}
	}
	cout << cost << " " << num << endl;
}
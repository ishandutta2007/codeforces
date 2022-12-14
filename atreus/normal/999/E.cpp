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
const int maxn = 2e5 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
int n, m, s, tmp = 1, cmp[maxn];
vector <int> out[maxn], in[maxn], v[maxn], tpl;
bool visited[maxn];
pair <int, int> ed[maxn];

void dfs_in (int u) {
	visited[u] = 1;
	cmp[u] = tmp;
	for (auto w : in[u])
		if (!visited[w])
			dfs_in (w);
}

void dfs (int u) {
	visited[u] = 1;
	for (auto w : out[u])
		if (!visited[w])
			dfs (w);
	tpl.PB (u);
}

void scc () {
	for (int i = 1; i <= n; i++)
		if (!visited[i])
			dfs (i);
	memset (visited, 0, sizeof visited);
	for (int i = n - 1; i >= 0; i--) {
		int u = tpl[i];
		if (!visited[u]) {
			dfs_in (u);
			tmp ++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> s;
	for (int i = 1; i <= m; i++) {
		int u, w;
		cin >> u >> w;
		ed[i] = MP (u, w);
		out[u].PB (w);
		in[w].PB (u);
	}
	scc ();
	for (int i = 1; i <= m; i++) {
		int u = ed[i].F, w = ed[i].S;
		u = cmp[u], w = cmp[w];
		if (u != w)
			v[w].PB (u);
	}
	int cnt = 0;
	for (int i = 1; i < tmp; i++) 
		if (v[i].size() == 0)
			cnt ++;
	if (v[cmp[s]].size() == 0)
		cnt --;
	cout << cnt << endl;
}
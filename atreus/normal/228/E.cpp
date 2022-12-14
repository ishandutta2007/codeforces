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
int n, m, tmp = 1, cmp[maxn], ans[maxn];
vector <int> tpl, out[maxn], in[maxn];
bool visited[maxn];

int nott (int x) {
	if (x > n)
		return x - n;
	return x + n;
}

void backdfs (int u) {
	cmp[u] = tmp;
	visited[u] = 1;
	for (auto w : in[u])
		if (!visited[w])
			backdfs (w);
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
	for (int i = tpl.size() - 1; i >= 0; i--) {
		int u = tpl[i];
		if (!visited[u]) {
			backdfs (u);
			tmp ++;
		}
	}
}

void merge (int u, int w) { // (0, 1) or (1, 0)  --> (u or w) and (!u or !w) 
	out[u].PB (nott(w));
	out[w].PB (nott(u));
	out[nott(u)].PB (w);
	out[nott(w)].PB (u);
	in[nott(w)].PB (u);
	in[nott(u)].PB (w);
	in[w].PB (nott(u));
	in[u].PB (nott(w));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, w, isas;
		cin >> u >> w >> isas;
		if (isas == 1) 
			merge (u, nott (w));
		else 
			merge (u, w);
	}
	scc ();
	for (int i = 1; i <= n; i++)
		if (cmp[i] == cmp[nott(i)])
			return cout << "Impossible" << endl, 0;
	int cnt = 0;
	memset (visited, 0, sizeof visited);
	for (auto w : tpl) {
		int u = w - (w > n) * n;
		if (!visited[u]) {
			ans[u] = (w <= n);
		}
	}
	for (int i = 1; i <= n; i++)
		if (ans[i] == 0)
			cnt ++;
	cout << cnt << endl;
	for (int i = 1; i <= n; i++)
		if (ans[i] == 0)
			cout << i << " ";
	cout << endl;
}
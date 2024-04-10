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
vector <int> in[2 * maxn], out[2 * maxn], tpl;
bool visited[2 * maxn], x[maxn];
map <int, int> mp;
int tmp = 1, n, a, b, com[2 * maxn], p[maxn];

void dfs_scc (int u){
	com[u] = tmp;
	visited[u] = 1;
	for (auto w : in[u])
		if (!visited[w])
			dfs_scc (w);
}

void dfs (int u){
	visited[u] = 1;
	for (auto w : out[u])
		if (!visited[w])
			dfs (w);
	tpl.PB (u);
}

void scc (){
	for (int i = 1; i <= 2 * n; i++)
		if (!visited[i])
			dfs (i);

	memset (visited, 0, sizeof visited);
	for (int i = tpl.size() - 1; i >= 0; i--){
		int u = tpl[i];
		if (!visited[u]){
			dfs_scc (u);
			tmp ++;
		}
	}
}

void merge (int u, int w){
	out[u].PB (w);
	in[w].PB (u);
	out[w + n].PB (u + n);
	in[u + n].PB (w + n);
	out[w].PB (u);
	in[u].PB (w);
	out[u + n].PB (w + n);
	in[w + n].PB (u + n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		mp[p[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		if (mp.count (a - p[i])){
			merge (i, mp[a - p[i]]);
		}
		else {
			out[i + n].PB (i);
			in[i].PB (i + n);
		}
		if (mp.count (b - p[i]))
			merge (i, mp[b - p[i]]);
		else {
			out[i].PB (i + n);
			in[i + n].PB (i);
		}
	}
	scc ();
	for (int i = 1; i <= n; i++) {
		if (com[i] == com[i + n])
			return cout << "NO" << endl, 0;
	}
	memset (visited, 0, sizeof visited);
	for (int i = 0; i < tpl.size(); i++) {
		int u = tpl[i];
		if (u > n)
			u -= n;
		visited[u] = 1;
		x[u] = (tpl[i] > n);
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++)
		cout << x[i] << " ";
	cout << endl;
}
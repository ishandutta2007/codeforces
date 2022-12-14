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
vector <int> v[maxn], in[2 * maxn], out[2 * maxn], tpl;
bool visited[2 * maxn], vaz[maxn];
ll tmp = 1, com[2 * maxn], n, m;
pair <ll, ll> p[maxn];
char ans[maxn];

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
	for (int i = 1; i <= 2 * m; i++) {
		if (!visited[i]) {
			dfs (i);
		}
	}
	memset (visited, 0, sizeof visited);
	for (int i = tpl.size() - 1; i >= 0; i--){
		int u = tpl[i];
		if (!visited[u]){
			dfs_scc (u);
			tmp ++;
		}
	}
}

void merge (int u, int w){ // (u or !w) & (!u or w) 
	out[u].PB (w);
	in[w].PB (u);
	out[w + m].PB (u + m);
	in[u + m].PB (w + m);
	out[w].PB (u);
	in[u].PB (w);
	out[u + m].PB (w + m);
	in[w + m].PB (u + m);
}

void merger (int u, int w){ // (u or w) & (!u or !w)
	out[u].PB (w + m);
	in[w + m].PB (u);
	out[w].PB (u + m);
	in[u + m].PB (w);
	out[w + m].PB (u);
	in[u].PB (w + m);
	out[u + m].PB (w);
	in[w].PB (u + m);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> vaz[i];
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		for (int j = 1; j <= x; j++){
			int key;
			cin >> key;
			v[key].PB (i);
		}
	}
	for (int i = 1; i <= n; i++){
//		cout << v[i][0] << " " << v[i][1] << " " << vaz[i] << " " << endl;
		if (vaz[i] == 1) 
			merge (v[i][0], v[i][1]);
		
		else { // (0, 1);
			int u = v[i][0], w = v[i][1];
			merger (u, w);
		}
	}
//	for (int i = 1; i <= m; i++){
//		cout << out[i].size() << " -> ";
//		for (auto w : out[i])
//			cout << w << " ";
//		cout << endl;
//	}
	scc ();
	for (int i = 1; i <= m; i++)
		if (com[i] == com[i + m])
			return cout << "NO" << endl, 0;
	cout << "YES" << endl;
}
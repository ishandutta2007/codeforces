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

/*
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
*/

bool check (int x, int y){
	int a1 = p[x].F, a2 = p[x].S, b1 = p[y].F, b2 = p[y].S;
	if (a2 < a1)
		swap (a1, a2);
	if (b2 < b1)
		swap (b1, b2);
	if (a1 < b1 and b1 < a2 and a2 < b2)
		return 1;
	if (b1 < a1 and a1 < b2 and b2 < a2)
		return 1;
	return 0;
}

int main () {
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> p[i].F >> p[i].S;
	for (int i = 1; i <= m; i++){
		for (int j = i + 1; j <= m; j++){
			if (check (i, j))
				merger (i, j);
		}
	}
	memset (visited, 0, sizeof visited);
	scc ();	
	bool curre = 1;
	for (int i = 1; i <= m; i++){
		if (com[i] == com[i + m])
			curre = 0;
	}
	if (!curre)
		return cout << "Impossible" << endl, 0;
	memset (visited, 0, sizeof visited);
	for (int i = 0; i < tpl.size(); i++) {
		int u = tpl[i];
		if (u > m)
			u -= m;
		if (!visited[u]) {
			visited[u] = 1;
			if (tpl[i] > m)
				ans[u] = 'i';
			else
				ans[u] = 'o';
		}
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i];
	cout << endl;
}
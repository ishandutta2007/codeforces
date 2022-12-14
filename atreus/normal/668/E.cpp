#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 2000 + 10;
const int maxm = 1e6 + 10;

int n, m1, m2;
int cnt, c[maxn], cmp[maxn], candid[maxn];
vector<int> topol, fg[maxn][2], sg[maxn][2];
bool visited[maxn];
bitset<maxn> bs[maxn];
pair<int, int> fe[maxm], se[maxm];

void printanswer(){
	memset(c, -1, sizeof c);
	for (auto idx : topol){
		if (c[cmp[idx]] == -1){
			c[cmp[idx]] = 0;
			c[cmp[idx^1]] = 1;
		}
	}
	for (int i = 0; i < 2 * n; i += 2)
		cout << c[cmp[i]] << " ";
	cout << endl;
}

void dfs(int v, bool w){
	visited[v] = 1;
	for (auto u : sg[v][w])
		if (!visited[u])
			dfs(u, w);
	if (w == 0)
		topol.push_back(v);
	else
		cmp[v] = cnt;
}

bool valid(){
	topol.clear();
	cnt = 0;
	memset(visited, 0, sizeof visited);
	for (int i = 0; i < 2 * n; i++)
		if (!visited[i])
			dfs(i, 0);
	memset(visited, 0, sizeof visited);
	reverse(topol.begin(), topol.end());
	for (auto i : topol)
		if (!visited[i])
			dfs(i, 1), candid[cnt] = i, cnt ++;
	for (int i = 0; i < 2 * n; i += 2)
		if (cmp[i] == cmp[i+1])
			return false;
	for (int v = 0; v < 2 * n; v++)
		for (int u = 0; u < 2 * n; u++)
			bs[v][u] = (cmp[v] == cmp[u]);
	for (int i = 2 * n - 1; i >= 0; i--){
		int v = topol[i];
		for (auto u : sg[v][0])
			bs[v] |= bs[u];
	}
	return true;
}

void add_edge(int v, int u, bool w){
	if (w == 0){
		fg[v][0].push_back(u);
		fg[u][1].push_back(v);
	}
	else{
		sg[v][0].push_back(u);
		sg[u][1].push_back(v);
	}
}

void solve(){
	if (valid() == false)
		return;
	for (int i = 0; i < m1; i++){
		int v = fe[i].first, u = fe[i].second;
		int vp = (v ^ 1), up = (u ^ 1);
		// v -> !v and u -> !u
		bitset<maxn> now = bs[vp];
		if (bs[vp][v] == true or (bs[vp][u] == true and bs[up][v] == true))
			continue;
		if (bs[up][u] == true or (bs[up][v] == true and bs[vp][u] == true))
			continue;
		add_edge(v, vp, 1);
		add_edge(u, up, 1);
		valid();
		printanswer();
		exit(0);
	}
}

int transform(int v){
	bool k = (v < 0);
	v = abs(v);
	return 2 * (v - 1) + k;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m1 >> m2;
	for (int i = 0; i < m1; i++){
		int v, u;
		cin >> v >> u;
		v = transform(v), u = transform(u);
		fe[i] = {v, u};
		add_edge(v ^ 1, u, 0);
		add_edge(u ^ 1, v, 0);
	}
	for (int i = 0; i < m2; i++){
		int v, u;
		cin >> v >> u;
		v = transform(v), u = transform(u);
		se[i] = {v, u};
		add_edge(v ^ 1, u, 1);
		add_edge(u ^ 1, v, 1);
	}
	solve();
	for (int i = 0; i < 2 * n; i++)
		swap(fg[i], sg[i]);
	swap(fe, se);
	swap(m1, m2);
	solve();
	cout << "SIMILAR" << endl;
}
#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int maxn = 1e5 + 10;

int s[maxn], w[maxn], par[maxn];
bool visited[maxn], mark[maxn];
vector<pair<int, int> > t[maxn];
vector<int> numbers;

int a[32][maxn];
int line = 0, col;

bool hasanswer(){
	for (int i = 0; i < line; i++)
		if (a[line][s[i]] == 1)
			for (int j = 0; j <= col; j++)
				a[line][j] ^= a[i][j];
	bool flag = 0;
	for (int i = 0; i < col; i++)
		flag |= a[line][i];
	if (flag == 0 and a[line][col])
		return 0;
	if (flag == 0){
		line --;
		return 1;
	}
	for (int i = 0; i < col; i++)
		if (a[line][i] == 1)
			s[line] = i;
	return 1;
}

int gauss(int n){
	col = numbers.size();
	int ret = 0;
	for (int i = 30; i >= 0; i--){
		if (par[n] & (1 << i)){
			for (int j = 0; j < col; j++){
				int k = numbers[j];
				if (k & (1 << i))
					a[line][j] = 1;
				else
					a[line][j] = 0;
			}
			a[line][col] = 1;
			if (hasanswer())
				line ++;
			else
				ret += (1 << i);
		}
		else{
			for (int j = 0; j < col; j++){
				int k = numbers[j];
				if (k & (1 << i))
					a[line][j] = 1;
				else
					a[line][j] = 0;
			}
			a[line][col] = 0;
			if (hasanswer())
				line ++;
			else
				ret += (1 << i);
		}
	}
	return ret;
}

void add(int x){
	numbers.push_back(x);
}

void dfs(int v){
	visited[v] = 1;
	for (auto edge : t[v]){
		int u = edge.first, idx = edge.second;
		if (!visited[u]){
			mark[idx] = 1;
			par[u] = par[v] ^ w[idx];
			dfs(u);
		}
		else if (!mark[idx]){
			mark[idx] = 1;
			add(par[v] ^ par[u] ^ w[idx]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int v, u;
		cin >> v >> u >> w[i];
		t[v].push_back({u, i});
		t[u].push_back({v, i});
	}
	dfs(1);
	cout << gauss(n) << endl;
}
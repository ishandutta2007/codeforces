#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 2000 + 7;

vector<int> t[maxn];
int c[maxn], sz[maxn], a[maxn], pos[maxn];
int n;
int st[maxn], ft[maxn], Time;

bool insub(int v, int u){
	return st[v] < st[u] and ft[v] >= ft[u];
}

int dfs(int v, int now){
	st[v] = Time ++;
	for (auto u : t[v])
		sz[v] += dfs(u, now + sz[v]);
	a[v] = c[v] + now;
	ft[v] = Time;
	for (int i = 1; i <= n; i++)
		if (insub(v, i) and a[i] >= a[v])
			a[i] ++;
	if (sz[v] < c[v]){
		cout << "NO\n";
		exit(0);
	}
	return sz[v] + 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	int root = 0;
	for (int i = 1; i <= n; i++){
		int p;
		cin >> p >> c[i];
		if (p != 0)
			t[p].push_back(i);
		else
			root = i;
	}
	dfs(root, 1);
	cout << "YES\n";
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
}
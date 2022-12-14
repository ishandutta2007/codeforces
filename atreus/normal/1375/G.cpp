#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef complex<ld> point;
const int maxn = 2e5 + 5;

vector<int> t[maxn];

int dfs(int v, bool h = 0, int par = -1){
	int ret = 0;
	for (auto u : t[v])
		if (u != par)
			ret += dfs(u, h^1, v);
	return ret + h;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++){
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	int x = dfs(1);
	cout << min(x, n-x) - 1 << endl;
}
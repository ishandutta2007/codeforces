#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

vector<int> t[maxn];

int h[maxn], sz[maxn];
vector<int> A;

void dfs(int v, int par = -1){
	sz[v] = 1;
	for (auto u : t[v]){
		if (u == par)
			continue;
		h[u] = h[v] + 1;
		dfs(u, v);
		sz[v] += sz[u];
	}
	A.push_back(sz[v] - h[v] - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++){
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	dfs(1);
	k = n - k;
	sort(A.rbegin(), A.rend());
	ll answer = 0;
	for (int i = 0; i < k; i++)
		answer += A[i];
	cout << answer << endl;
}
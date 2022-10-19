#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

const int MAXN = 100007;
int N, ans[MAXN];
vector<int> G[MAXN];
vector<int> vec;
int64_t S = 0;

int dfs(int u, int p)
{
	vec.push_back(u);
	int cur = 1;
	for (int v : G[u]) if (v != p) {
		cur += dfs(v, u);
	}
	S += min(cur, N - cur);
	return cur;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	assert(N != 1); // why ...
	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	cout << S * 2 << endl;
	for (int i = 0; i < N; ++i) {
		ans[vec[i]] = vec[(i + (N + 1) / 2) % N];
	}
	for (int i = 1; i <= N; ++i) {
		cout << ans[i] << ' ';
	}
}
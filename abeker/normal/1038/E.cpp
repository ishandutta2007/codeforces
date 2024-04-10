#include <bits/stdc++.h>
using namespace std;

int N;
bool edge[5][5];
int deg[5], sum[5];
bool bio[5];
int mn = 1e9;

void load() {
	scanf("%d", &N);
	while (N--) {
		int x, y, val;
		scanf("%d%d%d", &x, &val, &y);
		if (x != y)
			edge[x][y] = edge[y][x] = true;
		deg[x] ^= 1;
		deg[y] ^= 1;
		sum[x] += val;
		sum[y] += val;
		if (x != y)
			mn = min(mn, val);
	}
}

int dfs(int x) {
	bio[x] = true;
	int res = sum[x];
	for (int i = 1; i <= 4; i++)
		if (!bio[i] && edge[x][i])
			res += dfs(i);
	return res;
}

int solve() {
	vector <int> v;
	bool all = true;
	for (int i = 1; i <= 4; i++) {
		all &= deg[i];
		if (!bio[i])
			v.push_back(dfs(i) / 2);
	}

	if (v.size() > 1)
		return *max_element(v.begin(), v.end());
	
	if (all)
		v[0] -= mn;
	
	return v[0];
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}
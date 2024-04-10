#include <bits/stdc++.h>

using namespace std;

int n, m;
bitset<500> to[500][61][2];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v, t;
		cin >> u >> v >> t;
		--u; --v;
		if(!t) to[u][0][0].set(v);
		else to[u][0][1].set(v);
	}
	for(int j = 1; j < 61; j++)
		for(int i = 0; i < n; i++)
			for(int t = 0; t < 2; t++)
				for(int ii = 0; ii < n; ii++)
					if(to[i][j - 1][t][ii])
						to[i][j][t] |= to[ii][j - 1][!t];
	long long len = 0;
	bitset<500> cur = 1;
	int t = 0;
	for(int i = 60; i >= 0; i--) {
		bitset<500> cur1;
		for(int v = 0; v < n; v++)
			if(cur[v])
				cur1 |= to[v][i][t];
		if(cur1 == 0) continue;
		len += 1LL << i;
		cur = cur1;
		t = !t;
	}
	cout << (len > 1e18 ? -1 : len);
}
#include<bits/stdc++.h>

using namespace std;

const int MX = 400, INF = 1000000000;

int e[MX][MX];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		
		u--;
		v--;
		
		e[u][v] = e[v][u] = 1;
	}
	
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < n; j++) {
			e[i][j] ^= e[0][n - 1];
			
			if (e[i][j] == 0) e[i][j] = INF;
		}
	
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
	
	if (e[0][n - 1] == INF) printf("-1\n");
	else printf("%d\n", e[0][n - 1]);
	
	return 0;
}
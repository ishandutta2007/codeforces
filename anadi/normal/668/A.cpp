#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 107;

int n, m, q;
PII tab[N][N];
int out[N][N];

int main(){
	cin >> n >> m >> q;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			tab[i][j] = {i, j};
	
	while(q--){
		int t, x, y;
		scanf("%d", &t);
		
		if(t == 1){
			scanf("%d", &x);
			for(int i = 0; i < m; ++i)
				tab[x][i] = tab[x][i + 1];
			tab[x][m] = tab[x][0];
		}
		else if(t == 2){
			scanf("%d", &y);
			for(int i = 0; i < n; ++i)
				tab[i][y] = tab[i + 1][y];
			tab[n][y] = tab[0][y];
		}
		else{
			int z;
			scanf("%d %d %d", &x, &y, &z);
			out[tab[x][y].st][tab[x][y].nd] = z;
		}
	}
	
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j)
			printf("%d ", out[i][j]);
		puts("");
	}

	return 0;
}
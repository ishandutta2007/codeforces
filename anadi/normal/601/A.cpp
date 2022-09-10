#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 407;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
int d[N];
queue <int> Q;
bool edge[N][N];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		edge[u][v] = edge[v][u] = true;
	}
	
	if(edge[1][n]){
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				edge[i][j] ^= 1;
	}
	
	for(int i = 2; i <= n; ++i)
		d[i] = -1;
	d[1] = 0;
	
	Q.push(1);
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		
		for(int i = 1; i <= n; ++i)
			if(edge[u][i] && d[i] == -1){
				d[i] = d[u] + 1;
				Q.push(i);
			}
	}
	
	printf("%d\n", d[n]);
	return 0;
}
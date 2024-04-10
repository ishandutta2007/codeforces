#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2e5 + 7;
const int T = 3 * N + 9;

const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, q;
int cur[N];

int K = 1;
int tree[T][105];

int x[N], y[N];
vector <int> D[N];
vector <int> U[N];

void change(int p, int a, int b){
	p += K;
	tree[p][a] = b;
	
	while(p > 1){
		p >>= 1;
		for(int j = 1; j <= 100; ++j)
			tree[p][j] = tree[p + p + 1][tree[p + p][j]];
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &cur[i]);
	
	scanf("%d", &q);
	for(int i = 1; i <= q; ++i){
		int a, b; scanf("%d %d", &a, &b);
		D[a].push_back(i);
		U[b].push_back(i);
		
		scanf("%d %d", &x[i], &y[i]);
	}
	
	while(K < q)
		K *= 2;
	--K;
	
	for(int i = 1; i <= 2 * K + 1; ++i)
		for(int j = 1; j <= 100; ++j)
			tree[i][j] = j;
	
	for(int i = 1; i <= n; ++i){
		for(int v: D[i])
			change(v, x[v], y[v]);

		printf("%d ", tree[1][cur[i]]);
		for(int v: U[i])
			change(v, x[v], x[v]);
	}

	return 0;
}
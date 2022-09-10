#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 2007;

int n, m;
bool res[N];
bitset <N> edge[N];

void solve(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j < N; ++j)
			edge[i][j] = false;
	
	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		edge[u][v] = edge[v][u] = true;
	}
	
	bool ok = false;
	for(int i = 1; i <= n; ++i){
		bool s = 0;
		for(int j = 1; j <= n; ++j)
			s ^= edge[i][j];
		
		edge[i][i] = s;
		edge[i][n + 1] = s;
		ok |= s;
	}
	
	if(!ok){
		puts("1");
		for(int i = 1; i <= n; ++i)
			printf("1 ");
		puts("");
		return;
	}
	
	for(int i = 1; i <= n; ++i){
		int nr = -1;
		for(int j = i; j <= n; ++j)
			if(nr == -1 && edge[j][i] == 1)
				nr = j;
		
		if(nr > 0)
			swap(edge[nr], edge[i]);
		for(int j = i + 1; j <= n; ++j)
			if(edge[j][i] == 1)
				edge[j] ^= edge[i];
	}
	
	for(int i = n; i >= 1; --i){
		res[i] = edge[i][n + 1];
		for(int j = i + 1; j <= n; ++j)
			if(edge[i][j])
				res[i] ^= res[j];
	}
	
	puts("2");
	for(int i = 1; i <= n; ++i)
		printf("%d ", res[i] + 1);
}

int main(){
	int tests;
	scanf("%d", &tests);
	
	while(tests--)
		solve();
	return 0;
}
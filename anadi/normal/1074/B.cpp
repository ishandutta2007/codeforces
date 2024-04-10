#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1007;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
bool in[2][N];
vector <int> G[N];
vector <int> color[2];

int ask(char t, int a){
	printf("%c %d\n", t, a);
	fflush(stdout);
	
	int read;
	scanf("%d", &read);
	
	assert(read != -1);
	return read;
}

void answer(int a){
	printf("C %d\n", a);
	fflush(stdout);
}

int best, dist;
void dfs(int u, int p, int d){
	if(in[0][u] && d < dist)
		best = u, dist = d;

	for(int v: G[u])
		if(v != p)
			dfs(v, u, d + 1);
}

void solve(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		G[i].clear();
		in[0][i] = in[1][i] = false;
	}

	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	for(int i = 0; i < 2; ++i){
		color[i].clear();
		int k;
		scanf("%d", &k);
		color[i].resize(k);
		
		for(int j = 0; j < k; ++j){
			scanf("%d", &color[i][j]);
			in[i][color[i][j]] = true;
		}
	}
	
	int nr = ask('B', color[1][0]);
	if(in[0][nr]){
		answer(nr);
		return;
	}
	
	best = -1, dist = N;
	dfs(nr, nr, 0);
	
	nr = ask('A', best);
	if(in[1][nr])
		answer(best);
	else
		answer(-1);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}
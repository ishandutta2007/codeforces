#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int type[N];
bool val[N];
bool poss[N][2];
vector <int> G[N];

bool dfs(int u){
	if(type[u] < 2)
		return val[u];
	
	if(type[u] == 2)
		return val[u] = !dfs(G[u][0]);
	
	bool t1 = dfs(G[u][0]);
	bool t2 = dfs(G[u][1]);
	
	if(type[u] == 3)
		return val[u] = t1 & t2;
	if(type[u] == 4)
		return val[u] = t1 | t2;
	return val[u] = t1 ^ t2;
}

void go(int u){
	if(type[u] < 2)
		return;
	
	int v1 = G[u][0];
	if(type[u] == 2){
		poss[v1][0] = poss[u][1];
		poss[v1][1] = poss[u][0];
		go(v1);
		return;
	}
	
	int v2 = G[u][1];
	bool t1 = val[v1], t2 = val[v2];

	if(type[u] == 3){
		poss[v1][0] = poss[u][0];
		poss[v1][1] = t2 ? poss[u][1] : poss[u][0];

		poss[v2][0] = poss[u][0];
		poss[v2][1] = t1 ? poss[u][1] : poss[u][0];
	}
	
	if(type[u] == 4){
		poss[v1][0] = t2 ? poss[u][1] : poss[u][0];
		poss[v1][1] = poss[u][1];
		
		poss[v2][0] = t1 ? poss[u][1] : poss[u][0];
		poss[v2][1] = poss[u][1];		
	}
	
	if(type[u] == 5){
		poss[v1][0] = t2 ? poss[u][1] : poss[u][0];
		poss[v1][1] = t2 ? poss[u][0] : poss[u][1];

		poss[v2][0] = t1 ? poss[u][1] : poss[u][0];
		poss[v2][1] = t1 ? poss[u][0] : poss[u][1];
	}
	
	go(v1); go(v2);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		char s[5];
		scanf(" %s", s);
		
		int x, y;
		if(s[0] == 'I'){
			scanf("%d", &x);
			type[i] = x;
			val[i] = x;
		}
		else if(s[0] == 'N'){
			scanf("%d", &x);
			G[i].push_back(x);
			type[i] = 2;
		}
		else{
			scanf("%d %d", &x, &y);
			G[i].push_back(x);
			G[i].push_back(y);

			if(s[0] == 'A')
				type[i] = 3;
			else if(s[0] == 'O')
				type[i] = 4;
			else
				type[i] = 5;
		}
	}
	
	dfs(1);
	poss[1][1] = true;
	go(1);
	
	for(int i = 1; i <= n; ++i)
		if(type[i] < 2)
			printf("%d", poss[i][val[i] ^ 1]);
	return 0;
}
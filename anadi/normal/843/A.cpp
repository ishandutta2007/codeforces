#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const int inf = 1e9 + 9;

int n, m;
int cnt = 0;

PII tab[N];
bool vis[N];
vector <int> res[N];

void dfs(int u){
	vis[u] = true;
	res[cnt].push_back(u);
	
	if(!vis[tab[u].nd])
		dfs(tab[u].nd);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &tab[i].st),
		tab[i].nd = i;
	sort(tab + 1, tab + n + 1);
	
	for(int i = 1; i <= n; ++i){
		if(vis[i])	continue;
		++cnt;
		dfs(i);
	}
	
	printf("%d\n", cnt);
	for(int i = 1; i <= cnt; ++i){
		printf("%d ", res[i].size());
		for(int v: res[i])
			printf("%d ", v);
		puts("");
	}

	return 0;
}
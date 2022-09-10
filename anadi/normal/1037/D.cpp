#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int val[N];
bool vis[N];
queue <int> Q;
vector <int> G[N];

bool cmp(int a, int b){
	return val[a] < val[b];
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		val[a] = i;
	}
	
	for(int i = 1; i <= n; ++i)
		sort(G[i].begin(), G[i].end(), cmp);
	
	int cnt = 0;
	queue <int> Q;

	Q.push(1);
	vis[1] = true;
	
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		
		if(val[u] != ++cnt){
			puts("No");
			exit(0);
		}
		
		for(int v: G[u])
			if(!vis[v]){
				vis[v] = true;
				Q.push(v);
			}
	}
	
	puts("Yes");
	return 0;
}
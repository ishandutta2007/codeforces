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

int n, m, k;
int res = n;
int edge[N][2];

int ans[N];
bool ok[N];
int deg[N];
queue <int> Q;
vector <int> G[N];

void go(){
	while(!Q.empty()){
		int u = Q.front();
		Q.pop(); --res;
		
		for(int v: G[u]){
			deg[v]--;
			if(deg[v] < k && ok[v]){
				ok[v] = false;
				Q.push(v);
			}
		}
	}
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= m; ++i){
		scanf("%d %d", &edge[i][0], &edge[i][1]);
		G[edge[i][0]].push_back(edge[i][1]);
		G[edge[i][1]].push_back(edge[i][0]);
	}
	
	res = n;
	for(int i = 1; i <= n; ++i){
		deg[i] = G[i].size();
		if(deg[i] < k)
			Q.push(i);
		else
			ok[i] = true;
	}
	
	go(); ans[m] = res;
	for(int i = m; i > 1; --i){
		int a = edge[i][0], b = edge[i][1];
		G[a].pop_back();
		G[b].pop_back();
		
		if(ok[b] && ok[a]){
			deg[b]--; deg[a]--;
			if(deg[b] < k){
				Q.push(b);
				ok[b] = false;
			}
			
			if(deg[a] < k){
				Q.push(a);
				ok[a] = false;
			}
		}
		
		go();
		ans[i - 1] = res;
	}
	
	for(int i = 1; i <= m; ++i)
		printf("%d\n", ans[i]);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 207;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;
vector <LL> in;

int ans;
int dist[N];
vector <int> G[N];

void check(int root, int forb){
	for(int i = 1; i <= n; ++i)
		dist[i] = -1;	
	dist[root] = 0;

	queue <int> Q;
	for(auto v: G[root])
		if(v != forb && dist[v] == -1){
			dist[v] = 1;
			Q.push(v);
		}
	
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		
		for(auto v: G[u])
			if(dist[v] == -1){
				dist[v] = dist[u] + 1;
				Q.push(v);
			}
	}
	
	if(dist[forb] != -1)
		ans = min(ans, dist[forb] + 1);
}

void solve(int root){
	if(ans == 3)	return;
	for(auto v: G[root])
		check(root, v);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		LL x;
		scanf("%lld", &x);

		if(x > 0)
			in.push_back(x);
	}
	
	if((int)in.size() > 120){
		puts("3");
		exit(0);
	}
	
	n = in.size();
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(i != j && (in[i] & in[j]) > 0)
				G[i + 1].push_back(j + 1);
	ans = N;
	for(int i = 1; i <= n; ++i)
		solve(i);
	
	if(ans == N)
		ans = -1;
	printf("%d\n", ans);
	return 0;
}
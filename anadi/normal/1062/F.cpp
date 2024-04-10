#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 3e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
int ans[N];
int last[N];
int topSort[N];

int deg[N];
int place[N];
vector <int> G[N];

int reach[N];
int secondBest[N];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		
		++deg[v];
		G[u].push_back(v);
	}
	
	queue <int> Q;
	for(int i = 1; i <= n; ++i)
		if(deg[i] == 0)
			Q.push(i);
	
	int cnt = 0;
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		
		place[u] = cnt + 1;
		topSort[++cnt] = u;

		for(int v: G[u]){
			deg[v]--;
			if(deg[v] == 0){
				Q.push(v);
				last[v] = cnt;
			}
			else
				secondBest[v] = cnt;
		}
	}
	
//	for(int i = 1; i <= n; ++i)
//		printf("%d ", topSort[i]);
//	puts("");

	set <PII> S;
	for(int i = n; i >= 1; --i){	
		int u = topSort[i];
		reach[u] = i;
		
		for(int v: G[u])
			if(i == last[v])
				reach[u] = min(reach[u], secondBest[v]);
		
//		printf("%d -> %d %d %d\n", u, last[u], reach[u], secondBest[u]);
		
		if(S.size() == 0 || (*S.begin()).st >= i){
			S.insert({last[u], u});
			continue;
		}
		
		if(S.size() == 1){
			++ans[u];
			S.insert({last[u], u});
			continue;
		}
		
		auto it = S.begin(); ++it;
		if((*it).st < i){
			ans[u] += 2;
			S.insert({last[u], u});
			continue;
		}
		
		int v = (*S.begin()).nd;
		if(reach[v] < i)
			ans[u] += 2;
		else
			ans[u] += 1;
		
		S.insert({last[u], u});
	}

	S.clear();
	for(int i = 1; i <= n; ++i)
		reach[topSort[i]] = 0, secondBest[i] = n + 1;
	
	for(int i = 1; i <= n; ++i){
		int u = topSort[i];
		last[u] = n + 1;

		for(int v: G[u])
			if(place[v] < last[u]){
				secondBest[u] = last[u];
				last[u] = place[v];
			}
			else if(place[v] < secondBest[u])
				secondBest[u] = place[v];
		reach[topSort[last[u]]] = max(reach[topSort[last[u]]], secondBest[u]);
		
		auto it = S.end();
		if(S.size() == 0 || (*(--S.end())).st <= i){
			S.insert({last[u], u});
			continue;
		}
		
		--it;
		if(S.size() == 1){
			++ans[u];
			S.insert({last[u], u});
			continue;
		}
		
		--it;
		if((*it).st > i){
			ans[u] += 2;
			S.insert({last[u], u});
			continue;
		}
		
		++it;
		int v = (*it).nd;
		if(reach[v] > i)
			ans[u] += 2;
		else
			ans[u] += 1;
		
		S.insert({last[u], u});
	}
	
	int res = 0;
	for(int i = 1; i <= n; ++i)
		res += ans[i] < 2;
	
//	for(int i = 1; i <= n; ++i)
//		printf("%d ", ans[i]);
//	puts("");
	
	printf("%d\n", res);
	return 0;
}
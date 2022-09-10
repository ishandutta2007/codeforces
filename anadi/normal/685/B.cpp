#include <bits/stdc++.h>

using namespace std;

typedef double d;
typedef long long int LL;

#define mp make_pair
#define st first
#define nd second
#define PII pair <int, int>

const int mxn = 3e5 + 9;

int n, q;
int p[mxn];
int pod[mxn];
int ans[mxn];
vector <int> V[mxn];

int dfs(int u){
	pod[u] = 1;
	for(int i = 0; i < V[u].size(); ++i)
		pod[u] += dfs(V[u][i]);
		
	int half = (pod[u] + 1) / 2;
	int ktory = -1;
	ans[u] = u;
	
	for(int i = 0; i < V[u].size(); ++i)
		if(pod[V[u][i]] >= half)
			ktory = V[u][i];
	
	if(ktory == -1)
		return pod[u];
	
	ktory = ans[ktory];
	while(pod[ktory] < half)
		ktory = p[ktory];
	ans[u] = ktory;
	return pod[u];
}

int main(){
	scanf("%d %d", &n, &q);
	for(int i = 2; i <= n; ++i){
		int a;
		scanf("%d", &a);
		V[a].push_back(i);
		p[i] = a;
	}
	
	dfs(1);
	while(q--){
		int a;
		scanf("%d", &a);
		printf("%d\n", ans[a]);
	}
	return 0;
}
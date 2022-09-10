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

struct tree{
	int pod = 1;
	tree* node[26];
	
	tree(){
		for(int i = 0; i < 26; ++i)
			node[i] = nullptr;
	}
};

int n;
char in[N];
int val[N];
int pod[N];
tree *T[N];
vector <int> G[N];

void add(tree *cur, int u, int p){
	if(cur -> node[in[u] - 'a'] == nullptr)
		cur -> node[in[u] - 'a'] = new tree();
	cur = cur -> node[in[u] - 'a'];
	
	for(int v: G[u]){
		if(v == p)
			continue;
		add(cur, v, u);
	}
	
	cur -> pod = 1;
	for(int i = 0; i < 26; ++i)
		if(cur -> node[i] != nullptr)
			cur -> pod += cur -> node[i] -> pod;
}

void dfs(int u, int p){
	int best = 0;
	pod[u] = 1;

	for(int v: G[u]){
		if(v == p)
			continue;
		
		dfs(v, u);
		if(pod[best] < pod[v])
			best = v;
		pod[u] += pod[v];
	}
	
	T[u] = new tree();
	if(best == 0){
		val[u] += T[u] -> pod;
		return;
	}
	
	T[u] -> node[in[best] - 'a'] = T[best];
	T[u] -> pod = T[best] -> pod + 1;

	for(int v: G[u]){
		if(v == p || v == best)
			continue;
		
		add(T[u], v, u);
		T[u] -> pod = 1;
		for(int i = 0; i < 26; ++i)
			if(T[u] -> node[i] != nullptr)
				T[u] -> pod += T[u] -> node[i] -> pod;
	}
	
	val[u] += T[u] -> pod;
//	printf("%d -> %d\n", u, T[u] -> pod);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &val[i]);
	scanf("%s", in + 1);
	
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);

		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1, 0);	
	int mx = 0, cnt = 0;
	for(int i = 1; i <= n; ++i)
		if(val[i] > mx){
			mx = val[i];
			cnt = 1;
		}
		else if(val[i] == mx)
			++cnt;
	
	printf("%d\n%d\n", mx, cnt);
	return 0;
}
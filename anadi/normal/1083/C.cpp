#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int LOGN = 18;
const int N = 2e5 + 7;
const int T = 1 << 18;

const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int in[N];
vector <int> G[N];

int jump[N][LOGN];
int pre[N], post[N];

int rv[N];
PII tree[T + T + 7];

inline int fast(){
	int ret = 0;
	char cur = ' ';
	
	while(cur < '0')
		cur = getchar();
	
	while('0' <= cur){
		ret = ret * 10 + cur - '0';
		cur = getchar();
	}
	
	return ret;
}

inline bool anc(int u, int v){
	return pre[u] <= pre[v] && post[v] <= post[u];
}

inline int lca(int u, int v){
	int cur = LOGN;
	while(cur){
		cur--;
		if(!anc(jump[u][cur], v))
			u = jump[u][cur];
	}
	
	if(!anc(u, v))
		u = jump[u][0];
	return u;
}

void dfs(int u){
	static int Time = 0;
	pre[u] = ++Time;
	
	for(int v: G[u])
		dfs(v);
	post[u] = Time;
}

inline PII get(PII p, int v){
	if(p.st == 0)
		return {0, 0};
	
	if(anc(p.st, p.nd))
		swap(p.st, p.nd);
	
	if(anc(p.nd, p.st)){
		if(anc(p.st, v))
			return {p.nd, v};
		
		if(anc(p.nd, v) && anc(v, p.st))
			return p;
		
		if(anc(p.nd, v)){
			if(lca(p.st, v) == p.nd)
				return {p.st, v};
			return {0, 0};
		}

		return {v, p.st};
	}
	
	if(anc(p.st, v))
		return {v, p.nd};
	
	if(anc(p.nd, v))
		return {p.st, v};
	
	if(!anc(v, p.st) && !anc(v, p.nd))
		return {0, 0};
	
	int ret = lca(p.st, p.nd);
	if(!anc(ret, v))
		return {0, 0};
	return p;	
}

inline PII Union(PII p1, PII p2){
	if(p1.st == 0 || p2.st == 0)
		return {0, 0};
//	printf("%d %d i %d -> %d %d\n", p1.st, p1.nd, p2.st, get(p1, p2.st).st, get(p1, p2.st).nd);
	return get(get(p1, p2.st), p2.nd);
}

inline void push(int p, int v){
	p += T;
	tree[p] = {v, v};

	while(p > 1){
		p >>= 1;
		tree[p] = Union(tree[p + p], tree[p + p + 1]);
	}
}

inline int getAns(){
	int cur = 1;
	PII st = tree[T];

	while(cur < T){
		cur += cur;
		PII nxt = Union(st, tree[cur]);
		
		if(nxt.st == 0)
			continue;
		else
			st = nxt, ++cur;
	}
	
	return cur - T;
}

int main(){
	n = fast();
	for(int i = 1; i <= n; ++i)
		rv[i] = fast();

	jump[1][0] = 1;
	for(int i = 2; i <= n; ++i){
		int v = fast();
		jump[i][0] = v;
		G[v].push_back(i);
	}
	
	dfs(1);
	for(int i = 1; i < LOGN; ++i)
		for(int j = 1; j <= n; ++j)
			jump[j][i] = jump[jump[j][i - 1]][i - 1];
	
	for(int i = 1; i <= n; ++i)
		push(rv[i], i);
	
	int quest = fast();
	while(quest--){
		int t = fast();
		if(t == 1){
			int u = fast(), v = fast();
			swap(rv[u], rv[v]);

			push(rv[u], u);
			push(rv[v], v);
		}
		else
			printf("%d\n", getAns());
	}

	return 0;
}
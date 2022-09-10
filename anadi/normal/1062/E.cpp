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
const int T = 1 << 18;

const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, q;
int level[N];
vector <int> G[N];

int rv[N];
int pre[N];

PII pt[T + T + 7];
int tree[T + T + 7];

void dfs(int u){
	static int Place = 1;

	pre[u] = Place;
	rv[Place] = u;
	
	tree[T + Place] = level[u];
	pt[T + u] = {pre[u], -pre[u]};
	++Place;
	
//	printf("%d %d\n", u, pre[u]);
	for(int v: G[u]){
		level[v] = level[u] + 1;
		dfs(v);

		tree[T + Place] = level[u];
		++Place;
	}
}

int ask(int l, int r){
	int ret = N;
	l += T, r += T;
	
	while(l < r){
		if(l & 1)
			ret = min(ret, tree[l]);
		if(!(r & 1))
			ret = min(ret, tree[r]);
		
		l = (l + 1) >> 1;
		r = (r - 1) >> 1;
	}
	
	if(l == r)
		ret = min(ret, tree[l]);	
	return ret;
}

PII query(int l, int r){
	PII ret = {T, T};
	l += T, r += T;
	
	while(l < r){
		if(l & 1)
			ret = {min(ret.st, pt[l].st), min(ret.nd, pt[l].nd)};		

		if(!(r & 1))
			ret = {min(ret.st, pt[r].st), min(ret.nd, pt[r].nd)};		
	
		l = (l + 1) >> 1;
		r = (r - 1) >> 1;
	}
	
	if(l == r)
		ret = {min(ret.st, pt[l].st), min(ret.nd, pt[l].nd)};
	return {ret.st, -ret.nd};
}

PII get(int l, int r, int nr){
	PII r1 = query(l, nr - 1);
	PII r2 = query(nr + 1, r);
	return {min(r1.st, r2.st), max(r1.nd, r2.nd)};
}

int main(){
	scanf("%d %d", &n, &q);
	for(int i = 2; i <= n; ++i){
		int p;
		scanf("%d", &p);
		G[p].push_back(i);
	}
	
	dfs(1);
	for(int i = T - 1; i >= 1; --i){
		pt[i] = {min(pt[i + i].st, pt[i + i + 1].st), min(pt[i + i].nd, pt[i + i + 1].nd)};
		tree[i] = min(tree[i + i], tree[i + i + 1]);
	}
	
	while(q--){
		int l, r;
		scanf("%d %d", &l, &r);
		
		PII t = query(l, r);
		PII q1 = get(l, r, rv[t.st]);
		PII q2 = get(l, r, rv[t.nd]);
		
		int ans1 = ask(q1.st, q1.nd);
		int ans2 = ask(q2.st, q2.nd);
		
		if(ans1 > ans2)
			printf("%d %d\n", rv[t.st], ans1);
		else
			printf("%d %d\n", rv[t.nd], ans2);
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2e5 + 7;
const int T = 6 * N + 9;

const int MX = 1e9 + 7;
const int inf  = 1e9 + 9;
const LL bigInf = 1e18 + 9LL;

int K;
int n, q;
PII y[N];
LL ans[N];
int perm[N];
int tree[T];
bool visited[N];
priority_queue <PII> Q;

inline LL ile(LL val){
	return val * (val - 1LL) / 2LL;
}

void add(int u){
	u += K;
	tree[u]++;
	
	while(u > 1){
		u /= 2;
		tree[u]++;
	}
}

int ask(int from, int to){
	int ret = 0;
	from += K, to += K;
	
	while(from < to){
		if(from & 1)
			ret += tree[from];
		if(!(to & 1))
			ret += tree[to];
		
		from = (from + 1) >> 1;
		to = (to - 1) >> 1;
	}
	
	if(from == to)
		ret += tree[to];
	return ret;
}

int main(){
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &perm[i]),
		Q.push({-i, -1});
	
	for(int i = 1; i <= q; ++i){
		int l, r, d, u;
		scanf("%d %d %d %d", &l, &d, &r, &u);
		y[i] = {d, u};
		ans[i] = ile(l - 1) + ile(d - 1) + ile(n - r) + ile(n - u);
		Q.push({-l, i});
		Q.push({-r - 1, i});
	}

	K = 1;
	while(K < n)
		K *= 2;
	--K;

	while(!Q.empty()){
		int nr = Q.top().nd, val = Q.top().st;
		Q.pop();

		if(nr < 0){
			add(perm[-val]);
			continue;
		}
		
		if(visited[nr])
			ans[nr] -= ile(y[nr].st - 1 - ask(1, y[nr].st - 1)) + ile(n - y[nr].nd - ask(y[nr].nd + 1, n));
		else{
			visited[nr] = true;
			ans[nr] -= ile(ask(1, y[nr].st - 1)) + ile(ask(y[nr].nd + 1, n));
		}
	}
	
	for(int i = 1; i <= q; ++i)
		printf("%lld\n", ile(n) - ans[i]);
	return 0;
}
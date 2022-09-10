#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 20007;
const int T = 1 << 15;

const int P = 1e7 + 19;
const int Q = 1e9 + 7;

const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, k;
int w[N], v[N];
int from[N], to[N];

int q, req;
int dp[20][1007];
vector <int> tree[T + T];

void add(int from, int to, int v){
	from += T, to += T;
	while(from < to){
		if(from & 1)
			tree[from].push_back(v);
		if(!(to & 1))
			tree[to].push_back(v);
		
		from = (from + 1) >> 1;
		to = (to - 1) >> 1;
	}
	
	if(from == to)
		tree[from].push_back(v);
}

void go(int r, int u){	
	for(auto t: tree[u])
		for(int i = k; i >= w[t]; --i)
			dp[r][i] = max(dp[r][i - w[t]] + v[t], dp[r][i]);

	if(u >= T){
		u -= T;
		if(u < 1)
			return;
		if(req < u)
			exit(0);
		
		int res = 0;
		for(int i = k; i >= 1; --i)
			res = (1LL * res * P + dp[r][i])%Q;
		
		printf("%d\n", res);
		return;
	}

/*	printf("%d %d\n", r, u);
	for(int i = 1; i <= k; ++i)
		printf("%d ", dp[r][i]);
	puts("");
*/	
	for(int i = 0; i <= k; ++i)
		dp[r + 1][i] = dp[r][i];

	go(r + 1, u + u);
	for(int i = 0; i <= k; ++i)
		dp[r + 1][i] = dp[r][i];
	go(r + 1, u + u + 1);
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i){
		scanf("%d %d", &v[i], &w[i]);
		from[i] = 1;
	}
	
	scanf("%d", &q);
	for(int i = 1; i <= q; ++i){
		int t;
		scanf("%d", &t);

		if(t == 1){
			++n;
			from[n] = req + 1;
			scanf("%d %d", &v[n], &w[n]);
		}
		
		if(t == 2){
			int c;
			scanf("%d", &c);
			to[c] = req == 0 ? -1 : req;
		}
		
		if(t == 3)
			++req;
	}
	
	for(int i = 1; i <= n; ++i){
		if(to[i] == 0)
			to[i] = req;

		if(from[i] <= to[i])
			add(from[i], to[i], i);
	}
	
/*	for(int i = 1; i < T + T; ++i){
		printf("%d -> ", i);
		for(auto v: tree[i])
			printf("%d ", v);
		puts("");
	}
*/	
	go(0, 1);
	return 0;
}
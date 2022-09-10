#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 5e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m, k;
LL value[N];
pair <LL, PII> edge[N];

int pt[N];
int rep[N];
int res = 0;

int Find(int a){
	if(rep[a] == a)
		return a;
	return rep[a] = Find(rep[a]);
}

bool Union(int a, int b){
	a = Find(a), b = Find(b);
	if(a == b)
		return false;
	
	rep[a] = b;
	return true;
}

void solve(int from, int to){
//	printf("%d :: %d\n", from, to);
	int cnt = n;
	for(int i = from; i <= to; ++i)
		if(Union(edge[i].nd.st, edge[i].nd.nd))
			--cnt;

	res = (res + pt[cnt])%MX;
	for(int i = from; i <= to; ++i)
		rep[edge[i].nd.st] = edge[i].nd.st,
		rep[edge[i].nd.nd] = edge[i].nd.nd;
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n; ++i){
		scanf("%lld", &value[i]);
		rep[i] = i;
	}
	
	pt[0] = 1;
	for(int i = 1; i < N; ++i)
		pt[i] = (pt[i - 1] + pt[i - 1])%MX;
	
	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		edge[i] = {value[u] ^ value[v], {u, v}};
	}
	
	LL ok = pt[k];
	sort(edge + 1, edge + m + 1);
	
	for(int i = 1; i <= m; ++i){
		int t = i;
		while(t < m && edge[t + 1].st == edge[t].st)
			++t;
		solve(i, t);
		i = t;
		--ok;
	}
	
	res = (res + 1LL * pt[n] * (ok%MX))%MX;
	printf("%d\n", res);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n, m;
LL value[N];

vector <int> G[N];
map <vector <int>, LL> M;

LL nwd(LL a, LL b){
	if(!b)	return a;
	return nwd(b, a % b);
}

void solve(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%lld", &value[i]);
		G[i].clear();
	}
	
	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);		
		G[v].push_back(u);
	}
	
	M.clear();
	for(int i = 1; i <= n; ++i){
		if(G[i].size() == 0)
			continue;

		sort(G[i].begin(), G[i].end());
		M[G[i]] += value[i];
	}
	
	LL ans = 0;
	for(auto v: M)
		ans = nwd(ans, v.nd);
	printf("%lld\n", ans);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}
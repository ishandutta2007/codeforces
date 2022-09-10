#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 3007;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
vector <int> G[N];

LL ask(int a){
	if(a == 0)
		return INF;
	
	LL ret = 0LL;
	int need = a - G[1].size();

	for(int i = 2; i <= m; ++i){
		int t = max((int)G[i].size() - a + 1, 0);
		for(int j = 0; j < t; ++j)
			ret += G[i][j];
		need -= t;
	}
	
	if(need <= 0)
		return ret;
	
	vector <int> cost;
	for(int i = 2; i <= m; ++i){
		int t = max((int)G[i].size() - a + 1, 0);
		for(int j = t; j < (int)G[i].size(); ++j)
			cost.push_back(G[i][j]);
	}
	
	sort(cost.begin(), cost.end());
	for(int j = 0; j < need; ++j)
		ret += cost[j];
	return ret;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i){
		int t, c;
		scanf("%d %d", &t, &c);
		G[t].push_back(c);
	}
	
	for(int i = 1; i <= m; ++i)
		sort(G[i].begin(), G[i].end());
	
	LL res = INF;
	for(int i = G[1].size(); i <= n; ++i)
		res = min(res, ask(i));
	printf("%lld\n", res);
	return 0;
}
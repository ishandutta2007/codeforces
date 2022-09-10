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

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const int inf  = 1e9 + 9;
const LL bigInf = 1e18 + 9LL;

int n, m, k;

LL pref[N];
LL curBest[N];
vector <PII> In[N];
vector <PII> Out[N];

int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= m; ++i){
		int day, u, v, c;
		scanf("%d %d %d %d", &day, &u, &v, &c);
		if(u == 0)
			Out[day].pb({v, c});
		else
			In[day].pb({u, c});
	}
	
	for(int i = 1; i <= n; ++i)
		curBest[i] = inf;
	LL curCost = 1LL * n * inf;

	for(int i = 1; i <= 1e6; ++i){
		for(PII v: In[i])
			if(curBest[v.st] > v.nd)
				curCost -= curBest[v.st] - v.nd,
				curBest[v.st] = v.nd;
		pref[i] = curCost;
	}
	
	for(int i = 1; i <= n; ++i)
		curBest[i] = inf;
	curCost = 1LL * n * inf;
	
	LL res = bigInf;
	for(int i = 1e6; i > k + 1; --i){
		for(PII v: Out[i])
			if(curBest[v.st] > v.nd)
				curCost -= curBest[v.st] - v.nd,
				curBest[v.st] = v.nd;
		res = min(res, curCost + pref[i - k - 1]);
	}
	
	if(res > 2LL * n * N)
		res = -1;
	printf("%lld\n", res);
	return 0;
}
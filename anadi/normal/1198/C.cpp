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
int u[N], v[N];

bool pick[N];
bool block[N];
vector <int> G[N];

void clear(){
	for(int i = 1; i <= n; ++i)
		G[i].clear(), pick[i] = false;
	for(int i = 1; i <= m; ++i)
		block[i] = false;
}

void solve(){
	scanf("%d %d", &n, &m);
	n = 3 * n;
	clear();
	
	for(int i = 1; i <= m; ++i){
		scanf("%d %d", &u[i], &v[i]);		
		G[u[i]].push_back(i);
		G[v[i]].push_back(i);
	}
	
	vector <int> ans;
	for(int i = 1; i <= m; ++i){
		if(block[i])	
			continue;
		
		pick[u[i]] = pick[v[i]] = true;
		for(auto t: G[u[i]])
			block[t] = true;
		for(auto t: G[v[i]])
			block[t] = true;
		ans.push_back(i);
	}
	
	int sz = n / 3;
	while((int)ans.size() > sz)
		ans.pop_back();
	
	if((int)ans.size() < sz){
		ans.clear();
		for(int i = 1; i <= n; ++i)
			if(!pick[i] && (int)ans.size() < sz)
				ans.push_back(i);
		puts("IndSet");
	}
	else
		puts("Matching");
	
	for(auto id: ans)
		printf("%d ", id);
	puts("");
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}
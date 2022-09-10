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

int n;
vector <int> G[N];
vector <PII> sons[N];

int s[N], deep[N];
vector <int> ord, ans;

void calcDP(int u){
	for(auto v: G[u]){
		calcDP(v);
		s[u] += s[v] + deep[v] + 1;
		sons[u].push_back({deep[v], v});
	}
	
	sort(sons[u].begin(), sons[u].end());
	if(sons[u].size()){
		s[u] -= sons[u].back().st + 1;
		deep[u] = sons[u].back().st + 1;
	}
}

void getAnswer(int u){
	int last = 0;
	ord.push_back(u);

	for(auto v: sons[u]){
		getAnswer(v.nd);
		while(last--)
			ans.push_back(v.nd);
		last = v.st + 1;
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int p;
		scanf("%d", &p);
		G[p].push_back(i);
	}
	
	calcDP(0);
	getAnswer(0);
	
	for(auto v: ord)
		printf("%d ", v);
	puts("");
	
	printf("%d\n", (int)ans.size());
	for(auto v: ans)
		printf("%d ", v);
	puts("");
	return 0;
}
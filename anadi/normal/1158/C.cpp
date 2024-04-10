#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;
int nxt[N];
set <int> S;

int rv[N];
int deg[N];
vector <int> G[N];

void clear(){
	S.clear();
	for(int i = 1; i <= n; ++i)
		deg[i] = 0, G[i].clear();
}

void solve(){
	scanf("%d", &n); clear();
	for(int i = 1; i <= n; ++i){
		scanf("%d", &nxt[i]);
		if(1 <= nxt[i] && nxt[i] <= n){
			G[i].push_back(nxt[i]);
			++deg[nxt[i]];
		}
	}
	
	deque <PII> D;
	for(int i = 1; i <= n; ++i){
		if(nxt[i] == -1)
			continue;
		
		while(D.size() && D.back().st <= i)
			D.pop_back();
		
		if(D.size() && D.back().st < nxt[i]){
			puts("-1");
			return;
		}
		
		D.push_back({nxt[i], i});
	}
	
	while(D.size())
		D.pop_back();
	
	for(int i = 1; i <= n; ++i){
		while(D.size() && D.back().st <= i)
			D.pop_back();
		
		if(D.size()){
			++deg[D.back().nd];
			G[i].push_back(D.back().nd);
		}
		
		if(nxt[i] != -1)
			D.push_back({nxt[i], i});
	}
	
	queue <int> Q;
	vector <int> ans;
	
	for(int i = 1; i <= n; ++i)
		if(deg[i] == 0)
			Q.push(i);
	
	while(!Q.empty()){
		int u = Q.front();
		ans.push_back(u);
		Q.pop();
		
		for(int v: G[u]){
			deg[v]--;
			if(deg[v] == 0)
				Q.push(v);
		}
	}
	
	if((int)ans.size() < n)
		puts("-1");
	else{
		for(int i = 0; i < (int)ans.size(); ++i)
			rv[ans[i]] = i + 1;
		for(int i = 1; i <= n; ++i)
			printf("%d ", rv[i]);
		puts("");
	}
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}
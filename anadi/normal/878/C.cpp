#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;

int n, k;
int rep[N];
int roz[N];
set <PII> S;
int mn[N][12], mx[N][12];

int Find(int a){
	if(rep[a] == a)
		return a;
	return rep[a] = Find(rep[a]);
}

void Union(int u, int v){
	if(roz[u] < roz[v])
		swap(u, v);

	S.erase({mn[u][1], u});
	S.erase({mn[v][1], v});
	
	rep[v] = u;
	roz[u] += roz[v];

	for(int i = 1; i <= k; ++i){
		mn[u][i] = min(mn[u][i], mn[v][i]);
		mx[u][i] = max(mx[u][i], mx[v][i]);
	}
	
	S.insert({mn[u][1], u});
}

bool check(int u, int v){
	if(mn[u][1] > mn[v][1])
		swap(u, v);

	for(int i = 1; i <= k; ++i)
		if(mx[u][i] > mn[v][i]){
			Union(u, v);
			return true;
		}
	
	return false;
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i){
		rep[i] = i;
		roz[i] = 1;
		
		for(int j = 1; j <= k; ++j){
			scanf("%d", &mn[i][j]);
			mx[i][j] = mn[i][j];
		}
		
		S.insert({mn[i][1], i});
		auto it = S.find({mn[i][1], i});		

		while(it != S.begin()){
			auto it2 = it; --it2;
			if(!check((*it).nd, (*it2).nd))
				break;
			it = S.find({mn[Find(i)][1], Find(i)});
		}
		
		while(true){
			auto it2 = it; ++it2;
			if(it2 == S.end() || !check((*it).nd, (*it2).nd))
				break;
			it = S.find({mn[Find(i)][1], Find(i)});
		}
		
		it = S.end();
		--it;
		
		printf("%d\n", roz[Find((*it).nd)]);
	}

	return 0;
}
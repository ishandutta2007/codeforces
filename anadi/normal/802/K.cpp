#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define PII pair <int, int>

const int N = 1e5 + 7;

int n, k;
vector <pair <int, int> > G[N];

PII dfs(int u, int p){
	PII ret = {0, 0};
	vector <PII> V;
	for(PII v: G[u])
		if(v.st != p){
			PII son = dfs(v.first, u);
			son.st += v.second;
			son.nd += v.second;
			V.push_back(son);
		}
	
	sort(V.begin(), V.end());
	int sum = 0;
	for(int i = V.size() - 1; i >= max(0, (int)V.size() - k); --i)
		sum += V[i].st;
	for(int i = V.size() - 1; i >= 0; --i)
		if(i + k >= V.size())
			ret.nd = max(ret.nd, sum - V[i].st + V[i].nd);
		else
			ret.nd = max(ret.nd, sum - V[V.size() - k].st + V[i].nd);
	
	if(V.size() >= k)
		sum -= V[V.size() - k].st;
	ret.st = sum;
	return ret;
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i < n; ++i){
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		G[u].push_back({v, c});
		G[v].push_back({u, c});
	}
	
	PII res = dfs(0, 0);
	printf("%d\n", max(res.first, res.second));
	return 0;
}
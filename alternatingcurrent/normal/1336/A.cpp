#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n, k;
vector<int> v[200200];
int sz[200200];
int dist[200200];
long long val[200200];

void dfs(int now, int par){
	sz[now] = 1;
	rep(i, v[now].size()) if(v[now][i] != par){
		dist[v[now][i]] = dist[now] + 1;
		dfs(v[now][i], now);
		sz[now] += sz[v[now][i]]; 
	}
	val[now] = dist[now] - sz[now] + 1;
}

int main(){
	scanf("%d%d", &n, &k);
	rep(i, n-1){
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(0, -1);
	sort(val, val + n);
	reverse(val, val + n);
	long long sum = 0;
	rep(i, k) sum += val[i];
	cout << sum << endl; 
	return 0;
}
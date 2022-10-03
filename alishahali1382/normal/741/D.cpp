#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
const int MAXN = 500010;

int n, m, k, u, v, x, y, t, a, b;
int par[MAXN], h[MAXN];
char ch[MAXN];
int X[MAXN];
int ans[MAXN];
unordered_map<int, int> mp[MAXN];

void merge(int a, int b){
	if (mp[a].size()<mp[b].size()){
		mp[a].swap(mp[b]);
		swap(X[a], X[b]);
	}
	ans[a]=max(ans[a], ans[b]);
	for (auto p:mp[b]){
		int tmp=p.first^X[a]^X[b];
		if (mp[a].count(tmp)) ans[a]=max(ans[a], mp[a][tmp] + p.second - 2*h[a]);
		for (int i=0; i<26; i++){
			tmp=p.first^X[a]^X[b]^(1<<i);
			if (mp[a].count(tmp)) ans[a]=max(ans[a], mp[a][tmp] + p.second - 2*h[a]);
		}
	}
	for (auto p:mp[b]){
		int tmp=p.first^X[b]^X[a];
		mp[a][tmp]=max(mp[a][tmp], p.second);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	mp[1][0]=0;
	for (int i=2; i<=n; i++) cin>>par[i]>>ch[i], h[i]=h[par[i]]+1, mp[i][0]=h[i];
	for (int i=n; i>1; i--){
		X[i]^=(1<<(ch[i]-'a'));
		merge(par[i], i);
	}
	for (int i=1; i<=n; i++) cout<<ans[i]<<' ';
	
	return 0;
}
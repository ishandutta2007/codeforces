#include<bits/stdc++.h>
#define N 300100
using namespace std;
vector<int> g[N];
int s[N];
int main(){
	int n,x,y;
	scanf("%d",&n);
	multiset<int> a;
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
		a.insert(s[i]);
	}
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int ans=1e9+100;
	for(int i=1;i<=n;i++){
		int tmp=s[i];
		a.erase(a.find(s[i]));
		for(int j=0;j<g[i].size();j++){
			int v=g[i][j];
			tmp=max(tmp,s[v]+1);
			a.erase(a.find(s[v]));
		}
		if(!a.empty()) tmp=max(tmp,2+*a.rbegin());
		a.insert(s[i]);
		for(int j=0;j<g[i].size();j++){
			int v=g[i][j];
			a.insert(s[v]);
		}
		ans=min(ans,tmp);
	}
	printf("%d\n",ans);
	return 0;
}
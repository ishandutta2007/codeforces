#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
 
int T;
int n,m,id[N];
ll c[N];
vector<int>g[N];

bool cmp(int x,int y){
	if(x>n||y>n){
		cout<<x<<" "<<y<<endl;
//		for(int i=1;i<=n;++i)cout<<id[i]<<" ";
//		cout<<endl;
		exit(0);
	}
	if(g[x].size()!=g[y].size())return g[x].size()<g[y].size();
	for(int i=0;i<g[x].size();++i)
	if(g[x][i]!=g[y][i]){
		return g[x][i]<g[y][i];
	}
	return 0;
}

bool eq(int x,int y){
	if(g[x].size()!=g[y].size())return 0;
	for(int i=0;i<g[x].size();++i)
	if(g[x][i]!=g[y][i]){
		return 0;
	}
	return 1;
}
 
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%lld",&c[i]);
		for(int i=1;i<=n;++i)g[i].clear();
		for(int i=1,x,y;i<=m;++i){
			scanf("%d%d",&x,&y);
			g[y].push_back(x);
		}
		for(int i=1;i<=n;++i)id[i]=i;
		for(int i=1;i<=n;++i)sort(g[i].begin(),g[i].end());
		sort(id+1,id+n+1,cmp);
		ll ans=0;
		for(int i=1,r=1;i<=n;i=++r){
			while(r<n&&eq(id[r],id[r+1]))r++;
			ll res=0;
			for(int j=i;j<=r;++j)
			if(g[id[j]].size()){
				res+=c[id[j]];
			}
			ans=__gcd(ans,res);
		}
		printf("%lld\n",ans);
	}
}
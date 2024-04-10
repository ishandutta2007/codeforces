#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n,d[100005];
vector<int> v[100005];
void dfs(int x,int y){
	d[x]=d[y]+1;
	for(int i=0;i<v[x].size();++i)if(v[x][i]!=y)dfs(v[x][i],x);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)d[i]=0,v[i].clear();
		for(int i=1;i<n;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			v[x].pb(y),v[y].pb(x);
		}
		dfs(1,0);
		for(int i=1;i<=n;++i){
			if(d[i]&1)d[i]=v[i].size();
			else d[i]=-((int)v[i].size());
		}
		for(int i=1;i<n;++i)printf("%d ",d[i]);
		printf("%d\n",d[n]);
	}
    return 0;
}
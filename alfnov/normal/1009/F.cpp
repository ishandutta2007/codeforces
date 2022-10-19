#include<bits/stdc++.h>
using namespace std;
vector<int>g[1000005];
int dep[1000005],md[1000005],zz[1000005];
void dfs1(int x,int la){
	md[x]=dep[x],zz[x]=-1;
	for(auto cu:g[x]){
		if(cu==la)continue;
		dep[cu]=dep[x]+1;
		dfs1(cu,x);
		if(md[x]<md[cu]){
			md[x]=md[cu];
			zz[x]=cu;
		}
	}
}
int bg[1000005],tot=0;
int cc[1000005];
int ans[1000005];
void dfs2(int x,int la){
	bg[x]=++tot;
	if(zz[x]==-1){
		++cc[bg[x]];
		ans[x]=0;
		return;
	}
	int w=zz[x];
	dfs2(w,x);
	ans[x]=ans[w]+1;
	if(ans[x]==1)ans[x]=0;
	++cc[bg[x]];
	for(auto cu:g[x]){
		if(cu==la||cu==w)continue;
		dfs2(cu,x);
		int mm=md[cu]-dep[cu];
		for(int i=0;i<=mm;++i){
			cc[bg[x]+i+1]+=cc[bg[cu]+i];
			if(cc[bg[x]+i+1]>cc[bg[x]+ans[x]]){
				ans[x]=i+1;
			}else if(cc[bg[x]+i+1]==cc[bg[x]+ans[x]]){
				if(ans[x]>i+1)ans[x]=i+1;
			}
		}
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;++i)printf("%d\n",ans[i]);
	return 0;
}
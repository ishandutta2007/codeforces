#include<bits/stdc++.h>
using namespace std;
vector<int>g[300005];
int dep[300005],f[21][300005];
int l[300005];
void dfs(int x,int la){
	dep[x]=1;
	for(auto cu:g[x]){
		if(cu==la)continue;
		dfs(cu,x);
		dep[x]=max(dep[x],dep[cu]+1);
	}
	for(int i=2;i<=19;++i){
		int gs=0;
		for(auto cu:g[x]){
			if(cu==la)continue;
			l[++gs]=f[i-1][cu];
		}
		sort(l+1,l+gs+1);
		for(int j=gs;j>=1;--j){
			if(l[j]>=gs-j+1)f[i][x]=max(f[i][x],gs-j+1);
		}
	}
}
void dfs2(int x,int la){
	for(auto cu:g[x]){
		if(cu==la)continue;
		dfs2(cu,x);
	}
	for(int i=1;i<=19;++i){
		for(auto cu:g[x]){
			if(cu==la)continue;
			f[i][x]=max(f[i][x],f[i][cu]);
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
	for(int i=1;i<=n;++i)f[1][i]=n;
	dfs(1,0);
	dfs2(1,0);
	long long ans=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=19;++j){
			if(f[j][i]<=1)continue;
			ans+=1ll*j*(f[j][i]-max(1,f[j+1][i]));
		}
	}
	for(int i=1;i<=n;++i)ans+=dep[i];
	cout<<ans<<endl;
	return 0;
}
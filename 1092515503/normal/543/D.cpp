#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,f[200100];
vector<int>v[200100],pre[200100],suf[200100];
void dfs1(int x){
	f[x]=1;
	for(auto y:v[x])dfs1(y),f[x]=1ll*f[x]*(f[y]+1)%mod;
	if(v[x].empty())return;
	pre[x].resize(v[x].size()),suf[x].resize(v[x].size());
	pre[x][0]=1;for(int i=1;i<v[x].size();i++)pre[x][i]=1ll*pre[x][i-1]*(f[v[x][i-1]]+1)%mod;
	suf[x].back()=1;for(int i=(int)v[x].size()-2;i>=0;i--)suf[x][i]=1ll*suf[x][i+1]*(f[v[x][i+1]]+1)%mod; 
}
void dfs2(int x,int qwq=1){
	for(int i=0;i<v[x].size();i++){
		int y=v[x][i];
		int tmp=1ll*pre[x][i]*suf[x][i]%mod*qwq%mod;
		f[y]=1ll*f[y]*(tmp+1)%mod;
		dfs2(y,tmp+1);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=2,x;i<=n;i++)scanf("%d",&x),v[x].push_back(i);
	dfs1(1),dfs2(1);
	for(int i=1;i<=n;i++)printf("%d ",f[i]);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,msk[500100],fa[500100],son[500100],sz[500100],dep[500100],buc[1<<22],res[500100],ans;
char s[10];
vector<int>v[500100];
void dfs1(int x){
	sz[x]=1;
	for(auto y:v[x]){
		dep[y]=dep[x]+1,dfs1(y),sz[x]+=sz[y];
		if(sz[son[x]]<sz[y])son[x]=y;
	}
}
void dfsread(int x){
	if(buc[msk[x]]!=-1)ans=max(ans,dep[x]+buc[msk[x]]);
	for(int i=0;i<22;i++)if(buc[msk[x]^(1<<i)]!=-1)ans=max(ans,dep[x]+buc[msk[x]^(1<<i)]);
	for(auto y:v[x])dfsread(y);
}
void dfswrite(int x){
	buc[msk[x]]=max(buc[msk[x]],dep[x]);
	for(auto y:v[x])dfswrite(y);
}
void dfserase(int x){
	buc[msk[x]]=-1;
	for(auto y:v[x])dfserase(y);
}
void dsuontree(int x){
	for(auto y:v[x])if(y!=son[x])dsuontree(y),dfserase(y);
	if(son[x])dsuontree(son[x]);
	ans=0;
	buc[msk[x]]=max(buc[msk[x]],dep[x]);
	if(buc[msk[x]]!=-1)ans=max(ans,dep[x]+buc[msk[x]]);
	for(int i=0;i<22;i++)if(buc[msk[x]^(1<<i)]!=-1)ans=max(ans,dep[x]+buc[msk[x]^(1<<i)]);
	for(auto y:v[x])if(y!=son[x])dfsread(y),dfswrite(y);
	res[x]=ans-2*dep[x];
	for(auto y:v[x])res[x]=max(res[x],res[y]);
}
int main(){
	scanf("%d",&n),memset(buc,-1,sizeof(buc));
	for(int i=2;i<=n;i++)scanf("%d%s",&fa[i],s),msk[i]=msk[fa[i]]^(1<<(s[0]-'a')),v[fa[i]].push_back(i);
	dfs1(1);
	dsuontree(1);
	for(int i=1;i<=n;i++)printf("%d ",res[i]);
	return 0;
}
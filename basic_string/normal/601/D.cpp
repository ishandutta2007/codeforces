#include<bits/stdc++.h>
using namespace std;
const int N=3e5+3;
int c[N][29],sz[N],a[N],ans,cnt;
char s[N];
basic_string<int>g[N];
void mg(int x,int y){
	for(int i=0;i<26;++i)if(c[x][i]){
		if(c[y][i])mg(c[x][i],c[y][i]);
	}else if(c[y][i])c[x][i]=c[y][i];
	sz[x]=1;
	for(int i=0;i<26;++i)sz[x]+=sz[c[x][i]];
}
void dfs(int x,int y){
	sz[x]=1;
	for(int i:g[x])if(i!=y){
		dfs(i,x);
		int o=s[i]-'a';
		if(!c[x][o])c[x][o]=i;
		else mg(c[x][o],i);
	}
	for(int i=0;i<26;++i)sz[x]+=sz[c[x][i]];
	int o=a[x]+sz[x];
	if(o>ans)ans=o,cnt=1;
	else if(o==ans)++cnt;
}
int main(){
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	scanf("%s",s+1);
	for(i=1;i<n;++i)scanf("%d%d",&j,&k),g[j]+=k,g[k]+=j;
	dfs(1,0),cout<<ans<<'\n'<<cnt;
	return 0;
}
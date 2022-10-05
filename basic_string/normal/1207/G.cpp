#include<bits/stdc++.h>
using namespace std;
const int N=4e5+3;
char o[N],s[N];
basic_string<int>e[N],g[N];
vector<pair<int,int>>qr[N];
int c[N][26],f[N],ans[N],lp[N],rp[N],id,t[N];
queue<int>q;
void dfs(int x){
	lp[x]=++id;
	for(int i:g[x])dfs(i);
	rp[x]=id;
}
void add(int x,int y){for(;x<=id;x+=x&-x)t[x]+=y;}
int sum(int x){int r=0;for(;x;x-=x&-x)r+=t[x];return r;}
void wk(int x,int y){
	add(lp[x],1);
	for(auto o:qr[y])ans[o.second]=sum(rp[o.first])-sum(lp[o.first]-1);
	for(int i:e[y])wk(c[x][o[i]-'a'],i);
	add(lp[x],-1);
}
int main(){
	int n,m,i,j,k,l,u,x,id=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&j);
		if(j==1)scanf(" %c",o+i),e[0]+=i;
		else scanf("%d %c",&k,o+i),e[k]+=i;
	}
	scanf("%d",&m);
	for(i=1;i<=m;++i){
		scanf("%d%s",&u,s+1),x=0,l=strlen(s+1);
		for(j=1;j<=l;++j){
			k=s[j]-'a';
			if(!c[x][k])c[x][k]=++id;
			x=c[x][k];
		}
		qr[u].push_back({x,i});
	}
	for(i=0;i<26;++i)if(c[0][i])q.push(c[0][i]);
	while(q.size()){
		i=q.front(),q.pop(),k=f[i];
		for(j=0;j<26;++j)if(c[i][j])q.push(c[i][j]),f[c[i][j]]=c[k][j];
		else c[i][j]=c[k][j];
	}
	for(i=1;i<=id;++i)g[f[i]]+=i;
	dfs(0),wk(0,0);
	for(i=1;i<=m;++i)printf("%d\n",ans[i]);
	return 0;
}
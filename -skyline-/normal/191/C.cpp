#include<bits/stdc++.h>
#define pb    push_back
#define mp    make_pair
#define ll    long long
#define orz   1000000007
using namespace std;
int n,k,x[100005],y[100005],f[100005][20],id[100005],s[100005],d[100005];
vector<int> v[100005],e[100005];
void dfs(int x,int y){
	d[x]=d[y]+1,f[x][0]=y;
	for(int i=0;i<17;++i)f[x][i+1]=f[f[x][i]][i];
	for(int i=0;i<v[x].size();++i){
		if(v[x][i]==y)id[e[x][i]]=x;
		else dfs(v[x][i],x);
	}
}
int lca(int x,int y){
	if(d[x]<d[y])swap(x,y);
	for(int i=17;i>=0;--i)if(d[f[x][i]]>=d[y])x=f[x][i];
	if(x==y) return x;
	for(int i=17;i>=0;--i)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
void go(int x,int y){
	for(int i=0;i<v[x].size();++i)if(v[x][i]!=y)go(v[x][i],x),s[x]+=s[v[x][i]];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		scanf("%d%d",x+i,y+i);
		v[x[i]].pb(y[i]),v[y[i]].pb(x[i]);
		e[x[i]].pb(i),e[y[i]].pb(i);
	}
	dfs(1,0);
	scanf("%d",&k);
	while(k--){
		int x,y,z;
		scanf("%d%d",&x,&y);
		z=lca(x,y);
		++s[x],++s[y],s[z]-=2;
	}
	go(1,0);
	for(int i=1;i<n-1;++i)printf("%d ",s[id[i]]);
	printf("%d\n",s[id[n-1]]);
	return 0;
}
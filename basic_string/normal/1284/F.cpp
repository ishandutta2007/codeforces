#include<bits/stdc++.h>
using namespace std;
const int N=250009;
basic_string<int>e[N],g[N];
int p[N][21],f[N],l[N],r[N],id;
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
void dfs(int x,int y){
	f[x]=x,p[x][0]=y,l[x]=++id;
	for(int i=0;p[x][i];++i)p[x][i+1]=p[p[x][i]][i];
	for(int i:g[x])if(i!=y)dfs(i,x);
	r[x]=id;
}
bool in(int x,int y){return!x||l[x]<=l[y]&&l[y]<=r[x];}
void get(int x,int y){
	for(int i:e[x])if(i!=y)get(i,x);
	if(y){
		int i=gf(x),j;
		if(in(i,y)){
			for(i=y,j=20;~j;--j)if(!in(gf(p[i][j]),x))i=p[i][j];
			i=gf(i);
		}
		f[i]=j=p[i][0],cout<<i<<' '<<j<<' '<<x<<' '<<y<<'\n';
	}
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,i,j,k;
	for(cin>>n,i=1;i<n;++i)cin>>j>>k,g[j]+=k,g[k]+=j;
	for(i=1;i<n;++i)cin>>j>>k,e[j]+=k,e[k]+=j;
	cout<<n-1<<'\n',dfs(1,0),get(1,0);
	return 0;
}
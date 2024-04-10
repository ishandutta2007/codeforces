#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
basic_string<int>g[N];
int a[N],f[N][2],ans;
void dfs(int x,int y){
	if(a[x]==2)f[x][0]=N,f[x][1]=0;
	else if(a[x]==1)f[x][0]=0,f[x][1]=N;
	else f[x][0]=f[x][1]=0;
	int j,k,l;
	for(int i:g[x])if(i^y){
		dfs(i,x);
		for(j=0,l=N;j<2;++j)for(k=0;k<2;++k)l=min(l,f[x][j]+f[i][k]+(j^k));
		ans=max(ans,l);
		for(j=0;j<2;++j)f[x][j]=max(f[x][j],min(f[i][0]+j,f[i][1]+1-j));
	}
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,n,i,j,k;
	for(cin>>T;T--;){
		for(i=1,cin>>n;i<=n;++i)cin>>a[i],g[i]={};
		for(i=1;i<n;++i)cin>>j>>k,g[j]+=k,g[k]+=j;
		ans=0,dfs(1,0),cout<<(ans+3)/2<<'\n';
	}
	return 0;
}
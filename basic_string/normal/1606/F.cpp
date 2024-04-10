#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
basic_string<int>g[N],qr[N],f[N];
int a[N],d[N],ans[N];
struct Q{
	int v,k;
}o[N];
void dfs1(int x,int y){
	a[x]=-1,d[x]=d[y]+1;
	for(int i:g[x])if(i^y)dfs1(i,x),++a[x];
}
void dp(int x,int y){
	if(a[x]<0){
		return;
	}
	int l,j;
	for(int i:g[x])if(i^y){
		dp(i,x);
		if(f[x].size()<f[i].size())f[x].resize(f[i].size());
		l=f[i].size();
		for(j=0;j<l;++j)f[x][j]+=f[i][j];
	}
	for(int i:qr[x])if(o[i].k<f[x].size())ans[i]=f[x][o[i].k];
	if(f[x].size()<a[x])f[x].resize(a[x]);
	l=f[x].size();
	for(j=0;j<l;++j)f[x][j]+=a[x]-j;
	while(f[x].back()<0)f[x].pop_back();
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,q,i,j,k;
	cin>>n;
	for(i=1;i<n;++i){
		cin>>j>>k;
		g[j]+=k,g[k]+=j;
	}
	dfs1(1,0);
	cin>>q;
	for(i=1;i<=q;++i){
		cin>>o[i].v>>o[i].k;
		qr[o[i].v]+=i;
	}
	dp(1,0);
	for(i=1;i<=q;++i)cout<<ans[i]+a[o[i].v]+1<<'\n';
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3,P=1e9+7;
int f[N],g[N],a[N],pr[N],sf[N];
basic_string<int>e[N];
void dfs1(int x){
	f[x]=1;
	for(int i:e[x])dfs1(i),f[x]=f[x]*(f[i]+1ll)%P;
}
void dfs2(int x){
	int t=0,i;
	for(int i:e[x])a[++t]=i;
	for(pr[0]=sf[t+1]=i=1;i<=t;++i)pr[i]=pr[i-1]*(f[a[i]]+1ll)%P;
	for(i=t;i;--i)sf[i]=sf[i+1]*(f[a[i]]+1ll)%P,g[a[i]]=(g[x]+1ll)*pr[i-1]%P*sf[i+1]%P;
	for(int i:e[x])dfs2(i);
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,i,j;
	for(cin>>n,i=2;i<=n;++i)cin>>j,e[j]+=i;
	dfs1(1),dfs2(1);
	for(i=1;i<=n;++i)cout<<f[i]*(g[i]+1ll)%P<<' ';
	return 0;
}
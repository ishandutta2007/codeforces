#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7,N=2e5+3;
int jc[N],ijc[N],n,k,sz[N],w[N];
basic_string<int>g[N];
int qp(int a,int b){
	int r=1;for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
int ans,now;
void add(int x,int fx,int v=1){
if(x>=k)now=(now+v*(x-fx)*1ll*jc[x]%P*ijc[x-k])%P;
}
void dfs(int x,int y=0){
	sz[x]=1;
	for(int i:g[x])if(i^y)dfs(i,x),sz[x]+=sz[i];
}
void dfs1(int x,int y=0){
	add(sz[x],sz[y]);
	for(int i:g[x])if(i^y){
		dfs1(i,x);
		if(sz[i]>=k)w[x]=(w[x]+jc[sz[i]]*1ll*ijc[sz[i]-k])%P;
	}
}
void dfs2(int x,int y=0){
	ans=(ans+now)%P;
	for(int i:g[x])if(i^y){
		add(n-sz[i],n),add(sz[i],n,-1);
		if(sz[i]>=k)w[x]=(w[x]-jc[sz[i]]*1ll*ijc[sz[i]-k])%P;
		now=(now+(sz[i]-n)*1ll*w[i])%P;
		now=(now+sz[i]*1ll*w[x])%P;
		if(n-sz[i]>=k)w[i]=(w[i]+jc[n-sz[i]]*1ll*ijc[n-sz[i]-k])%P;
		dfs2(i,x);
		add(sz[i],n),add(n-sz[i],n,-1);
		if(n-sz[i]>=k)w[i]=(w[i]-jc[n-sz[i]]*1ll*ijc[n-sz[i]-k])%P;
		now=(now-(sz[i]-n)*1ll*w[i])%P;
		now=(now-sz[i]*1ll*w[x])%P;
		if(sz[i]>=k)w[x]=(w[x]+jc[sz[i]]*1ll*ijc[sz[i]-k])%P;
		
	}
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	int i,x,y;
	for(jc[0]=i=1;i<=n;++i)jc[i]=jc[i-1]*1ll*i%P;
	ijc[n]=qp(jc[n],P-2);
	for(i=n;i;--i)ijc[i-1]=ijc[i]*1ll*i%P;
	for(i=1;i<n;++i)cin>>x>>y,g[x]+=y,g[y]+=x;
	dfs(1),dfs1(1),dfs2(1);
	cout<<(ans*1ll*ijc[k]%P+P)%P<<'\n';
}
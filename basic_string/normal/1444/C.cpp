#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3,M=1e6+3,O=2e6+3;
int c[N],a[N],b[N],id[O],tp;
bool f[N];
struct P{
	int f,sz;
}d[M],st[O];
int gf(int x){return d[x].f==x?x:gf(d[x].f);}
void mg(int x,int y){
	int u=gf(x),v=gf(y);
	if(d[u].sz>d[v].sz)swap(u,v);
	st[++tp]=d[u],id[tp]=u,st[++tp]=d[v],id[tp]=v;
	d[v].sz+=d[u].sz,d[u].f=v;
}
map<pair<int,int>,int>mp;
vector<int>vc[N];
int main(){
	int n,m,k,i,j,l,u,v,w,uu,vv,tt,uuu,vvv;
	long long ans=0;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;++i)scanf("%d",c+i);
	for(i=1;i<=n*2;++i)d[i].f=i,d[i].sz=1;
	for(i=1;i<=m;++i)scanf("%d%d",a+i,b+i);
	for(i=1;i<=m;++i)if(c[a[i]]==c[b[i]]){
		u=gf(a[i]),v=gf(b[i]);
		if(u==v)f[c[a[i]]]=1;
		else mg(a[i],b[i]+n),mg(b[i],a[i]+n);
	}
	for(i=1,j=0;i<=m;++i)if(c[a[i]]!=c[b[i]]&&!f[c[a[i]]]&&!f[c[b[i]]]){
		u=c[a[i]],v=c[b[i]];
		if(u>v)swap(u,v);
		l=mp[{u,v}];
		if(!l)l=mp[{u,v}]=++j;
		vc[l].push_back(i);
	}
	for(auto o:mp){
		u=o.first.first,v=o.first.second,w=o.second,tt=tp;
		for(int o2:vc[w]){
			uu=a[o2],vv=b[o2],uuu=gf(uu),vvv=gf(vv);
			if(uuu==vvv){
				--ans;
				break;
			}
			mg(uu,vv+n),mg(uu+n,vv);
		}
		while(tp!=tt)d[id[tp]]=st[tp],--tp;
	}
	for(i=1,j=0;i<=k;++i)if(!f[i])++j;
	ans+=j*1ll*(j-1)/2;
	printf("%lld",ans);
	return 0;
}
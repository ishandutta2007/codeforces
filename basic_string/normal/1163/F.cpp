#include<bits/stdc++.h>
using namespace std;
const int N=4e5+3;
using ll=long long;
using ar=int[N];
ar he,to,len,ne,u,v,w,l,r,c,p;
ll d1[N],dn[N],a[N];
bool b[N];
int t=1;
priority_queue<pair<ll,int>>q;
basic_string<ll>g[N],h[N];
multiset<ll>s;
void add(int x,int y,int z){ne[++t]=he[x],to[t]=y,len[t]=z,he[x]=t;}
void dij(int s,ll*d){
	int i,j,k;
	ll l;
	memset(d,9,N*8),d[s]=0,q.push({0,s}),memset(b,0,N);
	while(!q.empty()){
		if(i=q.top().second,q.pop(),b[i])continue;
		for(b[i]=1,j=he[i];j;j=ne[j])if(d[k=to[j]]>(l=d[i]+len[j]))d[k]=l,q.push({-l,k});
	}
}
int main(){
	int n,m,q,i,j,k;
	ll o;
	scanf("%d%d%d",&n,&m,&q),memset(a,9,N*8),memset(l,9,N*4);
	for(i=1;i<=m;++i)scanf("%d%d%d",u+i,v+i,w+i),add(u[i],v[i],w[i]),add(v[i],u[i],w[i]);
	dij(1,d1),dij(n,dn);
	for(i=1,t=0;l[i]=t+1,r[i]=t,i!=n;i=k,p[j/2]=++t)for(j=he[i];dn[k=to[j]]+len[j]!=dn[i];j=ne[j]);
	for(i=1;i<=n;++i)c[i]=i;
	for(sort(c+1,c+n+1,[](int x,int y){return d1[x]<d1[y];}),i=1;i<=n;++i)for(j=he[c[i]];j;j=ne[j])if(!p[j/2]&&d1[k=to[j]]==d1[c[i]]+len[j])l[k]=min(l[k],l[c[i]]);
	for(sort(c+1,c+n+1,[](int x,int y){return dn[x]<dn[y];}),i=1;i<=n;++i)for(j=he[c[i]];j;j=ne[j])if(!p[j/2]&&dn[k=to[j]]==dn[c[i]]+len[j])r[k]=max(r[k],r[c[i]]);
	for(i=1;i<=m;++i)if(!p[i]){
		if(l[j=u[i]]<=r[k=v[i]])o=d1[j]+w[i]+dn[k],g[l[j]]+=o,h[r[k]]+=o;
		if(l[k]<=r[j])o=d1[k]+w[i]+dn[j],g[l[k]]+=o,h[r[j]]+=o;
	}
	for(i=1;i<=t;++i){
		for(ll o:g[i])s.insert(o);
		if(s.size())a[i]=*s.begin();
		for(ll o:h[i])s.erase(s.find(o));
	}
	while(q--){
		scanf("%d%d",&i,&j);
		if(p[i])printf("%lld\n",min(d1[n]+j-w[i],a[p[i]]));
		else printf("%lld\n",min(d1[n],min(d1[u[i]]+dn[v[i]],d1[v[i]]+dn[u[i]])+j));
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
using ll=long long;
struct T{ll t,d,l,r,mn,mx;}s[N*4];
int bg[N],ed[N],he[N],to[N],ne[N],sn[N],o,u,v;
ll len[N],w;
void ad(int k,ll v){s[k].t+=v,s[k].l-=v,s[k].r-=v,s[k].mn+=v,s[k].mx+=v;}
void upd(int k,int l,int r){
	if(u<=l&&r<=v)return ad(k,w);
	int m=l+r>>1,a=k*2,b=a+1;
	if(s[k].t)ad(a,s[k].t),ad(b,s[k].t),s[k].t=0;
	if(u<=m)upd(a,l,m);
	if(m<v)upd(b,m+1,r);
	s[k].mn=min(s[a].mn,s[b].mn);
	s[k].mx=max(s[a].mx,s[b].mx);
	s[k].l=max(s[a].l,max(s[b].l,s[a].mx-2*s[b].mn));
	s[k].r=max(s[a].r,max(s[b].r,s[b].mx-2*s[a].mn));
	s[k].d=max(s[a].d,max(s[b].d,max(s[a].l+s[b].mx,s[a].mx+s[b].r)));
}
void dfs(int x,int y){
	bg[x]=++o;
	for(int i=he[x],j;i;i=ne[i])if((j=to[i])!=y)sn[i>>1]=j,dfs(j,x),++o;
	ed[x]=o;
}
int main(){
	int n,q,i,j,k,t=1;
	ll l,m,z=0;
	for(i=1,scanf("%d%d%lld",&n,&q,&m);i<n;++i)scanf("%d%d%lld",&j,&k,len+i),ne[++t]=he[j],to[t]=k,he[j]=t,ne[++t]=he[k],to[t]=j,he[k]=t;
	for(i=1,dfs(1,0);i<n;++i)u=bg[sn[i]],v=ed[sn[i]],w=len[i],upd(1,1,o);
	while(q--)scanf("%d%lld",&i,&l),u=bg[sn[i=(i+z)%(n-1)+1]],v=ed[sn[i]],w=(z=(l+z)%m)-len[i],len[i]=z,upd(1,1,o),printf("%lld\n",z=s[1].d);
	return 0;
}
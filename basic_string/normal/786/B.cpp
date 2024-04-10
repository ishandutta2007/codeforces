#include<bits/stdc++.h>
using namespace std;
const int N=6e6+7;
#define ll long long
int id,he[N],to[N],len[N],ne[N],lc[N],rc[N],t,p,u,v,w;
ll d[N];
bool f[N];
priority_queue<pair<ll,int> >q;
inline void add(int x,int y,int z){
	ne[++t]=he[x],to[t]=y,len[t]=z,he[x]=t;
}
void build(int&k,int l,int r){
	if(l==r){k=l;return;}
	int m=l+r>>1;
	k=++id,build(lc[k],l,m),build(rc[k],m+1,r);
}
void up1(int k,int l,int r){
	if(u<=l&&r<=v)return add(p,k,w);
	int m=l+r>>1;
	if(u<=m)up1(lc[k],l,m);
	if(m<v)up1(rc[k],m+1,r);
}
void up2(int k,int l,int r){
	if(u<=l&&r<=v)return add(k,p,w);
	int m=l+r>>1;
	if(u<=m)up2(lc[k],l,m);
	if(m<v)up2(rc[k],m+1,r);
}
int main(){
	int n,m,s,r1,r2,i,j,k;
	long long l;
	scanf("%d%d%d",&n,&m,&s),id=n;
	build(r1,1,n);
	for(i=n+1;i<=id;++i)add(i,lc[i],0),add(i,rc[i],0);
	build(r2,1,n);
	for(;i<=id;++i)add(lc[i],i,0),add(rc[i],i,0);
	while(m--){
		scanf("%d%d%d%d",&i,&p,&u,&v);
		if(i==1)add(p,u,v);
		else if(i==2)scanf("%d",&w),up1(r1,1,n);
		else scanf("%d",&w),up2(r2,1,n);
	}
	memset(d,63,sizeof(d)),d[s]=0,q.push(make_pair(0,s));
	while(!q.empty()){
		i=q.top().second,q.pop();
		if(f[i])continue;
		f[i]=1;
		for(j=he[i];j;j=ne[j]){
			k=to[j],l=len[j]+d[i];
			if(d[k]>l)d[k]=l,q.push(make_pair(-l,k));
		}
	}
	for(i=1;i<=n;++i)if(d[i]<1e18)printf("%lld ",d[i]);else printf("-1 ");
	return 0;
}
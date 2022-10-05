#include<bits/stdc++.h>
using namespace std;
enum{N=200009,M=N*63};
int c[M][2],sz[M],ps[M],rt[N],a[N],id,n,f[N],mn[N],to[N];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
void ins(int x,int y){
	if(!rt[x])rt[x]=++id;
	int i=29,v=a[y],b,p=rt[x];
	for(;++sz[p],~i;p=c[p][b],--i)if(!c[p][b=v>>i&1])c[p][b]=++id;
	ps[p]=y;
}
pair<int,int>qry(int x,int y,int v){
	int w=0,i=29,b;
	for(;~i;--i)if(b=v>>i&1,sz[c[x][b]]-sz[c[y][b]])x=c[x][b],y=c[y][b];
	else x=c[x][!b],y=c[y][!b],w+=1<<i;
	return{w,ps[x]};
}
void mg(int&x,int y){
	if(!x||!y){x|=y;return;}
	mg(c[x][0],c[y][0]),mg(c[x][1],c[y][1]),sz[x]=sz[c[x][0]]+sz[c[x][1]];
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int i,x,y;
	long long w=0;
	for(cin>>n,i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1),n=unique(a+1,a+n+1)-a-1;
	for(i=1;i<=n;++i)ins(0,i),ins(i,i),f[i]=i;
	for(;sz[rt[gf(1)]]<n;){
		for(memset(mn,99,N*4),i=1;i<=n;++i){
			auto o=qry(rt[0],rt[gf(i)],a[i]);
			if(x=gf(i),y=gf(o.second),o.first<mn[x])mn[x]=o.first,to[x]=y;
			if(o.first<mn[y])mn[y]=o.first,to[y]=x;
		}
		for(i=1;i<=n;++i)if(mn[i]<mn[0]&&gf(i)!=gf(to[i]))mg(rt[f[i]],rt[f[to[i]]]),f[f[to[i]]]=i,w+=mn[i];
	}
	cout<<w<<'\n';
	return 0;
}
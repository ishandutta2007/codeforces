#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=50009;
int w,n,ne[N<<1],to[N<<1],he[N],sz[N],mx[N],rt,d[N],g[509];
bool b[N];
ll ans;
void getr(int x,int y){
	sz[x]=1,mx[x]=0;
	for(int i=he[x],j;i;i=ne[i])if(!b[j=to[i]]&&j!=y){
		getr(j,x),sz[x]+=sz[j];
		if(mx[x]<sz[j])mx[x]=sz[j];
	}
	if((mx[x]=max(mx[x],n-sz[x]))<mx[rt])rt=x;
}
void getd(int x,int y){
	if(++g[d[x]],d[x]==w)return;
	for(int i=he[x],j;i;i=ne[i])if(!b[j=to[i]]&&j!=y)d[j]=d[x]+1,getd(j,x);
}
void calc(int x,bool f){
	memset(g,0,w+1<<2),d[x]=f,getd(x,0);
	ll s=0;
	int i,j;
	for(i=0,j=w;i<j;++i,--j)s+=g[i]*1ll*g[j];
	if(i==j)s+=(g[i]*1ll*(g[i]-1))>>1;
	ans+=f?-s:s;
}
void work(int x){ 
	b[x]=1,calc(x,0);
	for(int i=he[x],j;i;i=ne[i])if(!b[j=to[i]])calc(j,1),mx[rt=0]=n=sz[j],getr(j,0),work(rt);
}
int main(){
	int i,j,k,t=0;
	scanf("%d%d",&n,&w);
	for(i=1;i<n;++i){
		scanf("%d%d",&j,&k);
		ne[++t]=he[j],to[t]=k,he[j]=t;
		ne[++t]=he[k],to[t]=j,he[k]=t;
	}
	mx[0]=n,getr(1,0),work(rt),printf("%lld",ans);
	return 0;
}
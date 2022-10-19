#include<bits/stdc++.h>
#define M 1000000
using namespace std;
int a[500005];
struct apple{
	int zx,cs;
}sm[4000005];
int lz[4000005];
apple operator+(apple a,apple b){
	if(!a.cs)return b;
	if(!b.cs)return a;
	apple c;
	c.zx=min(a.zx,b.zx);
	c.cs=0;
	if(a.zx<=b.zx)c.cs+=a.cs;
	if(b.zx<=a.zx)c.cs+=b.cs;
	return c;
}
void pushdown(int l,int r,int o){
	if(!lz[o])return;
	sm[o<<1].zx+=lz[o],sm[o<<1|1].zx+=lz[o];
	lz[o<<1]+=lz[o],lz[o<<1|1]+=lz[o];
	lz[o]=0;
	return;
}
void add1(int l,int r,int o,int u,int op){
	if(l==r){
		sm[o].cs+=op;
		return;
	}
	pushdown(l,r,o);
	int mid=(l+r)>>1;
	if(u<=mid)add1(l,mid,o<<1,u,op);
	else add1(mid+1,r,o<<1|1,u,op);
	sm[o]=sm[o<<1]+sm[o<<1|1];
}
void add2(int l,int r,int o,int ll,int rr,int v){
	if(l>=ll&&r<=rr){
		sm[o].zx+=v;
		lz[o]+=v;
		return;
	}
	pushdown(l,r,o);
	int mid=(l+r)>>1;
	if(mid>=ll)add2(l,mid,o<<1,ll,rr,v);
	if(mid<rr)add2(mid+1,r,o<<1|1,ll,rr,v);
	sm[o]=sm[o<<1]+sm[o<<1|1];
}
int main(){
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	a[0]=M+1,a[n+1]=0;
	for(int i=1;i<=n+1;++i)add1(0,M,1,a[i],1);
	for(int i=1;i<=n+1;++i)if(a[i-1]>a[i]){
		add2(0,M,1,a[i],a[i-1]-1,1);
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		add1(0,M,1,a[x],-1);
		if(a[x-1]>a[x]){
			add2(0,M,1,a[x],a[x-1]-1,-1);
		}
		if(a[x]>a[x+1]){
			add2(0,M,1,a[x+1],a[x]-1,-1);
		}
		a[x]=y;
		add1(0,M,1,a[x],1);
		if(a[x-1]>a[x]){
			add2(0,M,1,a[x],a[x-1]-1,1);
		}
		if(a[x]>a[x+1]){
			add2(0,M,1,a[x+1],a[x]-1,1);
		}
		printf("%d\n",sm[1].cs-1);
	}
	return 0;
}
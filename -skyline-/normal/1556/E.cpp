#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,q,a[100005],b[100005];
ll s[100005];
	int L,R;
struct S{
	ll t[262222];
	void init(){
		for(int i=0;i<=262200;++i)t[i]=-orz*1ll*orz;
	}
	void upd(int x,ll o){
		x+=131071;
		t[x]=o;
		x>>=1;
		while(x)t[x]=max(t[x<<1],t[(x<<1)^1]),x>>=1;
	}
	ll get(int k,int l,int r){
		if(l>=L&&r<=R) return t[k];
		int m=(l+r)>>1,lc=k<<1,rc=lc|1;
		ll ret=-orz*1ll*orz;
		if(L<=m)ret=max(ret,get(lc,l,m));
		if(R>m)ret=max(ret,get(rc,m+1,r));
		return ret;
	}
}t[2];
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	t[0].init();
	t[1].init();
	for(int i=1;i<=n;++i)scanf("%d",b+i),s[i]=s[i-1]+a[i]-b[i],t[0].upd(i,s[i]),t[1].upd(i,-s[i]);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		L=l,R=r;
		if(s[r]==s[l-1]&&t[0].get(1,1,131072)==s[r])printf("%I64d\n",t[1].get(1,1,131072)+s[r]);
		else printf("-1\n");
	}
    return 0;
}
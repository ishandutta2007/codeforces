#include<bits/stdc++.h>
int n,a[1111111];
const int maxV=3e5;
typedef long long ll;
struct BIT
{
	ll v[1111111];
	void ins(int x,int d)
	{
		for(;x<=(maxV<<1);x+=x&-x)v[x]+=d;
	}
	ll ask(int x)
	{
		ll r=0;
		for(;x;x-=x&-x)r+=v[x];
		return r;
	}
	ll ask(int l,int r){return ask(r)-ask(l-1);}
}T,TS;
int main()
{
	scanf("%d",&n);
	register int i;
	ll ans=0,S=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i),S+=a[i];
		ans-=TS.ask(a[i]);
		for(register int ii=a[i];ii<=maxV;ii+=a[i])
			ans-=ii*T.ask(ii,ii+a[i]-1),TS.ins(ii,a[i]);
		printf("%lld ",S*(i-1)+ans);
		T.ins(a[i],1);
	}
	puts("");
}
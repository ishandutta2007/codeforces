#include<bits/stdc++.h>
int n;
typedef long long ll;
struct pii{ll x,v;}p[1111111];
bool check(ll M)
{
	register int i;
	for(i=1;i<=n;i++)
	{
		
	}
	return 0;
}
int main()
{
	ll Sx=0;
	scanf("%d",&n);
	for(register int i=1;i<=n;i++)
		scanf("%lld%lld",&p[i].x,&p[i].v),
		Sx+=p[i].x;
	std::sort(p+1,p+n+1,[&]
	(const pii&x,const pii&y){return x.v<y.v;});
	ll ans=0,tot=0;
	for(register int L=1,R=n;L<=R;)
	{
		if(p[L].v<=tot)
		{
			tot+=p[L].x,ans+=p[L].x,L++;
		}
		else if(p[L].v<=tot+p[R].x)
		{
			ans+=(p[L].v-tot)*2,p[R].x-=(p[L].v-tot),
			tot=p[L].v;
		}
		else tot+=p[R].x,ans+=p[R].x*2,R--;
	}
	printf("%lld\n",ans);
	/*
	ll L=Sx,R=Sx*2;
	while(L+1<R)
	{
		ll Mid=(L+R)>>1;
		if(check(Mid))R=Mid;
		else L=Mid;
	}
	*/
}
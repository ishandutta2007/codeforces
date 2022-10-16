#include<cstdio>
typedef long long ll;
ll phi(ll x)
{
    ll r=1;
    for(register int i=2;i<=x/i;i++)
        if(x%i==0){r*=(i-1),x/=i;while(x%i==0)x/=i,r*=i;}
    if(x>1)r*=(x-1);
    return r;
}
bool d,e;
ll qpow(ll x,ll k,ll mod)
{
    d=e=0;
    ll r=1;
    for(;k;k>>=1)
    {
    	if(x>=mod)x%=mod,e|=1;
        if(k&1)(r*=x),d|=e;
        if(r>=mod)r%=mod,d|=1;
        (x*=x);
    }return r;
}
ll a[1111111],p[1111111];
ll solve(int l,int r)
{
	ll ans=a[r];
	//d=e=0;
	register int i;
	if(r-l>40)
	{
		ans=0;
		for(i=l+35;i>=l;i--)
		{
			ans=qpow(a[i],ans,p[i-l+1]);
			if(d)ans+=p[i-l+1];
		}
	}else
	{
		ans=a[r];
		for(i=r-1;i>=l;i--)
		{
			ans=qpow(a[i],ans,p[i-l+1]);
			if(d)ans+=p[i-l+1];
		}
	}return ans;
}
int main()
{
    int T,n,P;
    register int i;
    scanf("%d%d",&n,&P),p[1]=P;
    for(i=1;i<=n;i++)scanf("%lld",a+i);
    for(i=1;i<=n;i++)p[i+1]=phi(p[i]);
    int q;scanf("%d",&q);
	for(i=1;i<=q;i++)
    {
    	int l,r;
    	scanf("%d%d",&l,&r);
    	printf("%lld\n",solve(l,r)%P);
    }
}
/*
Every little step contributes in constructing what is called the great.
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll gcd(ll a,ll b)
{
	ll t;
	while(b)t=a%b,a=b,b=t;
	return a;	
}

int main()
{
    #ifdef OnCode
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int n;
    ll p,q,b,t;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	scanf("%I64d%I64d%I64d",&p,&q,&b);
    	q/=gcd(p,q);
    	while((t=gcd(q,b))>1)q/=t,b=t;
    	if(q==1)printf("Finite\n");
    	else printf("Infinite\n");
    }
    return 0;
}
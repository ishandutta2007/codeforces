#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll hc,dc,hm,dm;
ll k,w,a;
ll ht,dt;
int t;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%lld%lld%lld%lld",&hc,&dc,&hm,&dm);
		scanf("%lld%lld%lld",&k,&w,&a);
		bool b=false;
		for (int i=0;i<=k;++i)
		{
			ht=hc+(ll)i*a;
			dt=dc+(ll)(k-i)*w;
			ll n0=(hm-1)/dt+1;
			ll n1=(ht-1)/dm+1;
			if (n0<=n1)
				b=true;
		}
		puts(b?"YES":"NO");
	}
	return 0;
}
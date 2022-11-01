#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)1001*1000)
#define K ((ll)20)


ll n,k,fen[N];

ll query(ll x){ll res=0;for(;x>0;x-=x&-x)res+=fen[x];return res;}
ll add(ll x){for(;x<=n;x+=x&-x)fen[x]++;}

int main()
{
	scanf("%d%d",&n,&k);
	cin>>n>>k;
	if(k>n/2)k=n-k;
	ll now=1;
	long long ans=1;
	while(1)
	{
		ll nex=now+k;
		if(nex<=n)ans+=2*(query(nex)-query(now))+1;
		else
		{
			nex-=n;
			ans+=2*(query(nex)+query(n)-query(now));
			if(nex==1)ans--;
		}
		printf("%lld ",ans);
		add(now);now=nex;
		if(now==1)break;
	}
	return 0;
}
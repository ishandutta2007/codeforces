#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)1001*1000)
#define K ((ll)10*1001*1000)
#define INF ((ll)1e13+100)
#define MOD ((ll)1e9+7)

int n,a[N],num[K];
ll ans;
bool mark[K];

ll f(ll x,int p)
{
	ll res=0;
	for(ll i=p;i<=x;i*=p)res+=x/i;
	return res;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]),num[a[i]]++;
	for(int i=K-2;i>=1;i--)num[i]+=num[i+1];
	for(ll i=2;i<K;i++)
	{
		if(mark[i])continue;
		ll res=0;
		for(ll j=i;j<K;j+=i)
		{
			mark[j]=1;
			ll p=j/i,q=1;
			while(p%i==0)q++,p/=i;
			res+=num[j]*q;
		}
		ll l=0,r=INF;
		while(l<r-1)
		{
			ll mid=(l+r)/2;
			if(f(mid,i)>=res)r=mid;
			else l=mid;
		}
		ans=max(ans,r);
	}
	printf("%I64d",ans);
	return 0;
}
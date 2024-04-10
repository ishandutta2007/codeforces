#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)3000*1000+1)

ll n,m,a[N],cnt[N];
long long num[N];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]),cnt[a[i]]++;
	for(ll i=1;i<N;i++)
	{
		ll j=i+1;
		while(1LL*i*j<N)num[i*j]+=cnt[i]*cnt[j],j++;
		if(1LL*i*i<N)num[i*i]+=cnt[i]*(cnt[i]-1)/2;
	}
	for(int i=1;i<N;i++)num[i]+=num[i-1];
	scanf("%d",&m);
	while(m--)
	{
		ll x;
		scanf("%d",&x);
		printf("%I64d\n",1LL*n*(n-1)-1LL*num[x-1]*2);
	}
	return 0;
}
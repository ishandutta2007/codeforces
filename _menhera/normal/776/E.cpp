#include<bits/stdc++.h>
long long phi(long long x)
{
	long long ans = x;
	for(long long i=2; i*i<=x; ++i)
	{
		if(x%i==0)
		{
			ans /= i;
			ans *= (i-1);
			while(x%i==0)
			{
				x/=i;
			}
		}
	}
	if(x!=1)
	{
		ans /= x;
		ans *= (x-1);
	}
	return ans;
}
int main()
{
	long long N; long long K;
	scanf("%lld%lld",&N,&K);
	K = (K+1)/2;
	for(long long i=0; i<K; ++i)
	{
		N = phi(N);
		if(N==1) break;
		//printf("%lld\n",N);
	}
	printf("%lld\n",N%1000000007);
}
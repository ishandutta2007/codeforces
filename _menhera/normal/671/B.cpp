#include<cstdio>
#include<algorithm>
using namespace std;
int N;
long long K;
long long c[1010101];

bool can1(long long int v)
{
	long long sum = 0;
	for(int i=0; i<N; i++)
		if(c[i]>v) sum += c[i]-v;
	return sum<=K;
}

bool can2(long long int v)
{
	long long sum = 0;
	for(int i=0; i<N; i++)
		if(c[i]<v) sum += v-c[i];
	return sum <=K;
}

int main()
{
	scanf("%d%lld",&N,&K);
	for(int i=0; i<N; i++) scanf("%lld",c+i);
	long long int sum = 0;
	for(int i=0; i<N; i++) sum +=c[i];
	//take K money at once
	long long int lo1 = 0; // can't
	long long int hi1 = 1e10; //can
	while(lo1+1!=hi1)
	{
		long long int mi = (lo1+hi1)/2;
		if(can1(mi)) hi1 = mi;
		else lo1 = mi;
	}

	//give K money at once

	long long int lo2 = 0; //can
	long long int hi2 = 1e10; //can't
	while(lo2+1!=hi2)
	{
		long long int mi = (lo2+hi2)/2;
		if(can2(mi)) lo2=mi;
		else hi2=mi;
	}
	//printf("%lld %lld\n",hi1, lo2);
	long long ans = hi1-lo2;
	if(sum%N==0) ans = max(ans, 0LL);
	else ans = max(ans, 1LL);
	printf("%lld",ans);
	return 0;
}
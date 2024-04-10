#include<bits/stdc++.h>
using namespace std;
int N;
long long K;
long long int arr[101010];
long long int S[101010];
long long powK[101];
int tp = 0;
int main()
{
	scanf("%d%lld",&N,&K);
	for(int i=1; i<=N; ++i)
	{
		scanf("%lld",arr+i);
		S[i] = S[i-1] + arr[i];
	}
	long long int v = 1;
	powK[tp++] = v;
	while(v*K!=1LL && -1e15 <= v && v<= 1e15)
	{
		v*=K;
		powK[tp++]=v;
	}
	map<long long, int> SS;
	long long ans = 0;
	for(int i=0; i<=N; ++i)
	{
		for(int j=0; j<tp; ++j)
			if(SS.count(S[i]-powK[j]))
				ans += SS[S[i]-powK[j]];
		SS[S[i]] = SS[S[i]]+1;
	}
	printf("%lld\n",ans);
	return 0;
}
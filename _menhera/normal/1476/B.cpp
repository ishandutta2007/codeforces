#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int N, K;
		scanf("%d%d", &N, &K);
		long long s; scanf("%lld", &s);
		long long ans = 0;
		for(int i=1; i<N; ++i)
		{
			long long t; scanf("%lld", &t);
			ans = max(ans, (100*t+K-1)/K-s);
			s += t;
		}
		printf("%lld\n", ans);
	}
}
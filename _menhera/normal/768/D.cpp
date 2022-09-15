#include<bits/stdc++.h>
using namespace std;
int K;
double prob[1010];
int ans[2010];
int tp = 0;
int main()
{
	scanf("%d",&K);
	int cnt = 0;
	prob[0] = 1.0;
	while(prob[K]<0.55)
	{
		for(int i=K-1; i>=0; i--)
		{
			prob[i+1] += prob[i]*(K-i)/K;
			prob[i] *= 1.0*i/K;
		}
		++cnt;
		while(prob[K] > tp / 2000.0 )
			ans[tp++] = cnt;
	}
	int Q;
	scanf("%d",&Q);
	for(int i=0; i<Q; ++i)
	{
		int T;
		scanf("%d",&T);
		printf("%d\n",ans[T]);
	}
}
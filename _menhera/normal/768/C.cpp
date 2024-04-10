#include<bits/stdc++.h>
using namespace std;
int N, K, X;
int arr[1024];
int tarr[1024];
int main()
{
	scanf("%d%d%d",&N,&K,&X);
	for(int i=0; i<N; ++i)
	{
		int T;
		scanf("%d",&T);
		arr[T] ++;
	}
	for(int i=0; i<K; ++i)
	{
		int parity = 1;
		for(int j=0; j<1024; ++j)
		{
			tarr[j^X] += (arr[j]+parity)/2;
			tarr[j] += (arr[j] + 1-parity)/2;
			parity = (parity+arr[j])&1;
		}
		for(int j=0; j<1024; ++j)
		{
			arr[j] = tarr[j];
			tarr[j] = 0;
		}
	}
	int minv = 1024, maxv = -1;
	for(int i=0; i<1024; ++i)
	{
		if(arr[i]) minv = min(minv,i);
		if(arr[i]) maxv = max(maxv,i);
	}
	printf("%d %d\n",maxv,minv);
	return 0;
}
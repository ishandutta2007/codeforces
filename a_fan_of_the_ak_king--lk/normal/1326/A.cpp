#include<bits/stdc++.h>
using namespace std;
const int N=200005,E=262144;
const int M=1000000007;
int n,t,i;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n==1)
		{
			puts("-1");
			continue;
		}
		for(i=1;i<=n-2;++i)
			printf("8");
		printf("58\n");
	}
}
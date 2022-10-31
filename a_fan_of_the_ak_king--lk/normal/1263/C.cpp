#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const long double PI=3.141592653589793238462643383279;
const int M=998244353,N=1000005;
int n,i,j,f[N],k,t;
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
		k=0;
		for(i=1;i<=n;i=n/(n/i)+1)
			f[++k]=n/i;
		f[++k]=0;
		printf("%d\n",k);
		for(i=k;i>=1;--i)
			printf("%d ",f[i]);
		printf("\n");
	}
}
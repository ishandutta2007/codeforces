#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,k;char c[N],d[N];
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%s",&n,&k,c+1);
		for(int i=1;i<=n;i++)if((i+1)/2<k)d[i]=i&1?'(':')';else d[i]=i<=n/2+k-1?'(':')';
		printf("%d\n",n);
		for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)if(d[i]==c[j])
		{
			for(int k=i;k+k<i+j;k++)swap(c[k],c[i+j-k]);
			printf("%d %d\n",i,j);break;
		}
	}
	return 0;
}
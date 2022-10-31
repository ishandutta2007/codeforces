#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,P=998244353;
const int N=200005,E=262144;
#define inf 2147483647
int n,i,j,t,a[N],m,s,k;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	int s=0;
	for(i=1;i<=n;++i)
		s+=(i-1)/2;
	if(s<m)
	{
		puts("-1");
		return 0;
	}
	for(i=1;i<=n;++i)
		if(m>=(i-1)/2)
		{
			m-=(i-1)/2;
			a[i]=i;
		}
		else
		{
			for(j=i;;++j)
			{
				int s=0;
				for(k=1;k<i;++k)
					if(j-a[k]<a[k])
						++s;
				if(s==m)
					break;
			}
			a[i]=j;
			++i;
			break;
		}
	a[i]=500000000;
	for(++i;i<=n;++i)
		a[i]=a[i-1]+10000;
	for(i=1;i<=n;++i)
		printf("%d ",a[i]);
}
#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int t,n,q,i,a[100005],j,ans;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(i=30;i>=0;--i)
	{
		int s=0;
		for(j=1;j<=n;++j)
			if((a[j]>>i)&1)
				++s;
		if(s==1)
			break;
	}
	for(j=1;j<=n;++j)
		if((a[j]>>i)&1)
			break;
	if(j==n+1)
		j=1;
	printf("%d ",a[j]);
	for(i=1;i<=n;++i)
		if(i!=j)
			printf("%d ",a[i]);
}
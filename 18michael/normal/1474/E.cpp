#include<bits/stdc++.h>
using namespace std;
int n,Test_num;
long long ans;
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)
	{
		scanf("%d",&n),ans=1LL*(n-1)*(n-1);
		for(int i=2;i<n;++i)ans+=1LL*max(i-1,n-i)*max(i-1,n-i);
		printf("%lld\n%d ",ans,n/2+1);
		for(int i=1;i<n/2;++i)printf("%d ",i);
		for(int i=n/2+2;i<=n;++i)printf("%d ",i);
		printf("%d\n%d\n",n/2,n-1);
		for(int i=n/2;i>1;--i)printf("%d %d\n",i,n);
		for(int i=n/2+1;i<n;++i)printf("%d %d\n",i,1);
		printf("%d %d\n",1,n);
	}
	return 0;
}
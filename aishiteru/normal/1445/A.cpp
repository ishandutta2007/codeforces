#include<bits/stdc++.h>
using namespace std;
int n,i,t,x,a[100005],b[100005];
long long p,q;
long long Test(long long i)
{
	if(i==1)
		return 1;
	long long t=p;
	while(t%q==0)
		t/=i;
	return t;
}
int main()
{
	cin>>t;
	while(t--)
	{
		scanf("%d %d",&n,&x);
		for(i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for(i=1;i<=n;++i)
			scanf("%d",&b[i]);
		for(i=1;i<=n;++i)
			if(a[i]+b[n-i+1]>x)
				break;
		puts(i>n?"Yes":"No");
	}
}
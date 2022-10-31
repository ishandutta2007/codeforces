#include<bits/stdc++.h>
using namespace std;
const int M=998244353,N=500005;
int n,i,j,t,a[N]; 
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
		for(i=1;i<=n;++i)
			scanf("%d",&a[i]);
		int las=a[1],s=0;
		for(i=2;i<=n;++i)
		{
			if(a[i]-s<0)
				break;
			if(a[i]-s>las)
				s+=a[i]-s-las;
			else
				las=a[i]-s;
		}
		puts(i<=n?"NO":"YES");
	}
}
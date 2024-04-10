#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const long double PI=3.141592653589793238462643383279;
const int M=998244353,N=1000005;
int n,i,j,f[N],k,t,a[N],ans;
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
		ans=0;
		for(i=1;i<=n;++i)
		{
			for(j=0;j<=9;++j)
			{
				for(k=1;k<=n;++k)
					if(i!=k)
						if((a[i]%10+j)%10+a[i]-a[i]%10==a[k])
							break;
				if(k>n)
					break;
			}
			if(j!=0)
			{
				++ans;
				a[i]=(a[i]%10+j)%10+a[i]-a[i]%10;
			}
		}
		printf("%d\n",ans);
		for(i=1;i<=n;++i)
			printf("%04d\n",a[i]);
	}
}
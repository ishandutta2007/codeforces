#include<bits/stdc++.h>
using namespace std; 
const int N=300005,M=998244353;
const long double PI=3.1415926535897932384626;
int n,p,i,t,a[N],f[N],j,ans;
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
		{
			scanf("%d",&a[i]);
			++f[a[i]];
		}
		ans=0;
		for(i=1;i<=2*n+1;++i)
			if(f[i])
			{
				++ans;
				if(f[i]>1)
					++f[i+1];
			}
		printf("%d\n",ans);
		for(i=1;i<=2*n+1;++i)
			f[i]=0;
	}
}
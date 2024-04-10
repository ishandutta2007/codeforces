#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int t,sum,i,n,x,ans,s;
char a[100005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&x);
		scanf("%s",a+1);
		sum=0;
		for(i=1;i<=n;++i)
			if(a[i]=='0')
				++sum;
			else
				--sum;
		ans=s=0;
		for(i=0;i<n;++i)
		{
			if(i)
			{
				if(a[i]=='0')
					++s;
				else
					--s;
			}
			if(sum==0)
				if(x-s==0)
				{
					ans=-1;
					break;
				}
				else
					continue;
			if((x-s)%sum==0)
				if(1ll*(x-s)*sum>=0)
					++ans;
		}
		cout<<ans<<endl;
	}
}
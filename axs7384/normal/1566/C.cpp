#include<bits/stdc++.h>
using namespace std;
int t,n;
const int N=100005;
int used[N];
int a[N];
char s1[N],s2[N];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		scanf("%s",s1);
		scanf("%s",s2);
		for (int i=0;i<n;++i)
		{
			used[i]=0;
			a[i]=s1[i]-'0'+s2[i]-'0';
		}
		int ans=0;
		for (int i=0;i<n;++i)
		{
			if (i!=0&&!used[i-1])
			{
				if (a[i]==1)
				{
					ans+=2;
					used[i]=1;
					if (a[i-1]==0)
						++ans;
				}
				if (a[i]==0)
				{
					if (a[i-1]==0)
						++ans;
					else
					{
						ans+=2;
						used[i]=1;
					}
				}
				if (a[i]==2)
				{
					if (a[i-1]==0)
					{
						ans+=2;
						used[i]=1;
					}
				}
			}
			else
			{
				if (a[i]==1)
				{
					ans+=2;
					used[i]=1;
				}
			}
		}
		if (!used[n-1]&&a[n-1]==0)
			++ans;
		printf("%d\n",ans);
	}
	return 0;
}
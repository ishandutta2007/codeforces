#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL N=200005;
char ss[N];
int n;
char a[N];
int main()
{
	LL T;
	scanf("%lld",&T);
	while (T--)
	{
		scanf("%d",&n);
		scanf("%s",ss+1);
		bool tf=false;
		for (int u=2;u<=n;u++) if (ss[u]!=ss[u-1])
		{
			int now=u;
			for (int i=1;i<=n;i++)
			{
				a[i]=ss[now];
				now++;if (now>n) now-=n;
			}
			tf=true;
			break;
		}
		int cnt=0,ans=0;
		if (tf==false) ans=(n+2)/3;
		else
		{
			for (int u=2;u<=n;u++)
			{
				if (a[u]==a[u-1]) cnt++;
				else	{ans=ans+(cnt+1)/3;cnt=0;}
			}
		}
		ans=ans+(cnt+1)/3;
		printf("%d\n",ans);
		
	}
	return 0;
}
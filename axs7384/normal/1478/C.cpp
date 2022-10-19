#include<bits/stdc++.h>
using namespace std;
#define int long long
inline void read(int &x)
{
	char c=getchar();
	x=0;
	while (c>'9'||c<'0')
		c=getchar();
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
int a[200005];
int n;
int t;
signed main()
{
	read(t);
	while (t--)
	{
		read(n);
		for (int i=1;i<=2*n;++i)  
			read(a[i]);
		bool b=1;
		for (int i=1;i<=2*n;++i)
		{
			if (a[i]&1)
			{
				b=0;
				break;
			}
			a[i]/=2;
		}
		if (!b)
		{
			puts("NO");
			continue;
		}
		sort(a+1,a+1+2*n);
		for (int i=1;i<=n;++i)
			if (a[i*2-1]!=a[i*2]||a[i*2]==a[i*2+2])
			{
				b=0;
				break;
			}

		if (!b)
		{
			puts("NO");
			continue;
		}
		int sum=0,now=0;
		for (int i=1;i<n;++i)
		{
			int p=a[i*2+2]-a[i*2];
			if (p%i!=0)
			{
				b=0;
				break;
			}
			now+=p/i;
			sum+=now;
		}
		if (!b||sum>=a[1]||(a[1]-sum)%n!=0)
		{
			puts("NO");
			continue;
		}
		puts("YES");
	}
	return 0;
}
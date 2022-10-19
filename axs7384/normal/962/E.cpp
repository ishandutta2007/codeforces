#include<bits/stdc++.h> 
using namespace std;
#define int long long
inline void read(int &x)
{
	char c=getchar();
	int y=1;
	while (c>'9'||c<'0')
	{
		if (c=='-')
			y=-1;
		c=getchar();
	}
	x=0;
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	x*=y;
}
inline void write(int x)
{
	if (x==0)
	{
		putchar('0');
		return;
	}
	int a[20];
	a[0]=0;
	while (x)
	{
		a[++a[0]]=x%10;
		x/=10;
	}
	while (a[0])
		putchar(a[a[0]--]+'0');
}	
int n,x,ans,la_b,la_r,mx_b,mx_r,la_p;
const int inf=1e9+7;
char c[5];
signed main()
{
	//freopen("962E.in","r",stdin);
	//freopen("962E.out","w",stdout);
	read(n);
	for (int i=1;i<=n;i++)
	{
		read(x);
		scanf("%s",c);
		x+=inf;
		if (c[0]=='B')
		{
			if (la_b)
			{
				ans+=x-la_b;
				mx_b=max(mx_b,x-la_b);
			}
			la_b=x;
		}
		if (c[0]=='R')
		{
			if (la_r)
			{
				ans+=x-la_r;
				mx_r=max(mx_r,x-la_r);
			}
			la_r=x;
		}
		if (c[0]=='P')
		{
			if (la_b)
			{
				ans+=x-la_b;
				mx_b=max(mx_b,x-la_b);
			}
			if (la_r)
			{
				ans+=x-la_r;
				mx_r=max(mx_r,x-la_r);
			}
			if (la_p)
				ans+=min(0ll,x-la_p-mx_b-mx_r);
			la_b=la_r=la_p=x;
			mx_b=mx_r=0;
		}
	}
	write(ans);
	return 0;
}
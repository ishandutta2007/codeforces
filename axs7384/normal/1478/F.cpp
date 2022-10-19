#include<bits/stdc++.h>
using namespace std;
#define int long long
inline void read(int &x)
{
	char c=getchar();
	x=0;
	int y=1;
	while (c>'9'||c<'0')
	{
		if (c=='-')
			y=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	x*=y;
}
const int N=100005;
struct point
{
	int x,y;
}a[N];
int calc(point a,point b,point c)
{
	point d,e;
	d.x=a.x-b.x;
	d.y=a.y-b.y;
	e.x=c.x-b.x;
	e.y=c.y-b.y;
	return d.x*e.x+d.y*e.y;
}
int n,b[N],f[N],cnt,p;
signed main()
{
	read(n);
	srand(time(0));
	for (int i=1;i<=n;++i)
	{
		read(a[i].x);
		read(a[i].y);
	}
	while (true)
	{
		for (int i=1;i<=n;++i)
			b[i]=i;
		cnt=0;
		for (int t=1;t<=2000000;++t)
		{
			p=rand()%(n-cnt)+1;
			if (cnt<=1||calc(a[f[cnt-1]],a[f[cnt]],a[b[p]])>0)
			{
				f[++cnt]=b[p];
				swap(b[p],b[n-cnt+1]);
				if (cnt==n)
				{
					for (int i=1;i<=n;++i)
						printf("%d ",f[i]);
					return 0;
				}
			}
		}
	}
	return 0;
}
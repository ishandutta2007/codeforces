#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline void read(ll &x)
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
inline void write(ll x)
{
	int a[20];
	a[0]=0;
	if (x==0)
		putchar('0');
	while (x)
	{
		a[++a[0]]=x%10;
		x/=10;
	}
	while (a[0])
		putchar('0'+a[a[0]--]);
	putchar('\n');
}
const int N=30005;
const ll inf=1e18+7;
struct data
{
	ll x;
	int id;
	bool operator<(const data &a)const
	{
		return x>a.x;
	}
}a[N],b[N];
int pa[N],pb[N],ban[N],n,x,y,q;
ll w[N][4],f[N];
void max(ll &x,const ll &y)
{
	x<y?x=y:0;
}
int main()
{
	read(n);
	read(q);
	for (int i=1;i<=n;++i)
	{
		read(a[i].x);
		a[i].id=i;
	}
	for (int i=1;i<=n;++i)
	{
		read(b[i].x);
		b[i].id=i;
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	for (int i=1;i<=n;++i)
	{
		pa[a[i].id]=i;
		pb[b[i].id]=i;
	}
	for (int i=1;i<=n;++i)
		ban[i]=pb[a[i].id];
	for (int i=1;i<=n;++i)
	{
		w[i][3]=w[i][1]=w[i][2]=-inf;
		if (ban[i]!=i)
			w[i][1]=a[i].x*b[i].x;
		if (i>=2&&ban[i-1]!=i&&ban[i]!=i-1)
			w[i][2]=a[i-1].x*b[i].x+a[i].x*b[i-1].x;
		if (i>=3&&ban[i-2]!=i-1&&ban[i-1]!=i&&ban[i]!=i-2)
			w[i][3]=a[i-2].x*b[i-1].x+a[i-1].x*b[i].x+a[i].x*b[i-2].x;
		if (i>=3&&ban[i-2]!=i&&ban[i-1]!=i-2&&ban[i]!=i-1)
			max(w[i][3],a[i-2].x*b[i].x+a[i-1].x*b[i-2].x+a[i].x*b[i-1].x);
	}
	while (q--)
	{
		read(x);
		read(y);
		x=pa[x];
		y=pa[y];
		swap(ban[x],ban[y]);
		for (int i=max(1,x-5);i<=min(n,x+5);++i)
		{
			w[i][3]=w[i][1]=w[i][2]=-inf;
			if (ban[i]!=i)
				w[i][1]=a[i].x*b[i].x;
			if (i>=2&&ban[i-1]!=i&&ban[i]!=i-1)
				w[i][2]=a[i-1].x*b[i].x+a[i].x*b[i-1].x;
			if (i>=3&&ban[i-2]!=i-1&&ban[i-1]!=i&&ban[i]!=i-2)
				w[i][3]=a[i-2].x*b[i-1].x+a[i-1].x*b[i].x+a[i].x*b[i-2].x;
			if (i>=3&&ban[i-2]!=i&&ban[i-1]!=i-2&&ban[i]!=i-1)
				max(w[i][3],a[i-2].x*b[i].x+a[i-1].x*b[i-2].x+a[i].x*b[i-1].x);
		}
		for (int i=max(1,y-5);i<=min(n,y+5);++i)
		{
			w[i][3]=w[i][1]=w[i][2]=-inf;
			if (ban[i]!=i)
				w[i][1]=a[i].x*b[i].x;
			if (i>=2&&ban[i-1]!=i&&ban[i]!=i-1)
				w[i][2]=a[i-1].x*b[i].x+a[i].x*b[i-1].x;
			if (i>=3&&ban[i-2]!=i-1&&ban[i-1]!=i&&ban[i]!=i-2)
				w[i][3]=a[i-2].x*b[i-1].x+a[i-1].x*b[i].x+a[i].x*b[i-2].x;
			if (i>=3&&ban[i-2]!=i&&ban[i-1]!=i-2&&ban[i]!=i-1)
				max(w[i][3],a[i-2].x*b[i].x+a[i-1].x*b[i-2].x+a[i].x*b[i-1].x);
		}
		f[1]=f[0]+w[1][1];
		f[2]=f[1]+w[2][1];
		max(f[2],f[0]+w[2][2]);
		for (int i=3;i<=n;++i)
		{
			f[i]=f[i-1]+w[i][1];
			max(f[i],f[i-2]+w[i][2]);
			max(f[i],f[i-3]+w[i][3]);
		}
		write(f[n]);
	}
	return 0;
}
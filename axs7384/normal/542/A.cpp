#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ll long long
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
const int N=200005,inf=1e9+7;
int n,m,cnt,x1,x2,l,r,c;
ll ans;
struct data
{
	int l,r,id;
	bool operator<(const data &a)const
	{
		return l!=a.l?l<a.l:r>a.r;
	}
}a[N],b[N];
int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	read(n);
	read(m);
	for (int i=1;i<=n;++i)
	{
		read(a[i].l);
		read(a[i].r);
		a[i].id=i;
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;++i)
		if (a[i].r>b[cnt].r)
			b[++cnt]=a[i];
	n=cnt;
	for (int i=1;i<=m;++i)
	{
		read(l);
		read(r);
		read(c);
		int p=lower_bound(b+1,b+1+n,data{l,-1,-1})-b-1;
		if (!p)
			++p;
		for (;p<=n&&b[p].l<=r;++p)
		{
			ll val=(ll)(min(b[p].r,r)-max(b[p].l,l))*c;
			if (val>ans)
			{
				ans=val;
				x1=b[p].id;
				x2=i;
			}
		}
	}
	if (!ans)
		putchar('0');
	else
		cout<<ans<<'\n'<<x1<<' '<<x2;
	return 0;
}
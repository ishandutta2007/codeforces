#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
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
inline void gg()
{
	puts("no");
	exit(0);
}
const int N=5005;
int n,m,t,mi;
char d[N][N];
pair<int,int>a[N];
int main()
{
	read(m);
	read(n);
	mi=2*m;
	for (int i=m-n+1;i<=m;++i)
	{
		read(a[i].first);
		a[i].second=i;
		t+=a[i].first;
		mi=min(mi,a[i].first);
	}
	if (t>m*(m-1))
		gg();
	t=m*(m-1)-t;
	for (int i=1;i<=m-n;++i)
		a[i]=mp(t/(m-n)+(i<=t%(m-n)),i);
	if (m-n&&a[1].first>mi)
		gg();
	sort(a+1,a+m+1);
	t=0;
	for (int i=1;i<=m;++i)
	{
		t+=a[i].first;
		if (t<i*(i-1))
			gg();
	}
	for (int i=1;i<=m;++i)
		d[i][i]='X';
	for (int i=m;i;--i)
	{
		sort(a+1,a+i+1);;
		t=a[i].first;
		for (int j=1;j<i;++j)
			if (t>1)
			{
				t-=2;
				d[a[i].second][a[j].second]='W';
				d[a[j].second][a[i].second]='L';
			}
			else
			{
				if (t==1)
				{
					--t;
					--a[j].first;
					d[a[i].second][a[j].second]=d[a[j].second][a[i].second]='D';
				}
				else
				{
					a[j].first-=2;
					d[a[i].second][a[j].second]='L';
					d[a[j].second][a[i].second]='W';
				}
			}
		a[i].first=0;
	}
	puts("YES");
	for (int i=1;i<=m;++i)
		puts(d[i]+1);
	return 0;
}
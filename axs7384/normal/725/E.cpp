#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
const int N=200000;
pair<int,int>b[N];
int a[N],n,m,x,p[N],tot;
inline bool work(int x)
{
	int k=n,c=0;
	for (int i=p[k];i;)
	{
		if (!c&&b[i].first<=x&&k>=x)
		{
			k-=x;
			c=1;
		}
		if (k>=b[i].first*b[i].second)
			k-=b[i].first*b[i].second;
		else
			k%=b[i].first;
		i=min(p[k],i-1);
	}
	return k!=0;
}
int main()
{
	//freopen("g.in","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i)
	{
		scanf("%d",&x);
		++a[x];
	}
	for (int i=1;i<=n;++i)
		if (a[i])
		{
			b[++tot]=mp(i,a[i]);
			p[i]=tot;
		}
		else
			p[i]=p[i-1];
	for (int i=1;i<n;++i)
		if (work(i))
		{
			cout<<i;
			return 0;
		}
	puts("Greed is good");
	return 0;
}
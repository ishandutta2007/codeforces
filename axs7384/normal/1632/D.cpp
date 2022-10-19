#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int st[N][22],lg[N];
int n;
inline int ask(int l,int r)
{
	int LG=lg[r-l+1];
	return __gcd(st[l][LG],st[r-(1<<LG)+1][LG]);
}
int main()
{
	scanf("%d",&n);
	lg[1]=0;
	for (int i=2;i<=n;++i)
		lg[i]=lg[i>>1]+1;
	for (int i=1;i<=n;++i)
		scanf("%d",&st[i][0]);
	for (int i=1;i<=20;++i)
		for (int j=1;j+(1<<i)<=n+1;++j)
			st[j][i]=__gcd(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	int ans=0,lastr=-1,l=1;
	for (int i=1;i<=n;++i)
	{
		while (l<i&&ask(l,i)<i-l+1)
			++l;
		if (ask(l,i)==i-l+1&&l>lastr)
		{
			++ans;
			lastr=i;
		}
		printf("%d ",ans);
	}
	return 0;
}
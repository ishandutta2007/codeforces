#include<bits/stdc++.h>
using namespace std;
const int N=105;
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
int n,m;
int a[100005];
int main()
{
	read(n);
	read(m);
	for (int i=1;i<=n;++i)
		read(a[i]);
	int l=1;
	double ans=-1;
	for (int i=1;i<=n;++i)
	{
		while (a[l+1]<=a[i]+m&&l+1<=n)
			++l;
		if (l>=i+2)
			ans=max(ans,(double)(a[l]-a[i+1])/(double)(a[l]-a[i]));
		// cout<<i<<' '<<l<<' '<<(double)(a[l]-a[i+1])/(double)(a[l]-a[i])<<endl;
	}
	if (ans<0)
		puts("-1");
	else
		printf("%.10lf",ans);
	return 0;
}
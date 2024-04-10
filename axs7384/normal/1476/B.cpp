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
int n,K,t;
int a[N],b[N];
signed main()
{
	read(t);
	while (t--)
	{
		read(n);
		read(K);
		for (int i=1;i<=n;++i)
		{
			read(a[i]);
			b[i]=b[i-1]+a[i];
		}
		double ans=0;
		for (int i=2;i<=n;++i)
		{
			ans=max(ans,(double)a[i]*100.0/(double)K-b[i-1]);
		}
		int p=(int)(ans+1-1e-7);
		cout<<p<<endl;
	}
	return 0;
}
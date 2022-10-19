#include<bits/stdc++.h>
using namespace std;
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
int t,n,m,x;
int a[100][2000];
int main()
{
	for (int i=1;i<=9;++i)
		a[i][0]=1;
	for (int K=1;K<=9;++K)
	{
		for (int i=1;i<=999;++i)
			for (int j=i;j;--j)
				if (a[K][i-j]&&(j%10==K||(j/10)%10==K||j/100==K))
				{
					a[K][i]=1;
					break;
				}
	}
	read(t);
	while (t--)
	{
		read(n);
		read(m);
		for (int i=1;i<=n;++i)
		{
			read(x);
			puts(x>999||a[m][x]?"YES":"NO");
		}
	}
	return 0;
}
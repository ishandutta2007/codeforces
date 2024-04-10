#include<bits/stdc++.h>
using namespace std;
inline void read(int &x)
{
	x=0;
	char c=getchar();
	while (c>'9'||c<'0')
		c=getchar();
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
int n,f[1505][30],m,x;
char c[1505];
int main()
{
	//freopen("c.in","r",stdin);
	//freopen("c.out","w",stdout);
	read(n);
	for (int i=1;i<=n;++i)
	{
		char ch=getchar();
		while (ch>'z'||ch<'a')
			ch=getchar();
		c[i]=ch;
	}
	for (int i=0;i<=n;++i)
	{
		for (int j=0;j<=25;++j)
		{
			char ch='a'+j;
			int ans=0;
			int x=0,sum=i;
			while (sum>=0)
			{
				++x;
				if (c[x]!=ch)
					--sum;
			}
			--x;
			ans=x;
			for (int k=2;k<=n;++k)
				if (c[k-1]!=ch)
				{
					if (i!=0)
						sum=1;
					else
						sum=0;
					if (x<k)
						x=k-1;
					while (sum>=0)
					{
						++x;
						if (c[x]!=ch)
							--sum;
					}
					--x;
					ans=max(ans,x-k+1);
					if (x>=n)
						break;
				}
			f[i][j]=min(n,ans);
		}
	}
	read(m);
	for (int i=1;i<=m;++i)
	{
		read(x);
		char ch=getchar();
		while (ch==' ')
			ch=getchar();
		printf("%d\n",f[x][ch-'a']);
	}
	return 0;
}
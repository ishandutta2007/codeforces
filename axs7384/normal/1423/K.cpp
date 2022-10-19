#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline void read(int &x)
{
	char c=getchar();
	while (c>'9'||c<'0')
		c=getchar();
	x=0;
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
const int N=1100005;
int n,m,cnt;
int b[N+5],a[N],f[N],p[N],pri[N];
inline void prework()
{
	f[1]=1;
	for (int i=2;i<=N;++i)
	{
		if (!b[i])
		{
			pri[++cnt]=i;
			++f[i];
			if ((ll)i*i<=N)
				--f[i*i];
		}
		//else
		//{
			//++f[i];
			//if (i+b[i]<=N)
			//	--f[i+b[i]];
		//}
		for (int j=1;j<=cnt&&i*pri[j]<=N;++j)
		{
			b[i*pri[j]]=pri[j];
			if (i%pri[j]==0)
				break;
		}
	}
	for (int i=2;i<=N;++i)
		f[i]+=f[i-1];
}
inline bool cmp(int x,int y)
{
	return a[x]<a[y];
}
int main()
{
	prework();
	read(n);
	for (int i=1;i<=n;++i)
		read(a[i]);
	for (int i=1;i<=n;++i)
		printf("%d\n",f[a[i]]);
}
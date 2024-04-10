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
inline void write(int x)
{
	static int a[10];
	a[0]=0;
	if (x==0)
		putchar('0');
	while (x)
	{
		a[++a[0]]=x%10;
		x/=10;
	}
	while (a[0])
		putchar(a[a[0]--]+'0');
}
const int N=17;
char c[100];
int a[N],b[N],s[2][1<<N],f[1<<N][125],n,sa,sb,p[N];
int main()
{
	read(n);
	for (int i=1;i<=n;++i)
	{
		scanf("%s",c);
		read(a[i]);
		read(b[i]);
		sa+=a[i];
		sb+=b[i];
		p[i]=c[0]=='R';
	}
	for (int i=0;i<(1<<n);++i)
		for (int j=1;j<=n;++j)
			if (i&(1<<(j-1)))
				++s[p[j]][i];
	memset(f,-1,sizeof(f));
	f[0][0]=0;
	for (int i=0;i<(1<<n);++i)
		for (int j=0;j<=120;++j)
			if (f[i][j]>=0)
				for (int k=1;k<=n;++k)
					if (!(i&(1<<(k-1))))
						f[i|(1<<(k-1))][j+min(s[1][i],a[k])]=max(f[i|(1<<(k-1))][j+min(s[1][i],a[k])],f[i][j]+min(b[k],s[0][i]));
	int ans=1e9+7,p=(1<<n)-1;
	for (int i=0;i<=120;++i)
		if (f[p][i]>=0)
			ans=min(ans,max(sa-i,sb-f[p][i])+n);
	write(ans);
}
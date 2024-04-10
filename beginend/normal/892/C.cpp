#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=2005;
const int inf=1000000000;

int n,a[N],f[N][N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int gcd(int x,int y)
{
	if (!y) return x;
	else return gcd(y,x%y);
}

int main()
{
	n=read();int mn=inf;
	for (int i=1;i<=n;i++) a[i]=read(),f[i][i]=a[i],mn=min(mn,a[i]);
	if (mn==1)
	{
		int ans=0;
		for (int i=1;i<=n;i++) if (a[i]>1) ans++;
		printf("%d",ans);
		return 0;
	}
	int len=n+1;
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
		{
			f[i][j]=gcd(f[i][j-1],a[j]);
			if (f[i][j]==1) {len=min(len,j-i+1);break;}
		}
	if (len==n+1) puts("-1");
	else printf("%d",len-1+n-1);
	return 0;
}
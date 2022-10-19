#include<bits/stdc++.h>
using namespace std;
const int N=4005,M=100;
bool v[2100][M*2][M][2];
int f[2100][M*2][M][2],a[N],b[N],n;
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
inline void write(int x)
{
	static int a[10];
	a[0]=0;
	if (x<0)
	{
		x=-x;
		putchar('-');
	}
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
int dfs0(int l,int r,int k);
int dfs1(int l,int r,int k)
{
	int d=M+l+r-n;
	if (v[l][d][k][1])
		return f[l][d][k][1];
	v[l][d][k][1]=1;
	if (l+k-1==r)
		return f[l][d][k][1]=-b[r]+b[l-1];
	if (l+k-1>r)
		return f[l][d][k][1]=0;
	int s1=dfs0(l,r-k,k)-b[r]+b[r-k];
	int s2=dfs0(l,r-k-1,k+1)-b[r]+b[r-k-1];
	return f[l][d][k][1]=min(s1,s2);
}
int dfs0(int l,int r,int k)
{
	int d=M+l+r-n;
	if (v[l][d][k][0])
		return f[l][d][k][0];
	v[l][d][k][0]=1;
	if (l+k-1==r)
		return f[l][d][k][0]=b[r]-b[l-1];
	if (l+k-1>r)
		return f[l][d][k][0]=0;
	int s1=dfs1(l+k,r,k)+b[l+k-1]-b[l-1];
	int s2=dfs1(l+k+1,r,k+1)+b[l+k]-b[l-1];
	//cout<<s1<<' '<<s2<<'\n';
	return f[l][d][k][0]=max(s1,s2);
}
int main()
{
	read(n);
	for (int i=1;i<=n;++i)
	{
		read(a[i]);
		b[i]=b[i-1]+a[i];
	}
	write(dfs0(1,n,1));
	return 0;
}
#include<cstdio>
#include<cstring>
int n,n1,h,l,r,x,ans=0;
int a[2002];
int f[2][2002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int max(int a,int b)
{
	return a>b? a:b;
}
int main()
{
	memset(f[0],-1,sizeof(f[0])),f[0][0]=0;
	read(n),read(h),read(l),read(r);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1,i0=0,i1=1;i<=n;++i,i0^=1,i1^=1)
	{
		memset(f[i1],-1,sizeof(f[i1]));
		for(int j=0;j<l;++j)
		{
			x=f[i0][(j-a[i]+h)%h];
			if(x!=-1)f[i1][j]=max(f[i1][j],x);
			x=f[i0][(j-a[i]+1+h)%h];
			if(x!=-1)f[i1][j]=max(f[i1][j],x);
		}
		for(int j=l;j<=r;++j)
		{
			x=f[i0][(j-a[i]+h)%h];
			if(x!=-1)f[i1][j]=max(f[i1][j],x+1);
			x=f[i0][(j-a[i]+1+h)%h];
			if(x!=-1)f[i1][j]=max(f[i1][j],x+1);
		}
		for(int j=r+1;j<h;++j)
		{
			x=f[i0][(j-a[i]+h)%h];
			if(x!=-1)f[i1][j]=max(f[i1][j],x);
			x=f[i0][(j-a[i]+1+h)%h];
			if(x!=-1)f[i1][j]=max(f[i1][j],x);
		}
	}
	n1=n&1;
	for(int i=0;i<h;++i)ans=max(ans,f[n1][i]);
	printf("%d",ans);
	return 0;
}
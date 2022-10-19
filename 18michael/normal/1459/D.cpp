#include<cstdio>
#define inf 1000000
int n,tota=0,totb=0,t=0;
int a[102],b[102];
double res[102];
double f[102][10002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline double min(double a,double b)
{
	return a<b? a:b;
}
inline double max(double x,double y)
{
	return x>y? x:y;
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)read(a[i]),read(b[i]),tota+=a[i],totb+=b[i],res[i]=inf;
	for(int i=0;i<=n;++i)
		for(int j=0;j<=tota;++j)
			f[i][j]=inf;
	f[0][0]=0,res[0]=tota-totb;
	for(int i=1;i<=n;++i)
	{
		t+=a[i];
		for(int k=i;k;--k)
			for(int j=a[i];j<=t;++j)
				f[k][j]=min(f[k][j],f[k-1][j-a[i]]+1.0*b[i]/2),res[k]=min(res[k],max(j,f[k][j]+tota-totb));
	}
	for(int i=1;i<=n;++i)printf("%lf ",tota-res[n-i]);
	return 0;
}
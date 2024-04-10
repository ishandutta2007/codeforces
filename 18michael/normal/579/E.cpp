#include<bits/stdc++.h>
#define eps 1e-15
using namespace std;
int n;
int a[200002];
double b[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline double Min(double a,double b)
{
	return a<b? 1:0;
}
inline double Max(double a,double b)
{
	return a>b? 1:0;
}
inline double calc(double x)
{
	double ans=0,mn=0,mx=0;
	//printf("CALC %lf\n",x);
	for(int i=1;i<=n;++i)b[i]=a[i]-x;
	//for(int i=1;i<=n;++i)printf("%lf%c",a[i],i==n? '\n':' ');
	for(int i=2;i<=n;++i)b[i]+=b[i-1];
	for(int i=1;i<=n;++i)mn=min(mn,b[i]),mx=max(mx,b[i]);
	//for(int i=1;i<=n;++i)
	//	for(int j=i;j<=n;++j)
	//		ans=(fabs(b[j]-b[i-1])>ans? fabs(b[j]-b[i-1]):ans);
	return mx-mn;
}
inline double Trichotomy()
{
	double l=-10000,r=10000,l1,r1,fl1,fr1;
	while(r-l>eps)
	{
		l1=(2*l+r)/3,r1=(l+2*r)/3,fl1=calc(l1),fr1=calc(r1);
		//printf("%lf %lf %lf %lf\n",l,r,l1,r1);
		if(fl1>fr1)l=l1;else r=r1;
	}
	return fl1;
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	printf("%.10lf",Trichotomy());
	return 0;
}
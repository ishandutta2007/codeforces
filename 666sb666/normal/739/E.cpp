#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,x,y,A[N],B[N];
double a[N],b[N],f[N];
inline void update(double&a,int&b,int&c,double A,int B,int C)
{
	if(A>a)a=A,b=B,c=C;
}
inline void solve(double x,double y)
{
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];A[i]=A[i-1];B[i]=B[i-1];
		update(f[i],A[i],B[i],f[i-1]+a[i]-x,A[i-1]+1,B[i-1]);
		update(f[i],A[i],B[i],f[i-1]+b[i]-y,A[i-1],B[i-1]+1);
		update(f[i],A[i],B[i],f[i-1]+1-(1-a[i])*(1-b[i])-x-y,A[i-1]+1,B[i-1]+1);
	}
}
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n;i++)scanf("%lf",&a[i]);
	for(int i=1;i<=n;i++)scanf("%lf",&b[i]);
	double l=0,r=1,L,R;
	for(int tt=0;tt<50;tt++)
	{
		double mid=(l+r)/2;
		L=0,R=1;
		for(int ttt=0;ttt<50;ttt++)
		{
			double Mid=(L+R)/2;
			solve(mid,Mid);
			if(B[n]>y)L=Mid;else R=Mid;
		}
		solve(mid,R);
		if(A[n]>x)l=mid;else r=mid;
	}
	solve(r,R);
	printf("%.10lf\n",f[n]+l*x+L*y);
	return 0;
}
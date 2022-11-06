#include<bits/stdc++.h>
using namespace std;
int n,x[100005],y[100005];
bool chk(long double rr)
{
	long double l=-1e9,r=1e9;
	for(int i=1;i<=n;i++)
	{
		long double xx=x[i],yy=y[i];
		if(rr<yy)return 0;
		long double t=sqrt(yy)*sqrt(rr-yy);
		l=max(l,xx-t);r=min(r,xx+t);
	}
	return l<=r;
}
int main()
{
	scanf("%d",&n);int f1=0,f2=0;
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;i++)if(y[i]>0)f1=1;else f2=1;
	for(int i=1;i<=n;i++)y[i]=abs(y[i]);
	if(f1&&f2){puts("-1");return 0;}
	long double l=0,r=1000000000000000.0;
	while(fabs((double)(r-l))>1e-7)
	{
//		cout<<l<<" "<<r<<" "<<fabs(r-l)<<endl;
//	printf("%.10lf ",double(l));
//	printf("%.10lf ",double(r));
//	printf("%.10lf\n",double(r-l));
		long double mid=l+(r-l)*0.5;
		double x=mid-l;
		if(x<1e-7)break;
//	printf("%.10lf ",double(l));
//	printf("%.10lf ",double(r));
//	printf("%.10lf ",double(mid));
		if(chk(mid))r=mid;else l=mid;
	}
	printf("%.10lf\n",double(l*0.5));
	return 0;
}
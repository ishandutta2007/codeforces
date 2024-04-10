#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	double lo=0;
	double hi=1e11;
	for(int i=0;i<200;i++)
	{
		double mi=(lo+hi)/2;
		double amin=a-mi;
		double bmin=b-mi;
		double cmin=c-mi;
		double dmin=d-mi;
		double amax=a+mi;
		double bmax=b+mi;
		double cmax=c+mi;
		double dmax=d+mi;
		double admin=min(min(amin*dmin,amin*dmax),min(amax*dmin,amax*dmax));
		double admax=max(max(amin*dmin,amin*dmax),max(amax*dmin,amax*dmax));
		double bcmin=min(min(bmin*cmin,bmin*cmax),min(bmax*cmin,bmax*cmax));
		double bcmax=max(max(bmin*cmin,bmin*cmax),max(bmax*cmin,bmax*cmax));
		if(admin > bcmax || bcmin > admax) lo=mi;
		else hi=mi;
	}
	printf("%.12f",lo);
}
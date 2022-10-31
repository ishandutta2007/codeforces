#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#define inf 1e10
#define eps 1e-7
using namespace std;
inline double fix(double a){
	if(a<0) return inf;
	else return a;
}
inline bool iszero(double a){
	return a<eps&&a>-eps;
}
double solve(double coe[]){
	if(iszero(coe[2])&&iszero(coe[1])){
		if(iszero(coe[0])) return 0;
		else return inf;
	}
	if(iszero(coe[2])) return fix(1.0*coe[0]/coe[1]);
	double det=coe[1]*coe[1]-4*coe[0]*coe[2];
	if(det<0) return inf;
	double bs=-0.5*coe[1]/coe[2],ad=0.5*sqrt(det)/coe[2];
	return min(fix(bs+ad),fix(bs-ad));
}
int main(){
	double a[4],b[4];
	double coe[3];
	int i,j;
	double ans=inf;
	scanf("%lf%lf%lf%lf",&a[0],&a[1],&a[2],&a[3]);
	for(i=0;i<16;i++){
		for(j=0;j<4;j++){
			if(i&(1<<j)){
				b[j]=1;
			}
			else b[j]=-1;
		}
		coe[0]=a[0]*a[3]-a[1]*a[2];
		coe[1]=a[0]*b[0]+a[3]*b[3]-a[1]*b[1]-a[2]*b[2];
		coe[2]=b[0]*b[3]-b[1]*b[2];
		ans=min(ans,solve(coe));
	}
	ans=min(ans,1.0*max(abs(a[0]),abs(a[1])));
	ans=min(ans,1.0*max(abs(a[2]),abs(a[3])));
	printf("%.12f\n",ans);
	return 0;
}
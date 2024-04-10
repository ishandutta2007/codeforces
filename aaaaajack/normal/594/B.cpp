#include<cstdio>
#include<cmath>
using namespace std;
const double PI=acos(-1);
int main(){
	int n,r,v;
	scanf("%d%d%d",&n,&r,&v);
	double om=1.0*v/r;
	for(int i=0;i<n;i++){
		int s,f;
		scanf("%d%d",&s,&f);
		double lb=0,rb=1.0*(f-s)/v;
		for(int j=0;j<100;j++){
			double m=(lb+rb)/2,d=v*m+fabs(2*r*sin(om/2*m));
			if(d>f-s) rb=m;
			else lb=m;
		}
		printf("%.12f\n",lb);
	}
	return 0;
}
#include <stdio.h>
#include <algorithm>

const double EPS=1e-11;

int n,sx,sy,ex,ey;
int x[100000],y[100000],vx[100000],vy[100000];

inline int abs(int a) {
	return (a<0)?-a:a;
}
int main() {
	scanf("%d",&n);
	scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
	if(sx>ex) std::swap(sx,ex);
	if(sy>ey) std::swap(sy,ey);
	for(int i=0;i<n;i++)
		scanf("%d %d %d %d",x+i,y+i,vx+i,vy+i);

	double st=0,fi=987654321;
	for(int i=0;i<n;i++) {
		if(vx[i]==0) {
			if(x[i]<=sx||x[i]>=ex){
				printf("-1\n");
				return 0;
			}
		}
		else {
			double m1=(double)(sx-x[i])/vx[i],m2=(double)(ex-x[i])/vx[i];
			if(m1>m2)std::swap(m1,m2);
			st=std::max(st,m1);
			fi=std::min(fi,m2);
		}

		if(vy[i]==0) {
			if(y[i]<=sy||y[i]>=ey) {
				printf("-1\n");
				return 0;
			}
		}
		else {
			double m1=(double)(sy-y[i])/vy[i],m2=(double)(ey-y[i])/vy[i];
			if(m1>m2)std::swap(m1,m2);
			st=std::max(st,m1);
			fi=std::min(fi,m2);
		}
	}
	if(st<0) st=0;
	if(st+EPS<fi) {
		printf("%.8lf\n",st);
	}
	else 
		printf("-1\n");

	return 0;
}
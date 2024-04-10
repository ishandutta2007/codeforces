#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define inf 10000.0
using namespace std;
typedef long long ll;
double n,r,x[1005],y[1005];
double get_y(int nx,int num){
	double min_dis=inf,j=0,y_=-1.0;
	bool fl=0;
	for(int i=1;i<num;i++){
		double t=abs(x[num]-x[i]);
		if(t<=2*r){
			double tt=sqrt(2*r*2*r-t*t)+y[i];
			if(y_<tt){
				fl=1;
				y_=tt;
			}
		}
	}
	if(fl) return y[num]=y_;
	else return y[num]=r;
}
int main(){
	scanf("%lf%lf",&n,&r);
	for(int i=1;i<=n;i++){
		scanf("%lf",&x[i]);
	}
	for(int i=1;i<=n;i++){
		printf("%lf",get_y(x[i],i));
		if(i==n) printf("\n");
		else printf(" ");
	}
	return 0;
}
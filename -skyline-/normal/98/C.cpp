#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int l,a,b;
double f(double x){return a*sin(x)+b*cos(x)-l*sin(x)*cos(x);}
int main(){
	scanf("%d%d%d",&a,&b,&l);
	if(a>b)swap(a,b);
	if(l<=b){
		printf("%d\n",min(a,l));
		return 0;
	}
	double x=0,y=3.1415926535897932384626433832795*0.5;
	for(int _=0;_<200;++_){
		double X=(x*2.0+y)/3.0,Y=(x+y*2.0)/3.0;
		if(f(X)<f(Y))y=Y;
		else x=X;
	}
	double ans=f(x);
	if(ans<1e-8)puts("My poor head =(");
	else printf("%.10lf\n",ans);
    return 0;
}
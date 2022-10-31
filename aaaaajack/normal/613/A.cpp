#include<cstdio>
#include<cmath>
#define N 100100
using namespace std;
struct point{
	long long x,y;
	point(){}
	point(long long _x,long long _y):x(_x),y(_y){}
	point operator+(const point& rhs)const{return point(x+rhs.x,y+rhs.y);}
	point operator-(const point& rhs)const{return point(x-rhs.x,y-rhs.y);}
	long long operator*(const point& rhs)const{return x*rhs.x+y*rhs.y;}
	long long operator^(const point& rhs)const{return x*rhs.y-y*rhs.x;}
	long long len2()const{return x*x+y*y;}
	double len(){return sqrt(len2());}
}p[N];
int main(){
	point o;
	int n;
	scanf("%d%I64d%I64d",&n,&o.x,&o.y);
	double s,l;
	for(int i=0;i<n;i++){
		scanf("%I64d%I64d",&p[i].x,&p[i].y);
		double tmp=(p[i]-o).len();
		if(!i||tmp<s) s=tmp;
		if(!i||tmp>l) l=tmp;
	}
	p[n]=p[0];
	for(int i=0;i<n;i++){
		if((o-p[i])*(p[i+1]-p[i])>=0&&(o-p[i+1])*(p[i]-p[i+1])>=0){
			double tmp=fabs(((p[i]-o)^(p[i+1]-o))/(p[i+1]-p[i]).len());
			if(tmp<s) s=tmp;
		}
	}
	printf("%.12f\n",acos(-1)*(l*l-s*s));
	return 0;
}
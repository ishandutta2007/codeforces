#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
const double eps=1e-8;
struct point{
	double x,y;
	point(double _x=0,double _y=0){x=_x;y=_y;}
	bool operator == (const point &a)const{
		return abs(x-a.x)<eps&&abs(y-a.y)<eps;
	}
	friend istream& operator >> (istream& in,point &a){
  		scanf("%lf%lf",&a.x,&a.y);
		return in;
	}
};
struct xl{
	double x,y;
	xl(point a=point(0,0),point b=point(0,0)){x=b.x-a.x;y=b.y-a.y;}
	xl(double a=0,double b=0){x=a;y=b;}
	xl operator * (const double &a)const{
		return xl(x*a,y*a);
	}
	xl operator *= (const double &a){
		return *this=*this*a;
	}
	xl operator / (const double &a)const{
		return xl(x/a,y/a);
	}
	xl operator /= (const double &a){
		return *this=*this/a;
	}
	friend xl xz(const xl t,const double a){
		double p=sin(a),q=cos(a);
		return xl(t.x*q-t.y*p,t.x*p+t.y*q);
	}
};
point operator + (const point &a,const xl &b){
	return point(a.x+b.x,a.y+b.y);
}
point operator += (point &a,const xl &b){
	return a=a+b;
}
double dis(point a,point b){double dx=a.x-b.x,dy=a.y-b.y;return sqrt(dx*dx+dy*dy);}
double cj(xl a,xl b){return a.x*b.y-b.x*a.y;}
double dj(xl a,xl b){return a.x*b.x+a.y*b.y;}
bool p_l(point x,point a,point b){//0: 1: 
	xl ax=xl(a,x),bx=xl(b,x);
	return cj(ax,bx)>-eps&&cj(ax,bx)<eps;
}
bool p_s(point x,point a,point b){//0: 1: 
	return p_l(x,a,b)&&dj(xl(x,a),xl(x,b))<eps;
}
int l_l(point a,point b,point c,point d){//0: 1: 2:
	if(p_l(c,a,b)&&p_l(d,a,b))return 0;
	xl ab=xl(a,b),cd=xl(c,d);
	if(cj(ab,cd)>-eps&&cj(ab,cd)<eps)return 1;
	return 2;
}
int l_s(point a,point b,point c,point d){//0: 1:
	xl ab=xl(a,b),ac=xl(a,c),ad=xl(a,d);
	return cj(ab,ac)*cj(ab,ad)>eps;
}
int s_s(point a,point b,point c,point d){//0: 1:
	if(p_l(c,a,b)&&p_l(d,a,b))return p_s(c,a,b)||p_s(d,a,b)||p_s(a,c,d)||p_s(b,c,d);
	xl ab=xl(a,b),ac=xl(a,c),ad=xl(a,d),ca=xl(c,a),cb=xl(c,b),cd=xl(c,d);
	return cj(ab,ac)*cj(ab,ad)<eps&&cj(cd,ca)*cj(cd,cb)<eps;
}
point jd(point a,point b,point c,point d){// ab,cd  
	double s1=cj(xl(a,d),xl(a,c)),s2=cj(xl(b,c),xl(b,d));
	return a+xl(a,b)*s1/(s1+s2);
}
double S(int n,point a[]){// 0 
	if(n==1||n==2)return 0;
	double s=0;
	for(int i=0;i<n;i++)s+=cj(xl(point(),a[i]),xl(point(),a[(i+1)%n]))/2;
	return s;
}
int inside(int n,point a[],point x){// 0   0:,1:,2: 
	bool ans=0;
	for(int i=0;i<n;i++){
		if(p_s(x,a[i],a[(i+1)%n]))return 1;
		double d1=a[i].y-x.y,d2=a[(i+1)%n].y-x.y,res=cj(xl(x,a[i]),xl(x,a[(i+1)%n]));
		if((res>eps&&d1>-eps&&d2<-eps)||(res<-eps&&d1<-eps&&d2>-eps))ans^=1;
	}
	if(ans)return 2;
	return 0;
}
double dis(point a,point b,point x){
	return abs(cj(xl(x,a),xl(x,b)))/dis(a,b);
}
void qd(point o,double r,point p,point &a,point &b){// 
	double d=dis(o,p),x=sqrt(d*d-r*r),cosp=(d*d+x*x-r*r)/(2*d*x);
	a=p+xz(xl(p,o),acos(cosp))/d*x;
	b=p+xz(xl(p,o),-acos(cosp))/d*x;
}
int c_l(point o,double r,point a,point b){// 
	double d=abs(cj(xl(o,a),xl(o,b)))/dis(a,b);
	if(abs(d-r)<eps)return 1;
	if(d>r+eps)return 0;
	return 1;
}
point cz(point a,point b,point x){
	double d=dis(a,b,x),p=dis(a,x),q=sqrt(p*p-d*d),cosx=(p*p+d*d-q*q)/(2*p*d);
	point n=x+xz(xl(x,a),acos(cosx))/p*d;
	point m=x+xz(xl(x,a),-acos(cosx))/p*d;
	return p_l(n,a,b)?n:m;
}
void jd(point o,double r,point a,point b,point &n,point &m){// 
	point p=cz(a,b,o);
	double d=dis(o,p),x=sqrt(r*r-d*d),coso=(d*d+r*r-x*x)/(2*d*r);
	n=o+xz(xl(o,p),acos(coso))/d*r;
	m=o+xz(xl(o,p),-acos(coso))/d*r;
}
int n;
bool vis[5001];
point a[5001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)cin>>a[i];
	int now=1;printf("%d ",now);vis[1]=1;
	for(int i=1;i<n;i++){
		int maxx=now;
		for(int j=1;j<=n;j++)if(!vis[j]&&dis(a[now],a[j])>dis(a[now],a[maxx]))maxx=j;
		now=maxx;vis[now]=1;
		printf("%d ",now);
	}
	return 0;
}
#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>

using namespace std;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double EPS=1e-8;
const double PI=acos(-1);


template<class T>
struct point{
    T x,y;
    point() : x(0), y(0) {}
    point(const T& x,const T& y) : x(x), y(y) {}
    point operator+(const point &a)const{ return point(x+a.x,y+a.y); }
    point& operator+=(const point &a){x += a.x; y += a.y; return *this;}
    point operator-(const point &a)const{ return point(x-a.x,y-a.y); }
    point& operator-=(const point &a){x -= a.x; y -= a.y; return *this;}
    point operator*(const double a)const{ return point(a*x,a*y); }
    point& operator*=(const double a)const{ x *= a; y *= a; return *this;}
    point operator/(const double a)const{ return point(a/x,a/y); }
    point& operator/=(const double a)const{ x /= a; y /= a; return *this;}
	
	//rp
	bool operator<(const point &a)const{return (x != a.x) ? (x < a.x) : (y < a.y);}
 
};

template<class T> T SQ(T x){ return x*x; }
template<class T> T dist2(const point<T> &a,const point<T> &b){return SQ(a.x-b.x)+SQ(a.y-b.y);}
template<class T> T abs(const point<T>& p){return sqrt(SQ(p.x) + SQ(p.y));}
template<class T> T dot(const point<T>& a,const point<T>& b)
{return a.x*b.x + a.y*b.y;}
template<class T> T cross(const point<T>& a,const point<T>& b)
{return a.x*b.y - a.y*b.x;}
template<class T> point<T> rot(const point<T>& a,const double theta){
        return point<T>(a.x*cos(theta)-a.y*sin(theta),
			a.x*sin(theta)+a.y*cos(theta));
}

enum{CCW=1,CW=-1,ON=0};
template<class T>
int ccw(const point<T> &a,const point<T> &b,const point<T> &c){
    double rdir=cross(b-a,c-a);
    if(rdir> EPS) return CCW; //cab(v)
    if(rdir<-EPS) return CW; // cab(v)
    return ON; // a,b,c
}

template<class T>
struct segment{
    point<T> a,b;
    segment() : a(point<T>()), b(point<T>()) {}
    segment(const point<T>& a,const point<T>& b) : a(a), b(b) {}
};

bool intersect(const segment<double> &S1,const segment<double> &S2){
    if(max(S1.a.x,S1.b.x)+EPS<min(S2.a.x,S2.b.x)
    || max(S1.a.y,S1.b.y)+EPS<min(S2.a.y,S2.b.y)
    || max(S2.a.x,S2.b.x)+EPS<min(S1.a.x,S1.b.x)
    || max(S2.a.y,S2.b.y)+EPS<min(S1.a.y,S1.b.y)) return false;
    return ccw(S1.a,S1.b,S2.a)*ccw(S1.a,S1.b,S2.b)<=0
        && ccw(S2.a,S2.b,S1.a)*ccw(S2.a,S2.b,S1.b)<=0;
}

template<class T>
double dist2(const segment<T> &S,const point<T> &p){
    if(dot(S.b-S.a,p-S.a)<=0) return dist2(p,S.a);
    if(dot(S.a-S.b,p-S.b)<=0) return dist2(p,S.b);
    return (double)SQ(cross(S.b-S.a,p-S.a)) / dist2(S.a,S.b);
}

template<class T>
double dist(const segment<T> &S,const point<T> &p){
	return sqrt(dist2(S,p));
}

template<class T>
double dist(const segment<T> &S1,const segment<T> &S2){
    if(intersect(S1,S2)) return 0;
    return sqrt(min(min(dist2(S1,S2.a),dist2(S1,S2.b)),
                    min(dist2(S2,S1.a),dist2(S2,S1.b))));
}

template<class T>
std::ostream& operator<<(std::ostream& os, const point<T>& point){return ( os << '(' << point.x << ',' << point.y << ')' );}
template<class T>
std::ostream& operator<<(std::ostream& os, const segment<T>& seg){return ( os << '{' << seg.a << ',' << seg.b << '}' );}
 
typedef point<double> P;
typedef segment<double> S;

template<class T>
struct circle{
	point<T> c;
	T r;
	circle(){}
	circle(const point<T> &c, T& r) : c(c),r(r) {}
};

template<class T>
double arg(const point<T> &a){
	double t=atan2(a.y,a.x);
	return t<0?t+2*PI:t;
}

template<class T>
double geodist(point<T> a,point<T> b,const circle<T> &C){
	if(dist2(S(a,b),C.c) > SQ(C.r))
		return abs(a-b);

	a -= C.c; b -= C.c;

	double l1 = abs(a);
	double l_cos = acos(C.r/l1);
	double t1 = arg(a) + l_cos; if(t1 < 0) t1 += 2 * PI;
	double t2 = arg(a) - l_cos; if(t2 < 0) t2 += 2 * PI;

	double l2 = abs(b);
		   l_cos = acos(C.r/l2);
	double t3 = arg(b) + l_cos; if(t3 < 0) t3 += 2 * PI;
	double t4 = arg(b) - l_cos; if(t4 < 0) t4 += 2 * PI;

	double ret = 2 * PI;
	ret = min(ret,min(abs(t1-t4),2 * PI - abs(t1 - t4)) );
	ret = min(ret,min(abs(t2-t3),2 * PI - abs(t2 - t3)) );

	return ret * C.r + sqrt(SQ(l1) - SQ(C.r)) + sqrt(SQ(l2) - SQ(C.r));
}

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!

int main(){
	double va,vb,r;
	point<double> a,b;
	scanf("%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&va,&b.x,&b.y,&vb,&r);
	double R=abs(a);
	circle<double> C(P(0,0),r);

	double lo=0,hi=1e7;
	rep(_,70){
		double mi=(lo+hi)/2,t=mi;
		if(geodist(rot(a,va*t/R),b,C)<t * vb) hi=mi; else lo=mi;
	}
	printf("%.9f\n",(lo+hi)/2);

	return 0;
}
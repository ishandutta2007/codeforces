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
const int MODULO = 1000000009;
const int INF = 100000000; //1e8

using namespace std;

#define sz(v) ((int)v.size())
#define FOR(i,n) for(int i = 0; i < (n); i++)

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!


const double EPS (1e-9);
const double PI=acos(-1.0);

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
    point& operator*=(const double a){ x *= a; y *= a; return *this;}
    point operator/(const double a)const{ return point(x/a,y/a); }
    point& operator/=(const double a){ x /= a; y /= a; return *this;}
	
	//rp
	bool operator<(const point &a)const{return (x != a.x) ? (x < a.x) : (y < a.y);}
 
};

template<class T> T SQ(T x){ return x*x; }
template<class T> T dist2(const point<T> &a,const point<T> &b){return SQ(a.x-b.x)+SQ(a.y-b.y);}
template<class T> T abs2(const point<T>& p){return SQ(p.x) + SQ(p.y);}
template<class T> T abs(const point<T>& p){return sqrt(abs2(p));}
template<class T> T dot(const point<T>& a,const point<T>& b)
{return a.x*b.x + a.y*b.y;}
template<class T> T cross(const point<T>& a,const point<T>& b)
{return a.x*b.y - a.y*b.x;}
template<class T> point<T> rot(const point<T>& a,const double theta){
        return point<T>(a.x*cos(theta)-a.y*sin(theta),
			a.x*sin(theta)+a.y*cos(theta));
}
template<class T>
double arg(const point<T> &a){	double t=atan2(a.y,a.x); return t<0?t+2*PI:t; }

enum{CCW=1,CW=-1,ON=0};
template<class T>
int ccw(const point<T> &a,point<T> b,point<T> c){
	b -= a; c -= a;
    double rdir=cross(b,c);
    double len = abs(b) * abs(c); // (xOAu)
    if(rdir> EPS * len) return CCW; //cab(v)
    if(rdir<-EPS * len) return CW; // cab(v)
    return ON; // a,b,c
}

template<class T>
struct line{
    point<T> a,b;
    line() : a(point<T>()), b(point<T>()) {}
    line(const point<T>& a,const point<T>& b) : a(a), b(b) {}
};

template<class T>
double dist(const line<T> &L,const point<T> &p){
    return sqrt((double)SQ(cross(L.b-L.a,p-L.a)) / dist2(L.a,L.b));
}

typedef point<double> P;
typedef line<double> L;

double y_1,y_2,yw,xb,yb,_r;
bool C_high(double xw){
	double a = (yw - _r - yb) / (xb - xw);
	double h = yw - _r - a * xw;
	if(h >= y_2){
		return false;
	}
	L ln(P(xw,yw - _r),P(0,h));
	if(dist(ln,P(0,y_2)) > _r)
		return true;
	else
		return false;
}

bool C_low(double xw){
	double a = (yw - _r - yb) / (xb - xw);
	double h = yw - _r - a * xw;
	if(h <= y_1){
		return false;
	}
	if( h- y_1 >= _r)
		return true;
	else
		return false;
}

double low(){
	double l = 0,r = xb;
	while(r-l >= EPS){
		double xw = (r+l)/2;
		if (C_low(xw))
			l = xw;
		else
			r = xw;
	}
	return l;
}

int main()
{
	cin>>y_1>>y_2>>yw>>xb>>yb>>_r;

	double l = low();

	if(l + EPS >= xb || !C_high(l) ){
		puts("-1");
	} else {
		printf("%.15f\n",l);
	}

	return 0;
}
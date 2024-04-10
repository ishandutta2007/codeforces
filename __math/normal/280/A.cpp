#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

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
const unsigned int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(n) ((int)1e##n)

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }


const double EPS (1e-8);
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

typedef point<double> P;

double calc(double w,double h,double a){
	w /= 2;
	h /= 2;
	P p(w,h);
	P p2 = rot(p,a / 180 * PI);
	P q(w,-h);
	P q2 = rot(q,a / 180 * PI);

	if(p2.y <= h + EPS) return 0;
	if(q2.y >= h){
		double d = (p2.y + q2.y) / 2;
		double e = (p2.x + q2.x) / 2;
		double len = sqrt(d * d + e * e);
		double ret = 2 * h * len * (d - h) / d;
		return ret;
	} else {
		//
		double d = (p2.y - h) / (p2.y - q2.y) * 2 * h;
		double e = d / tan(a / 180 * PI);
		double ret = d * e * 1/2;
		return ret;
	}
}


int main(){
	double w,h,a;
	cin>>w>>h>>a;
	if(a >= 90) a = 180 - a;

	double ans = w * h - 2 * (calc(w,h,a) + calc(h,w,a));
	printf("%.20lf\n",ans);

	return 0;
}
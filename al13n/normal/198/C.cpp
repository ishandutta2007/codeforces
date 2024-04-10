#pragma comment(linker,"/STACK:256000000")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <iomanip>
#include <sstream>
#include <stack>
#include <ctime>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define fors(i,s) forn(i,(int)(s).length())
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define EQ(a,b) (fabs((a)-(b))<eps)
#define SQ(a) ((a)*(a))
#define index asdindex
#define prev asdprev
#define X first
#define Y second
#define unlink asdunlink
#define div asddiv
#define tr1 asdtr1
#define y0 asdy0
typedef unsigned char uchar;
typedef unsigned int uint;
typedef long long lng;
typedef pair<int,int> PII;
typedef pair<lng,lng> PLL;
typedef pair<double,double> PDD;
const int iinf=1000000000;
const lng linf=1000000000000000000LL;
const double dinf=1e200;
const double eps=1e-8;
const double PI=3.14159265359;
inline int mymax(int a,int b){return a<b?b:a;}
inline int mymin(int a,int b){return a>b?b:a;}
inline lng mymax(lng a,lng b){return a<b?b:a;}
inline lng mymin(lng a,lng b){return a>b?b:a;}
inline lng myabs(lng a){return a<0?-a:a;}

struct vec{
	double x,y;
	vec(){}
	vec(double x,double y):x(x),y(y){}
	double dot(const vec &b)const{return x*b.x+y*b.y;}
	double len()const{return sqrt(dot(*this));}
	vec norm()const{return vec(x/len(),y/len());}
	vec perp()const{return vec(-y,x);}
	vec operator-(const vec &b)const{return vec(x-b.x,y-b.y);}
	vec operator*(double b)const{return vec(x*b,y*b);}
};

double xp,yp,vp,rp,x0,y0,v0,r0;
double a0;

bool check(double ti){
	xp=rp*cos(a0+ti*vp/rp);
	yp=rp*sin(a0+ti*vp/rp);

	vec a(x0,y0);
	vec b(xp,yp);
	vec c(0,0);
	double dist=1e200;
	if((a-b).len()<eps||fabs((a-b).perp().norm().dot(a))>=r0||(c-a).dot(b-a)<=0||(c-b).dot(a-b)<=0)
		dist=(a-b).len();
	else{
		for(int s1=-1;s1<=1;s1+=2){
			for(int s2=-1;s2<=1;s2+=2){
				double va=atan2(y0,x0)+s1*acos(r0/a.len());
				vec pa=vec(cos(va),sin(va))*r0;
				double vb=atan2(yp,xp)+s2*acos(r0/b.len());
				vec pb=vec(cos(vb),sin(vb))*r0;
				double d=(va-vb)-floor((va-vb)/2/PI)*2*PI;
				dist=min(dist,min(d,2*PI-d)*r0+(a-pa).len()+(b-pb).len());
			}
		}
	}

	return dist/v0<=ti;
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	cin>>xp>>yp>>vp>>x0>>y0>>v0>>r0;
	a0=atan2(yp,xp);
	rp=sqrt(SQ(xp)+SQ(yp));

	double a=0,b=1e6;
	forn(qqq,100){
		double c=(a+b)/2;
		if(check(c))
			b=c;
		else
			a=c;
	}

	printf("%.15lf",(a+b)*.5);

    return 0;
}
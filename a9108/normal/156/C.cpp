#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define eps 1e-8
#define PB push_back
#define MP make_pair
using namespace std;
double pi=asin(1.0)*2;

struct point{
	double x,y;
	point(){}
	point(double _x,double _y){x=_x;y=_y;}
	inline void read(){scanf("%lf%lf",&x,&y);}
	inline void show(){printf("%lf %lf\n",x,y);}
	inline double dis(){return x*x+y*y;}
	inline double dist(){ return sqrt(x*x+y*y);}
};

inline point operator +(const point &a,const point &b){ return point(a.x+b.x,a.y+b.y); }
inline point operator -(const point &a,const point &b){ return point(a.x-b.x,a.y-b.y); }
inline point operator *(const point &a,const double &b){ return point(a.x*b,a.y*b); }
inline point operator /(const point &a,const double &b){ return point(a.x/b,a.y/b); }
inline double det(const point &a,const point &b){ return a.x*b.y-a.y*b.x; }
inline double dot(const point &a,const point &b){ return a.x*b.x+a.y*b.y; }
#define mo 1000000007
int T,n,m;
char s[200];
int f[3000][110];

int main(){
	memset(f,0,sizeof(f));
	f[0][0]=1;
	for (int i=0;i<3000;i++)
	for (int j=1;j<110;j++){
		for (int k=0;k<=25&&k<=i;k++) f[i][j]=(f[i][j]+f[i-k][j-1])%mo;
	}
	for (scanf("%d",&T);T--;){
		scanf("%s",s);
		n=strlen(s);
		m=0;
		for (int i=0;i<n;i++) m+=s[i]-'a';
		printf("%d\n",(f[m][n]+mo-1)%mo);
	}
	return 0;
}
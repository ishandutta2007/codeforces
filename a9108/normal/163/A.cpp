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

char a[10000],b[10000];
int n,m;
int f[5100][5100];
#define mo 1000000007

int main(){
	scanf("%s%s",a,b);
	n=strlen(a);m=strlen(b);
	memset(f,0,sizeof(f));
	int ans=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++){
		f[i][j]=0;
		if (a[i-1]==b[j-1]) {
			f[i][j]=(1+f[i-1][j-1])%mo;
			ans=(ans+f[i][j])%mo;
		}
		f[i][j]=(f[i][j]+f[i][j-1])%mo;
	}
	cout<<ans<<endl;
	return 0;
}
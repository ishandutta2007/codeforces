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

bool f[110000];
int cnt[110000][2];
int a[110000];
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	memset(cnt,0,sizeof(cnt));
	int t1=0,t2=0;
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if (a[i]>0) t1++,cnt[a[i]][0]++;
		else t2++,cnt[-a[i]][1]++;
	}
	int tot=0;
	for (int i=1;i<=n;i++){
		int num=t1-cnt[i][0]+cnt[i][1];
		if (num!=n-m) f[i]=false;
		else f[i]=true,tot++;
	}
	for (int i=0;i<n;i++){
		if (a[i]>0) {
			if (!f[a[i]]) puts("Lie");
			else if (tot==1) puts("Truth");
			else puts("Not defined");
		}
		else {
			if (!f[-a[i]]) puts("Truth");
			else if (tot==1) puts("Lie");
			else puts("Not defined");
		}
	}
	return 0;
}
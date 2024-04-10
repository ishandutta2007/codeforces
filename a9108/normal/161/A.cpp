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

int a[110000];
int b[110000];
int n,m,x,y;
vector<pair<int,int> > ans;
int main(){
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<m;i++) scanf("%d",&b[i]);
	ans.clear();
	for (int i=0,j=0;i<n&&j<m;){
		if (a[i]-x<=b[j]&&b[j]<=a[i]+y){
			ans.PB(MP(i+1,j+1));
			i++;j++;
		}
		else if (a[i]-x>b[j]) j++;
		else i++;
	}
	printf("%d\n",(int)ans.size());
	for (int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}
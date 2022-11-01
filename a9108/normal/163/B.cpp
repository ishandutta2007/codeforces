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

vector<pair<int,pair<int,int> > > a;
vector<int> ans,tmp;
int n,k,h;
int m[200000],v[200000];

vector<int> getans(double t){
	vector<int> ans;
	for (int i=0,j=1;j<=k&&i<a.size();i++){
		double ti=j/(double)a[i].second.first;
		if (ti<t){
			ans.PB(a[i].second.second);
			j++;
		}
	}
	return ans;
}

int main(){
	scanf("%d%d%d",&n,&k,&h);
	a.clear();
	for (int i=0;i<n;i++)scanf("%d",&m[i]);
	for (int i=0;i<n;i++)scanf("%d",&v[i]);
	for (int i=0;i<n;i++) a.PB(MP(m[i],MP(v[i],i+1)));
	sort(a.begin(),a.end());
	double l=0,r=1e10;
	ans.clear();
	for (int i=0;i<k;i++) ans.PB(a[i].second.second);
	for (int i=0;i<100;i++){
		double m=(l+r)/2;
		tmp=getans(m);
		if (tmp.size()==k) ans=tmp,r=m;
		else l=m;
	}
	for (int i=0;i<k;i++){
		if (i) printf(" ");
		printf("%d",ans[i]);
	}
	puts("");
	return 0;
}
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

vector<pair<double,double> > a;
vector<pair<double,int> >op;
int n,v1,v2,l;
double tlen[1000000];
int p[1000000];
inline bool reach(int len){
	return len*(long long)(v1+v2)<=l*(long long)v2;
}

int main(){
	scanf("%d%d%d%d",&n,&l,&v1,&v2);
	for (int i=0;i<n;i++) scanf("%d",&p[i]);
	double len=l*(double)v2/(double)(v1+v2);
	a.clear();
	for (int i=0;i<n;i++){
		if (p[i]-len<-eps){
			a.PB(MP(0,p[i]));
			a.PB(MP(p[i]-len+l+l,l+l));
		}
		else a.PB(MP(p[i]-len,p[i]));
	}
	op.clear();
	for (int i=0;i<a.size();i++)
	op.PB(MP(a[i].first,1)),op.PB(MP(a[i].second,-1));
	op.PB(MP(l+l,0));
	sort(op.begin(),op.end());
	int cnt=0;
	double la=0;
	memset(tlen,0,sizeof(tlen));
	
	for (int i=0;i<op.size();i++){
		tlen[cnt]+=op[i].first-la;
		la=op[i].first;
		cnt+=op[i].second;
	}
	for (int i=0;i<=n;i++) printf("%.20f\n",tlen[i]/(l+l));
	return 0;
}
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
#define N 86400
int n,k;
vector<pair<int,int> > a;
int f[4100][4100];

int getans(){
	memset(f,1,sizeof(f));
	f[0][0]=0;
	int ans=0;
	for (int i=0;i<n;i++)
	for (int j=0;j<=k;j++){
		f[i+1][j+1]=min(f[i+1][j+1],f[i][j]);
		f[i+1][j]=min(f[i+1][j],max(f[i][j],a[i].first)+a[i].second);
		ans=max(ans,a[i].first-f[i][j]);
	}
	return ans;
}

int main(){
	scanf("%d%d",&n,&k);
	a.clear();
	a.PB(MP(0,1));
	a.PB(MP(N+1,1));
	for (int i=0;i<n;i++){
		int q,w;
		scanf("%d%d",&q,&w);
		a.PB(MP(q,w));
	}
	n+=2;
	sort(a.begin(),a.end());
	printf("%d\n",getans());
	return 0;
}
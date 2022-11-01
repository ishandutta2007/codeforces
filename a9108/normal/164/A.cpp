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

bool r1[110000],r2[110000];
vector<int> g1[110000],g2[110000];
int n,m;
int a[110000];

void make1(int i){
	if (r1[i]) return;
	r1[i]=true;
	for (int z=0;z<g1[i].size();z++) make1(g1[i][z]);
}
void make2(int i){
	if (r2[i]) return;
	r2[i]=true;
	if (a[i]==1) return;
	for (int z=0;z<g2[i].size();z++) make2(g2[i][z]);
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
		g1[i].clear();
		g2[i].clear();
	}
	for (int z=0;z<m;z++){
		int i,j;
		scanf("%d%d",&i,&j);
		i--;j--;
		g1[i].PB(j);
		g2[j].PB(i);
	}
	memset(r1,false,sizeof(r1));
	for (int i=0;i<n;i++) if (a[i]==1) make1(i);
	memset(r2,false,sizeof(r2));
	for (int i=0;i<n;i++) if (a[i]==2) make2(i);
	for (int i=0;i<n;i++) if (r1[i]&&r2[i]) puts("1");
	else puts("0");
	return 0;
}
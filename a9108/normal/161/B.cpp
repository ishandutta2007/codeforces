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

vector<pair<int,int> > a,b;
vector<vector<pair<int,int> > > ans;
long long sum;
int n,k;

int main(){
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++){
		int q,w;
		scanf("%d%d",&q,&w);
		if (w==1) a.PB(MP(q,i+1));
		else b.PB(MP(q,i+1));
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	sum=0;
	ans.clear();
	for (int i=a.size()-1,j=b.size()-1,z=k;z>0;z--){
		vector<pair<int,int> > t;
		if (i>=0) t.PB(a[i--]);
		else t.PB(b[j--]);
		if (z==1){
			for (;i>=0;i--) t.PB(a[i]);
			for (;j>=0;j--) t.PB(b[j]);
		}
		ans.PB(t);
	}
	for (int i=0;i<k;i++){
		int mi=2000000000;
		for (int z=0;z<ans[i].size();z++) {
			mi=min(mi,ans[i][z].first);
			sum+=ans[i][z].first*2;
		}
		if (i<a.size()) sum-=mi;
	}
	printf("%I64d.",sum/2);
	if (sum%2==1) puts("5");
	else puts("0");
	for (int i=0;i<k;i++){
		printf("%d", ans[i].size());
		for (int z=0;z<ans[i].size();z++) printf(" %d",ans[i][z].second);
		puts("");
	}
	return 0;
}
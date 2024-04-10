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

vector<string> now;
int t;
char s[1000];

void make(int i){
	for (char *p=strtok(s+i,"/");p;p=strtok(NULL,"/")){
		if (strcmp(p,"..")==0) now.pop_back();
		else now.PB(p);
	}
}

int main(){
	now.clear();
	for (scanf("%d",&t);t--;){
		scanf("%s",s);
		if (s[0]=='c'){
			scanf("%s",s);
			if (s[0]=='/'){
				now.clear();
				make(1);
			}
			else make(0);
		}
		else{
			printf("/");
			for (int i=0;i<now.size();i++) printf("%s/",now[i].c_str());
			puts("");
		}
	}
	return 0;
}
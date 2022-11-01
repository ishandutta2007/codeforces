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

int f[110000];
int g[500000],nxt[500000],li[500000],tot;
int n,m,k;
bool v[110000];
bool in[110000];
queue<int> Q;
int S,T;
int M;

void insert(int i,int j){
	li[tot]=j;nxt[tot]=g[i];g[i]=tot;tot++;
}

void insert_q(int i,int le){
	if (v[i]) le=M;
	if (f[i]>=le) return;
	f[i]=le;
	if (in[i]) return;
	in[i]=true;
	Q.push(i);
}

void relax(int i){
	in[i]=false;
	int le=f[i];
	if (le) for (int j=g[i];j!=-1;j=nxt[j]) {
		insert_q(li[j],le-1);
	}
}

bool check(int m){
	M=m;
	memset(f,-1,sizeof(f));
	memset(in,false,sizeof(in));
	for (;Q.size();Q.pop());
	insert_q(S,m);
	for (;Q.size()&&f[T]==-1;Q.pop()){
		relax(Q.front());
	}
	return f[T]!=-1;
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	memset(v,false,sizeof(v));
	for (int z=0;z<k;z++){
		int a;
		scanf("%d",&a);
		v[a-1]=true;
	}
	memset(g,-1,sizeof(g));
	tot=0;
	for (int z=0;z<m;z++){
		int a,b;
		scanf("%d%d",&a,&b);
		a--;b--;
		insert(a,b);
		insert(b,a);
	}
	scanf("%d%d",&S,&T);
	S--;T--;
	int l=-1,r=n+1;
	for (;l<r-1;){
		int m=(l+r)/2;
		if (check(m)) r=m;
		else l=m;
	}
	if (l==n) printf("%d\n",-1);
	else printf("%d\n",r);
	return 0;
}
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

int f[66][66][66];
int g[66][66][66];
int tg[66][66];
bool in[66][66][66];
int n,m,r;
queue<pair<int,pair<int,int> > > Q;

void insert(int i,int j,int k,int len){
	if (f[i][j][k]!=-1&&f[i][j][k]<=len) return;
	f[i][j][k]=len;
	if (in[i][j][k]) return;
	in[i][j][k]=true;
	Q.push(MP(i,MP(j,k)));
}

void relax(pair<int,pair<int,int> > st){
	int num=st.first,i=st.second.first,j=st.second.second;
	in[num][i][j]=false;
	if (num==n) return;
	for (int z=0;z<n;z++) insert(num+1,i,z,f[num][i][j]+tg[j][z]);
}

void  makef(){
	memset(f,-1,sizeof(f));
	for (;Q.size();Q.pop());
	memset(in,false,sizeof(in));
	for (int z=0;z<n;z++) insert(0,z,z,0);
	for (;Q.size();Q.pop()) relax(Q.front());
}

int main(){
	scanf("%d%d%d",&n,&m,&r);
	for (int i=0;i<m;i++) for (int j=0;j<n;j++) for (int k=0;k<n;k++) scanf("%d",&g[i][j][k]);
	for (int z=0;z<m;z++)
	for (int k=0;k<n;k++)
	for (int i=0;i<n;i++)
	for (int j=0;j<n;j++)
	g[z][i][j]=min(g[z][i][k]+g[z][k][j],g[z][i][j]);
	for (int i=0;i<n;i++)
	for (int j=0;j<n;j++){
		tg[i][j]=1000000000;
		for (int z=0;z<m;z++) tg[i][j]=min(g[z][i][j],tg[i][j]);
	}
	makef();
	for (int z=0;z<r;z++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		c++;
		a--;b--;
		printf("%d\n",f[min(c,n)][a][b]);
	}
	return 0;
}
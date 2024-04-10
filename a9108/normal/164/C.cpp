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

int s[2000],t[2000],cc[2000];
int S,T,N;
int n,k;
int f[2100][2100],c[2100][2100],cost[2100][2100];
vector<int> g[2100];
queue<int> Q;
int fr[2100];
int d[2100];
bool in[2100];

void add(int i,int j,int k,int l){
	f[i][j]=k;
	cost[i][j]=l;cost[j][i]=-l;
	g[i].PB(j);
	g[j].PB(i);
}
void insert(int i,int j,int k){
	if (d[i]!=-1&&d[i]>=j) return;
	d[i]=j;
	fr[i]=k;
	if (in[i]) return;
	in[i]=true;
	Q.push(i);
}
void relax(int i){
	in[i]=false;
	for (int z=0;z<g[i].size();z++){
		int j=g[i][z];
		if (c[i][j]<f[i][j]) insert(j,d[i]+cost[i][j],i);
	}
}
void makeflow(){
	memset(d,-1,sizeof(d));
	for (;Q.size();Q.pop());
	memset(in,false,sizeof(in));
	insert(S,0,-1);
	for (;Q.size();Q.pop()) relax(Q.front());
	if (d[T]==-1) return;
	for (int now=T;now!=S;){
		int i=fr[now];
		c[i][now]++;
		c[now][i]--;
		now=i;
	}
}

int main(){
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) scanf("%d%d%d",&s[i],&t[i],&cc[i]);
	S=n*2;T=S+1;
	N=T+1;
	memset(f,0,sizeof(f));
	for (int i=0;i<n;i++){
		add(S,i*2,100,0);
		add(i*2,T,100,0);
		add(i*2+1,T,100,0);
		add(i*2,i*2+1,1,cc[i]);
	}
	for (int i=0;i<n;i++){
		int nxt=-1;
		for (int j=0;j<n;j++)
			if (s[i]<s[j]||(s[i]==s[j]&&j>i)) {
				if (nxt==-1) nxt=j;
				if (s[j]<s[nxt]) nxt=j;
			}
		if (nxt!=-1) add(i*2,nxt*2,100,0);
		nxt=-1;
		for (int j=0;j<n;j++)
			if (s[i]+t[i]<=s[j]) {
				if (nxt==-1) nxt=j;
				if (s[j]<s[nxt]) nxt=j;
			}
		if (nxt!=-1) add(i*2+1,nxt*2,100,0);
	}
	memset(c,0,sizeof(c));
	for (int z=0;z<k;z++) makeflow();
	for (int i=0;i<n;i++) {
		if (i) printf(" ");
		printf("%d",c[i*2][i*2+1]);
	}
	puts("");
	return 0;
}
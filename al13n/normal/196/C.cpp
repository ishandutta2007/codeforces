#pragma comment(linker,"/STACK:1024000000")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <iomanip>
#include <sstream>
#include <stack>
#include <ctime>
#include <cstdlib>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
#define linf 1000000000000000000LL
#define dinf 1e200
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-5
#define EQ(a,b) (fabs((a)-(b))<eps)
#define SQ(a) ((a)*(a))
#define PI 3.14159265359
#define index asdindex
#define FI first
#define SE second
#define prev asdprev
#define PII pair<int,int> 
#define PLL pair<lng,lng> 
#define PDD pair<double,double> 
#define X first
#define Y second
#define unlink asdunlink
#define div asddiv
#define divides asddivides
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned lng ulng;
inline int mymax(int a,int b){return a<b?b:a;}
inline int mymin(int a,int b){return a>b?b:a;}
inline lng mymax(lng a,lng b){return a<b?b:a;}
inline lng mymin(lng a,lng b){return a>b?b:a;}
inline lng abs(lng a){return a<0?-a:a;}
#ifdef __ASD__
#define LOG(x) cerr<<x<<endl
#else
#define LOG(x)
#endif

struct vec{
	double x,y;
	double v;
	int id;
	vec(){}
	vec(double x,double y):x(x),y(y){}
	bool operator<(const vec &b)const{
		return v<b.v;
	}
};

vector<int> gr[1600];
vec pts[1600];
int res[1600];
int sz[1600];

void dfs(int v,int pr){
	sz[v]=1;
	forv(i,gr[v]){
		int p=gr[v][i];
		if(p==pr)
			continue;
		dfs(p,v);
		sz[v]+=sz[p];
	}
}

void doit(int v,int pr,int a,int b,vec vx){
	res[pts[b-1].id]=v+1;
	vec vy(-vx.y,vx.x);
	for(int i=a;i<b-1;++i){
		pts[i].v=atan2(vy.x*(pts[i].x-pts[b-1].x)+vy.y*(pts[i].y-pts[b-1].y),vx.x*(pts[i].x-pts[b-1].x)+vx.y*(pts[i].y-pts[b-1].y));
	}
	sort(pts+a,pts+b-1);
	int s=a;
	forv(i,gr[v]){
		int p=gr[v][i];
		if(p==pr)
			continue;
		doit(p,v,s,s+sz[p],vec(pts[b-1].x-pts[s+sz[p]-1].x,pts[b-1].y-pts[s+sz[p]-1].y));
		s+=sz[p];
	}
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	int n;
	cin>>n;
	forn(i,n-1){
		int a,b;
		cin>>a>>b;
		--a;--b;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	forn(i,n){
		cin>>pts[i].x>>pts[i].y;
		pts[i].id=i;
		pts[i].v=pts[i].y*iinf*3-pts[i].x;
	}
	sort(pts,pts+n);
	dfs(0,-1);
	doit(0,-1,0,n,vec(1,0));
	forn(i,n)
		cout<<res[i]<<' ';

    return 0;
}
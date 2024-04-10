#pragma comment(linker,"/STACK:228000000")
#include <vector>
#include <cstring>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <string>
using namespace std;
#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i=0;i<n;++i)
#define fornr(i,n) for(int i=n-1;i>=0;--i)
#define lng long long
#define PI 3.1415926535897932384626433832795
#define SQ(a) ((a)*(a))
#define sqr(a) ((a)*(a))
#define VI vector<int>
#define VD vector<double>
#define VS vector<string>
#define forv(i,v) for(int i=0;i<(int)v.size();++i)
#define forvr(i,v) for(int i=(int)v.size()-1;i>=0;--i)
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define ABS(a) ((a)<0?-(a):(a))
#define EQ(a,b) (ABS((a)-(b))<eps)
#define iinf 1000000000
#define dinf 100000000000000000000.0
#define linf 1000000000000000000LL
#define y1 asdy1
#define y2 asdy2
#define DEG2RAD 0.01745329251994329576923690768489
#define eps 1e-9
#define prev asdprev
#define left asdleft
#define fixed asdfixed
#define time asdtime
#define free asdfree
#define ends asdends
#define list asdlist
inline lng abs(lng a){return a<0?-a:a;}
#ifdef __ASD__
//#include "my.h"
#endif

int tree[1000000];

void assign(int l,int r,int v,int a,int b,int k){
	if(l==a&&r==b){
		tree[k]=v;
		return;
	}
	if(tree[k]!=-1){
		tree[k*2+1]=tree[k*2+2]=tree[k];
		tree[k]=-1;
	}
	int c=(a+b+1)/2;
	if(r<=c)
		assign(l,r,v,a,c,k*2+1);
	else if(l>=c)
		assign(l,r,v,c,b,k*2+2);
	else{
		assign(l,c,v,a,c,k*2+1);
		assign(c,r,v,c,b,k*2+2);
	}
}
int getval(int v,int a,int b,int k){
	if(tree[k]!=-1)
		return tree[k];
	int c=(a+b+1)/2;
	if(v<c)
		return getval(v,a,c,k*2+1);
	else
		return getval(v,c,b,k*2+2);
}

double v;
pair<double,int> angs[100000];
int n;
const double g=9.8;

double getheight(double x,double a){
	double t=x/v/cos(a);
	return max(0.0,v*sin(a)*t-g*t*t/2);
}
double getmaxang(double x){
	double a=0,b=PI/4;
	while(b-a>eps){
		double t1=a+(b-a)/3;
		double t2=a+(b-a)*2/3;
		double l=getheight(x,t1);
		double r=getheight(x,t2);
		if(r<=l)
			b=t2;
		else
			a=t1;
	}
	return (a+b)/2;
}
double getang(double x,double y,double a,double b,double asc){
	while(b-a>eps){
		double t=(a+b)/2;
		if(getheight(x,t)*asc<y*asc)
			a=t;
		else
			b=t;
	}
	return (a+b)/2;
}

pair<double,double> walls[100000];
pair<double,double> res[100000];

#define filename "exam"
int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
	//freopen(filename".in","r",stdin);freopen(filename".out","w",stdout);
#endif

	cin>>n>>v;
	forn(i,n){
		scanf("%lf",&angs[i].first);
		angs[i].second=i;
	}
	sort(angs,angs+n);
	int m;
	cin>>m;
	
	tree[0]=-2;
	forn(i,m)
		scanf("%lf%lf",&walls[i].first,&walls[i].second);
	sort(walls,walls+m);
	fornr(i,m){
		double x,y;
		x=walls[i].first;
		y=walls[i].second;
		double amax=getmaxang(x);
		double ang1=getang(x,y,0,amax,1);
		double ang2=getang(x,y,amax,PI/4,-1);
		int i1=lower_bound(angs,angs+n,mp(ang1+eps,0))-angs;
		int i2=lower_bound(angs,angs+n,mp(ang2-eps,0))-angs;
		if(i1)
			assign(0,i1,i,0,n,0);
		if(i2<n)
			assign(i2,n,i,0,n,0);
	}
	forn(i,n){
		int w=getval(i,0,n,0);
		double rx,ry;
		double d=v*v*sin(2*angs[i].first)/g;
		if(w==-2||d<walls[w].first){
			rx=d;
			ry=0;
		}else{
			rx=walls[w].first;
			ry=getheight(rx,angs[i].first);
		}
		res[angs[i].second]=mp(rx,ry);
	}
	forn(i,n)
		printf("%.8lf %.8lf\n",res[i].first,res[i].second);

    return 0;
}
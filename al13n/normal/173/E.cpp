#pragma comment(linker,"/STACK:256000000")
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
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
#define linf 1000000000000000000LL
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-10
#define EQ(a,b) (fabs((a)-(b))<eps)
#define SQ(a) ((a)*(a))
#define PI 3.14159265359
#define index asdindex
#define FI first
#define SE second
#define prev asdprev
#define PII pair<int,int> 
#define X first
#define Y second
#define unlink asdunlink
typedef unsigned char uchar;
typedef unsigned int uint;

inline int mymax(int a,int b){
	return a<b?b:a;
}

int sum[1000000];
int mx[1000000];

void zero(int a,int b,int k){
	sum[k]=mx[k]=0;
	if(b==a+1)
		return;
	int c=(a+b)/2;
	zero(a,c,k*2+1);
	zero(c,b,k*2+2);
}

void setval(int p,int v,int a,int b,int k){
	if(b==a+1){
		sum[k]=mx[k]=v;
		return;
	}
	int c=(a+b)/2;
	if(p<c)
		setval(p,v,a,c,k*2+1);
	else
		setval(p,v,c,b,k*2+2);
	sum[k]=sum[k*2+1]+sum[k*2+2];
	mx[k]=mymax(mx[k*2+1],mx[k*2+2]);
}

int getsum(int l,int r,int a,int b,int k){
	if(a==l&&b==r)
		return sum[k];
	int c=(a+b)/2;
	if(r<=c)
		return getsum(l,r,a,c,k*2+1);
	else if(l>=c)
		return getsum(l,r,c,b,k*2+2);
	else
		return getsum(l,c,a,c,k*2+1)+getsum(c,r,c,b,k*2+2);
}

int getmax(int l,int r,int a,int b,int k){
	if(a==l&&b==r)
		return mx[k];
	int c=(a+b)/2;
	if(r<=c)
		return getmax(l,r,a,c,k*2+1);
	else if(l>=c)
		return getmax(l,r,c,b,k*2+2);
	else
		return mymax(getmax(l,c,a,c,k*2+1),getmax(c,r,c,b,k*2+2));
}

struct event{
	bool query;
	int y;
	int x1,x2;
	int id;
	bool operator<(const event &b)const{
		return y>b.y;
	}
};

int n,K;
int xs[110000];
int xcnt;
int team[110000];
int res[110000];
pair<pair<int,int>,PII> queries[110000];
pair<PII,int> pts[110000];
int iperm[110000];
event evs[210000];
int evcnt;

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	cin>>n>>K;
	forn(i,n){
		scanf("%d",&pts[i].X.X);
		pts[i].Y=i;
	}
	forn(i,n){
		scanf("%d",&pts[i].X.Y);
		xs[xcnt++]=pts[i].X.Y;
	}
	sort(xs,xs+xcnt);
	xcnt=unique(xs,xs+xcnt)-xs;
	forn(i,n){
		pts[i].X.Y=lower_bound(xs,xs+xcnt,pts[i].X.Y)-xs;
	}
	sort(pts,pts+n);

	forn(i,n){
		iperm[pts[i].Y]=i;
	}

	for(int i=0;i<n;){
		int j=i;
		while(j<n&&pts[j].X.X==pts[i].X.X){
			setval(pts[j].X.Y,getsum(pts[j].X.Y,pts[j].X.Y+1,0,xcnt,0)+1,0,xcnt,0);
			evs[evcnt].query=false;
			evs[evcnt].id=pts[j].Y;
			evs[evcnt].x1=pts[j].X.Y;
			evs[evcnt].y=pts[j].X.X;
			++evcnt;
			++j;
		}
		while(i<j){
			int a=lower_bound(xs,xs+xcnt,xs[pts[i].X.Y]-K)-xs;
			int b=upper_bound(xs,xs+xcnt,xs[pts[i].X.Y]+K)-xs;
			if(b<=a)
				exit(321);
			team[pts[i].Y]=getsum(a,b,0,xcnt,0);
			++i;
		}
	}

	zero(0,xcnt,0);

	int tc;
	cin>>tc;
	forn(qqq,tc){
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		a=iperm[a];
		b=iperm[b];
		evs[evcnt].id=qqq;
		evs[evcnt].query=true;
		evs[evcnt].y=mymax(pts[a].X.X,pts[b].X.X);
		int x1=pts[a].X.Y;
		int x2=pts[b].X.Y;
		if(x2<x1)
			swap(x1,x2);
		evs[evcnt].x1=lower_bound(xs,xs+xcnt,xs[x2]-K)-xs;
		evs[evcnt].x2=upper_bound(xs,xs+xcnt,xs[x1]+K)-xs;
		++evcnt;
	}

	sort(evs,evs+evcnt);

	for(int i=0;i<evcnt;){
		int j=i;
		while(j<evcnt&&evs[j].y==evs[i].y){
			if(!evs[j].query)
				setval(evs[j].x1,mymax(getmax(evs[j].x1,evs[j].x1+1,0,xcnt,0),team[evs[j].id]),0,xcnt,0);
			++j;
		}
		while(i<j){
			if(evs[i].query){
				if(evs[i].x1<evs[i].x2)
					res[evs[i].id]=getmax(evs[i].x1,evs[i].x2,0,xcnt,0);
			}
			++i;
		}
	}

	forn(i,tc){
		if(!res[i])
			res[i]=-1;
		printf("%d\n",res[i]);
	}
	
    return 0;
}
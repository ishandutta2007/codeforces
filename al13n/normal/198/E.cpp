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
#include <ctime>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define fors(i,s) forn(i,(int)(s).length())
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define EQ(a,b) (fabs((a)-(b))<eps)
#define SQ(a) ((a)*(a))
#define index asdindex
#define prev asdprev
#define X first
#define Y second
#define unlink asdunlink
#define div asddiv
#define tr1 asdtr1
#define y0 asdy0
typedef unsigned char uchar;
typedef unsigned int uint;
typedef long long lng;
typedef pair<int,int> PII;
typedef pair<lng,lng> PLL;
typedef pair<double,double> PDD;
const int iinf=1000000000;
const lng linf=1000000000000000000LL;
const double dinf=1e200;
const double eps=1e-8;
const double PI=3.14159265359;
inline int mymax(int a,int b){return a<b?b:a;}
inline int mymin(int a,int b){return a>b?b:a;}
inline lng mymax(lng a,lng b){return a<b?b:a;}
inline lng mymin(lng a,lng b){return a>b?b:a;}
inline lng myabs(lng a){return a<0?-a:a;}

PII tree[4000000];

pair<PII,PII> pts[251000];

void build(int a,int b,int k){
	if(b==a+1){
		tree[k]=mp(pts[a].X.Y,a);
		return;
	}
	int c=(a+b)/2;
	build(a,c,k*2+1);
	build(c,b,k*2+2);
	tree[k]=min(tree[k*2+1],tree[k*2+2]);
}

PII getmin(int l,int r,int a,int b,int k){
	if(l<=a&&r>=b)
		return tree[k];
	if(r<=a||l>=b)
		return mp(iinf*2,-1);
	int c=(a+b)/2;
	return min(getmin(l,r,a,c,k*2+1),getmin(l,r,c,b,k*2+2));
}

void setval(int p,PII v,int a,int b,int k){
	if(b==a+1){
		tree[k]=v;
		return;
	}
	int c=(a+b)/2;
	if(p<c)
		setval(p,v,a,c,k*2+1);
	else
		setval(p,v,c,b,k*2+2);
	tree[k]=min(tree[k*2+1],tree[k*2+2]);
}
int n;
int res;

void doit(PII v){
	int l=upper_bound(pts,pts+n,mp(mp(v.X,2*iinf),mp(2*iinf,2*iinf)))-pts;
	while(true){
		PII p=getmin(0,l,0,n,0);
		if(p.Y==-1||p.X>v.Y)
			break;
		int k=p.Y;
		++res;
		setval(k,mp(2*iinf,-1),0,n,0);
		doit(pts[k].Y);
	}
}

int prep(lng x,lng y){
	lng v=SQ(x)+SQ(y);
	lng a=(lng)sqrt((double)v);
	while(SQ(a)>v)--a;
	while(SQ(a)<v)++a;
	return (int)min(a,iinf+iinf/2LL);
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);

	int x0,y0,p0,r0;
	cin>>x0>>y0>>p0>>r0>>n;
	forn(i,n){
		int x,y;
		cin>>x>>y;
		pts[i].X.Y=prep(x-x0,y-y0);
		cin>>pts[i].X.X>>pts[i].Y.X>>pts[i].Y.Y;
	}
	sort(pts,pts+n);

	build(0,n,0);

	doit(mp(p0,r0));

	cout<<res;

    return 0;
}
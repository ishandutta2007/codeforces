#pragma comment(linker,"/STACK:256000000")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <complex>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <memory.h>
using namespace std;
#define sz(v) ((int)(v).size())
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define pb push_back
#define mp make_pair
#define istr stringstream
#define fi first
#define se second
#define X first
#define Y second
#define clr(a,v) memset((a),(v),sizeof(a))
#define y0 asdy0
#define y1 asdy1
#define j0 asdj0
#define j1 asdj1
#define next asdnext
#define prev asdprev
#define link asdlink
#define unlink asdunlink
#define left asdleft
#define right asdright
#define hash asdhash
#define div asddiv
#define all(v) (v).begin(),(v).end()
typedef long long lng;
typedef unsigned int uint;
typedef unsigned long long ulng;
typedef unsigned char uchar;
typedef double ld;
typedef pair<int,int> PII;
typedef pair<ld,ld> PDD;
typedef pair<lng,lng> PLL;
typedef complex<double> com;
const ld PI=3.1415926535897932384626433832795;
const ld EPS=1e-8;
const int inf=1000000000;
const lng linf=1000000000000000000LL;
template<class T> inline T sqr(T x) { return x * x; }
int gcd(int a,int b){return a?gcd(b%a,a):b;}

int xs[2100];
int ys[2100];
int cx,cy;
int n;
pair<PII,PII> rs[1100];
bool wall[2100][2100];

lng dfs(int x,int y){
	if(x<0||y<0||x>=cx-1||y>=cy-1||wall[x][y])
		return 0;
	wall[x][y]=true;
	const int dx[4]={-1,1,0,0};
	const int dy[4]={0,0,-1,1};
	lng r=1LL*(xs[x+1]-xs[x])*(ys[y+1]-ys[y]);
	forn(i,4){
		r+=dfs(x+dx[i],y+dy[i]);
	}
	return r;
}

int main() {
#ifdef __ASD__
    freopen("input.txt","rt",stdin);freopen("output.txt","wt",stdout);
#endif
	
	int dx[256];
	int dy[256];
	clr(dx,0);
	clr(dy,0);
	dx['L']=-1;
	dx['R']=1;
	dy['U']=1;
	dy['D']=-1;
	
	cin>>n;
	int x=0,y=0;
	xs[cx++]=-inf-1000;
	xs[cx++]=inf+1000;
	ys[cy++]=-inf-1000;
	ys[cy++]=inf+1000;
	forn(i,n){
		char d;
		int v;
		cin>>d>>v;
		int xx=x+dx[d]*v;
		int yy=y+dy[d]*v;
		int x1=min(x,xx);
		int x2=max(x,xx)+1;
		int y1=min(y,yy);
		int y2=max(y,yy)+1;
		rs[i]=mp(mp(x1,y1),mp(x2,y2));
		xs[cx++]=x1;
		xs[cx++]=x2;
		ys[cy++]=y1;
		ys[cy++]=y2;
		x=xx;
		y=yy;
	}
	sort(xs,xs+cx);
	cx=unique(xs,xs+cx)-xs;
	sort(ys,ys+cy);
	cy=unique(ys,ys+cy)-ys;
	
	forn(i,n){
		int x1=lower_bound(xs,xs+cx,rs[i].X.X)-xs;
		int y1=lower_bound(ys,ys+cy,rs[i].X.Y)-ys;
		int x2=lower_bound(xs,xs+cx,rs[i].Y.X)-xs;
		int y2=lower_bound(ys,ys+cy,rs[i].Y.Y)-ys;
		for(int x=x1;x<x2;++x){
			for(int y=y1;y<y2;++y){
				wall[x][y]=true;
			}
		}
	}
	
	cout<<1LL*(xs[cx-1]-xs[0])*(ys[cy-1]-ys[0])-dfs(0,0);

	return 0;
}
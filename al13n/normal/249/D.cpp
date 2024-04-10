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
const ld EPS=1e-12;
const int inf=1000000000;
const lng linf=1000000000000000000LL;
template<class T> inline T sqr(T x) { return x * x; }
int gcd(int a,int b){return a?gcd(b%a,a):b;}

int tree[1100000];

void init(int a,int b,int k){
	tree[k]=-inf;
	if(b==a+1)
		return;
	int c=(a+b)/2;
	init(a,c,k*2+1);
	init(c,b,k*2+2);
}

void setv(int p,int v,int a,int b,int k){
	if(b==a+1){
		tree[k]=max(tree[k],v);
		return;
	}
	int c=(a+b)/2;
	if(p<c)
		setv(p,v,a,c,k*2+1);
	else
		setv(p,v,c,b,k*2+2);
	tree[k]=max(tree[k*2+1],tree[k*2+2]);
}

int getmax(int l,int r,int a,int b,int k){
	if(r<=a||l>=b)
		return -inf;
	if(a>=l&&b<=r)
		return tree[k];
	int c=(a+b)/2;
	return max(getmax(l,r,a,c,k*2+1),getmax(l,r,c,b,k*2+2));
}

PLL pts[110000];
lng ys[110000];
int yc;
int n;

void perverted_read(lng &a,lng &b){
	string s;
	cin>>s;
	forv(i,s){
		if(s[i]=='/'){
			int ia,ib;
			s[i]=0;
			sscanf(s.c_str(),"%d",&ia);
			sscanf(s.c_str()+i+1,"%d",&ib);
			a=ia;
			b=ib;
			return;
		}
	}
	exit(2);
}

int main() {
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

	lng ax,ay,bx,by;
	
	cin>>n;
	perverted_read(ay, ax);
	perverted_read(by, bx);
	forn(i,n){
		lng x,y;
		int ix,iy;
		scanf("%d%d",&ix,&iy);
		x=ix;
		y=iy;
		lng p=by*x-bx*y;
		lng q=-ay*x+ax*y;
		pts[i]=mp(p,q);
		ys[i]=q;
	}
	ys[n]=0;
	sort(ys,ys+n+1);
	yc=unique(ys,ys+n+1)-ys;
	init(0,yc,0);
	forn(i,n){
		pts[i].Y=lower_bound(ys,ys+yc,pts[i].Y)-ys;
	}
	sort(pts,pts+n);
	setv(lower_bound(ys,ys+yc,0)-ys,0,0,yc,0);
	int res=0;
	for(int i=0;i<n;){
		int j=i+1;
		while(j<n&&pts[j].X==pts[i].X)
			++j;
		if(pts[i].X>0){
			vector<int> rs(j-i);
			for(int k=i;k<j;++k){
				rs[k-i]=1+getmax(0,pts[k].Y,0,yc,0);
				res=max(res,rs[k-i]);
			}
			for(int k=i;k<j;++k){
				setv(pts[k].Y,rs[k-i],0,yc,0);
			}
		}
		i=j;
	}
	cout<<res;

	return 0;
}
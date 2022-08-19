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
const ld EPS=1e-3;
const int inf=1000000000;
const lng linf=1000000000000000000LL;
template<class T> inline T sqr(T x) { return x * x; }
int gcd(int a,int b){return a?gcd(b%a,a):b;}



int main() {
#ifdef __ASD__
    freopen("input.txt","rt",stdin);freopen("output.txt","wt",stdout);
#endif

	vector<lng> xs;
	vector<lng> ps;
	lng x0=1000000;
	lng p0=1000000;
	xs.pb(x0);
	ps.pb(p0);
	lng x=x0;
	for(lng p=1;p<=330;++p){
		lng xx=x-1;
		while(xx>=0 && sqr(x-xx)+sqr(1)<sqr(p+p-1))
			--xx;
		while(xx>=0 && sqr(x0-xx)+sqr(p0-p)<=sqr(p+p0))
			--xx;
		if(xx<0){
			cout<<"nope "<<p<<endl;
			exit(0);
		}
		xs.pb(xx);
		ps.pb(p);
		x=xx;
	}
	
	{
		lng xx=0;
		lng pp=1;
		while(sqr(x0-xx)+sqr(p0-pp)>=sqr(p0+pp))
			++pp;
		xs.pb(xx);
		ps.pb(pp);
	}
	
	reverse(all(xs));
	reverse(all(ps));
	cout<<xs.size()<<endl;
	forv(i,xs){
		cout<<xs[i]<<' '<<ps[i]<<'\n';
	}
	
	return 0;
}
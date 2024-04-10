#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
using namespace std;
template<class T> inline T sqr(T x) { return x * x; }
template<class T> inline string tostr(const T & x) { stringstream ss; ss << x; return ss.str(); }
typedef long long lng;
typedef unsigned long long ulng;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<lng, lng> PLL;
typedef pair<lng, int> PLI;
typedef pair<ld, ld> PDD;
#define left asdleft
#define right asdright
#define link asdlink
#define unlink asdunlink
#define next asdnext
#define prev asdprev
#define y0 asdy0
#define y1 asdy1
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define X first
#define Y second
#define hash asdhash
#define move asdmove
const double EPS = 1e-6;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;

lng n,m,x,y,a,b;
lng rx1,ry1,rx2,ry2;
lng rd=LINF*8;

void tryres(lng x1,lng x2,lng y1,lng y2){
	if(x1<0){
		x2-=x1;
		x1=0;
	}
	if(y1<0){
		y2-=y1;
		y1=0;
	}
	if(x2>n){
		x1-=x2-n;
		x2=n;
	}
	if(y2>m){
		y1-=y2-m;
		y2=m;
	}
	lng d=sqr(x1+x2-x*2)+sqr(y1+y2-y*2);
	if(mp(d,mp(mp(x1,y1),mp(x2,y2)))<mp(rd,mp(mp(rx1,ry1),mp(rx2,ry2)))){
		rd=d;
		rx1=x1;
		rx2=x2;
		ry1=y1;
		ry2=y2;
	}
}

lng gcd(lng a,lng b){
	return a?gcd(b%a,a):b;
}

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	cin>>n>>m>>x>>y>>a>>b;
	lng g=gcd(a,b);
	a/=g;
	b/=g;
	lng k=min(n/a,m/b);
	forn(dx,2){
		forn(dy,2){
			tryres(x-(a*k+dx)/2,x+(a*k+1-dx)/2,y-(b*k+dy)/2,y+(b*k+1-dy)/2);
		}
	}
	
	cout<<rx1<<' '<<ry1<<' '<<rx2<<' '<<ry2<<endl;

	return 0;
}
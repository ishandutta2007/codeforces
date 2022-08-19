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
typedef pair<short, short> PSS;
typedef pair<PII, int> PIII;
typedef pair<lng, lng> PLL;
typedef pair<lng, int> PLI;
typedef pair<ld, ld> PDD;
#define left asdleft
#define right asdright
#define link asdlink
#define unlink asdunlink
//#define next asdnext
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
const ld EPS = 1e-14;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795L;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}

struct vec{
	ld x,y;
	vec(){}
	vec(ld x,ld y):x(x),y(y){}
	ld dot(const vec &b)const{
		return x*b.x+y*b.y;
	}
	vec ccw()const{
		return vec(-y,x);
	}
	ld len()const{
		return sqrt(dot(*this));
	}
	vec norm()const{
		ld l=len();
		return vec(x/l,y/l);
	}
	vec operator-(const vec &b)const{
		return vec(x-b.x,y-b.y);
	}
	vec operator+(const vec &b)const{
		return vec(x+b.x,y+b.y);
	}
	vec operator*(ld b)const{
		return vec(x*b,y*b);
	}
};

ld ans[310];

void doit(vector<PII> &src){
	vector<vec> poly;
	poly.pb(vec(0,1e4));
	poly.pb(vec(0,0));
	poly.pb(vec(1,0));
	poly.pb(vec(1,1e4));
	set<PII> was;
	forv(q,src){
		if(was.count(src[q]))
			continue;
		was.insert(src[q]);
		
		vec n=vec(1,src[q].Y-src[q].X).ccw();
		ld d=n.dot(vec(0,src[q].X));
		bool in=false;
		int cnt=0;
		vector<vec> poly2;
		poly2.pb(poly[0]);
		ld area0=0;
		for(int i=1;i<sz(poly);++i){
			bool tin=n.dot(poly[i])<d;
			if(tin!=in){
				++cnt;
				vec td=(poly[i]-poly[i-1]).norm();
				vec np=poly[i-1]+td*(-(n.dot(poly[i-1])-d)/n.dot(td));
				in=tin;
				poly2.pb(np);
			}
			if(!in)
				poly2.pb(poly[i]);
			if(i>1 && i<sz(poly)-1)
				area0+=(poly[i-1].y+poly[i].y)*(poly[i].x-poly[i-1].x)*.5;
		}
		if(cnt!=2 && cnt!=0)
			exit(55);
		poly=poly2;
		ld area1=0;
		for(int i=2;i<sz(poly2)-1;++i){
			area1+=(poly[i-1].y+poly[i].y)*(poly[i].x-poly[i-1].x)*.5;
		}
		ans[q]+=area1-area0;
	}
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	int n,k;
	cin>>n>>k;
	vector<vector<int> > src(n,vector<int>(k+1));
	forn(i,n){
		forn(j,k+1){
			cin>>src[i][j];
		}
	}
	forn(i,k){
		vector<PII> v(n);
		forn(j,n){
			v[j]=mp(src[j][i],src[j][i+1]);
		}
		doit(v);
	}
	
	forn(i,n){
		printf("%.15lf\n",(double)ans[i]);
	}
	
	return 0;
}
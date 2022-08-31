#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
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
typedef long long lng;
typedef unsigned long long ulng;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef double ld;
typedef pair<int, int> PII;
typedef pair<short, short> PSS;
typedef pair<PII, int> PIII;
typedef pair<lng, lng> PLL;
typedef pair<ulng, ulng> PUU;
typedef pair<lng, int> PLI;
typedef pair<int, lng> PIL;
typedef pair<ld, ld> PDD;
template<class T> inline T sqr(T x) { return x * x; }
template<class T> inline string tostr(const T & x) { stringstream ss; ss << x; return ss.str(); }
inline lng parse(const string & s) { stringstream ss(s); lng x; ss >> x; return x; }
#define left asdleft
#define right asdright
#define link asdlink
//#define unlink asdunlink
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
const ld EPS = 1e-9;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
lng powmod(lng a,lng p,lng m){lng r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
#define TASKA "iota"

ld W,H;
vector<PDD> A;
ld P[1100][1100];
ld Q[1100][1100];

bool check(ld R,int i0){
	vector<pair<ld,int> > evs;
	int D=0;
	PDD v=A[i0];

	if(v.X<R){
		ld a=PI-acos(v.X/R);
		D+=2;
		evs.pb(mp(-a,-2));
		evs.pb(mp(+a,+2));
	}
	if(W-v.X<R){
		ld a=acos((W-v.X)/R);
		evs.pb(mp(-a,+2));
		evs.pb(mp(+a,-2));
	}
	if(v.Y<R){
		ld a=acos(v.Y/R);
		evs.pb(mp(-PI/2-a,+2));
		evs.pb(mp(-PI/2+a,-2));
	}
	if(H-v.Y<R){
		ld a=acos((H-v.Y)/R);
		evs.pb(mp(PI/2-a,+2));
		evs.pb(mp(PI/2+a,-2));
	}

	forv(i,A){
		if(i==i0 || A[i]==v)
			continue;
		ld d=P[i0][i];
		if(d>=R*2)
			continue;
		ld a=acos(d/2/R);
		ld x=Q[i0][i];
		if(x+a>PI)
			x-=2*PI;
		if(x-a<-PI){
			++D;
			evs.pb(mp(x+a,-1));
			evs.pb(mp(2*PI+x-a,+1));
		}else{
			evs.pb(mp(x-a,+1));
			evs.pb(mp(x+a,-1));
		}
	}
	
	sort(all(evs));
	if(D<=1)
		return true;
	forv(i,evs){
		D+=evs[i].Y;
		if(D<=1)
			return true;
	}
	
	return false;
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASKA".in", "r", stdin); freopen(TASKA".out", "w", stdout);
#endif

	int n;
	cin>>W>>H>>n;
	A.resize(n);
	forn(i,n){
		cin>>A[i].X>>A[i].Y;
	}
	random_shuffle(all(A));
	
	forn(i,n){
		forn(j,n){
			if(i<=j)
				P[i][j]=P[j][i]=sqrt(sqr(A[i].X-A[j].X)+sqr(A[i].Y-A[j].Y));
			if(A[i]!=A[j])
				Q[i][j]=atan2(A[j].Y-A[i].Y,A[j].X-A[i].X);
		}
	}
	
	//cout<<check(4.9999)<<endl;return 0;
	
	ld ans=0;
	forv(i0,A){
		ld a=ans,b=sqrt(sqr(H)+sqr(W));
		if(!check(a+EPS,i0))
			continue;
		forn(qqq,60){
			ld r=(a+b)/2;
			if(check(r,i0))
				a=r;
			else
				b=r;
		}
		ans=a;
	}
	
	printf("%.15lf",(double)ans);
	
	return 0;
}
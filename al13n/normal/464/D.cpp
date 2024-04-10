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
const ld EPS = 1e-9;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
lng powmod(lng a,lng p,lng m){lng r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
#define FAIL { cerr<<"assertion failed on line "<<__LINE__<<endl; exit(123);}

const lng mod=INF+7;

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	//ios_base::sync_with_stdio(false);cin.tie(0);

	int n,k;
	cin>>n>>k;
	
	vector<ld> P(2,1);
	vector<ld> Q(2,0);
	
	int i0=1;
	
	forn(qqq,n){
		if(qqq%1000==0){
			cerr<<qqq<<' '<<sz(P)<<' '<<i0<<endl;
		}
	
		P.pb(0);
		Q.pb(0);
		for(int i=sz(P)-2;i>=i0;--i){
			ld p0=(k-1.)/k;
			ld p2=1./k/(i+1);
			ld p1=1-p0-p2;
			
			P[i+1]+=P[i]*p2;
			Q[i+1]+=(Q[i]+P[i]*i)*p2;
			
			Q[i]=Q[i]*(p0+p1) + P[i]*p1*(i+1)/2.;
			P[i]*=(p0+p1);
		}
		
		if(P.back()<1e-100){
			P.pop_back();
			Q.pop_back();
		}
		while(P[i0]<1e-100)
			++i0;
	}
	
	ld r=0;
	for(int i=i0;i<sz(Q);++i){
		r+=Q[i];
	}
	
	r*=k;
	
	printf("%.15lf",(double)r);

	return 0;
}
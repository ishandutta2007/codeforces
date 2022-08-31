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

struct vec{
	lng a[3];
	
	void read(){
		forn(i,3){
			cin>>a[i];
		}
	}
	
	vec operator-(const vec &b)const{
		vec r;
		forn(i,3){
			r.a[i]=a[i]-b.a[i];
		}
		return r;
	}
	vec operator+(const vec &b)const{
		vec r;
		forn(i,3){
			r.a[i]=a[i]+b.a[i];
		}
		return r;
	}

	lng dot(const vec &b)const{
		lng r=0;
		forn(i,3){
			r+=a[i]*b.a[i];
		}
		return r;
	}
	lng lensq()const{
		return dot(*this);
	}
	bool operator!=(const vec &b)const{
		forn(i,3){
			if(a[i]!=b.a[i])
				return true;
		}
		return false;
	}
	bool operator<(const vec &b)const{
		return false;
	}
};

vec A[8];

void check(){
	pair<lng,vec> d[8];
	forn(i,8){
		vec t=A[i]-A[7];
		d[i]=mp(t.lensq(),t);
	}
	sort(d,d+8);
	if(!d[1].X ||
	   d[1].X!=d[2].X || d[1].X!=d[3].X ||
	   d[1].Y.dot(d[2].Y) ||
	   d[1].Y.dot(d[3].Y) ||
	   d[2].Y.dot(d[3].Y))
	   return;
	forn(j,3){
		forn(i,j){
			vec t=d[i+1].Y+d[j+1].Y;
			if(t!=d[4].Y && t!=d[5].Y && t!=d[6].Y)
				return;
		}
	}
	if(d[1].Y+d[2].Y+d[3].Y != d[7].Y)
		return;
	
	cout<<"YES";
	forn(q,8){
		cout<<'\n';
		forn(i,3){
			cout<<A[q].a[i]<<' ';
		}
	}
	exit(0);
}

void doit(int q){
	if(q==8){
		check();
		return;
	}
	
	do{
		doit(q+1);
	}while(next_permutation(A[q].a,A[q].a+3));
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);cin.tie(0);

	forn(i,8){
		A[i].read();
		sort(A[i].a,A[i].a+3);
	}
	
	doit(0);
	
	cout<<"NO";

	return 0;
}
#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
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
const double EPS = 1e-6;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;

struct base{
	double a,b;
	base(){}
	base(double a,double b):a(a),b(b){}
	base operator+(const base &x)const{
		return base(a+x.a,b+x.b);
	}
	base operator-(const base &x)const{
		return base(a-x.a,b-x.b);
	}
	base operator*(const base &x)const{
		return base(a*x.a-b*x.b,a*x.b+b*x.a);
	}
	base operator/(double d)const{
		return base(a/d,b/d);
	}
};

const int lim=1<<21;
int src[lim + 100];
base ar[lim + 100];

void fft (bool invert) {
	int n = lim;
	
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (ar[i], ar[j]);
	}
	
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w (1, 0);
			for (int j=0; j<len/2; ++j) {
				base u = ar[i+j],  v = ar[i+j+len/2] * w;
				ar[i+j] = u + v;
				ar[i+j+len/2] = u - v;
				w = w * wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			ar[i] = ar[i] / n;
}

void square(){
	fft(false);
	forn(i,lim){
		ar[i] = ar[i] * ar[i];
	}
	fft(true);
}

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	int n,m;
	cin>>n>>m;
	forn(i,n){
		int a;
		scanf("%d",&a);
		src[a]=1;
		ar[a].a=1;
	}
	forn(a,m+1){
		if(!src[a])
			continue;
		for(int b=a+a;b<=m;b+=a){
			if(!src[b]){
				cout<<"NO";
				return 0;
			}
		}
	}
	square();
	vector<int> res;
	forn(a,m+1){
		//cout<<ar[a].a<<' '<<ar[a].b<<endl;
		bool t=fabs(ar[a].a)>.5;
		if(t){
			if(!src[a]){
				cout<<"NO";
				return 0;
			}
		}else{
			if(src[a])
				res.pb(a);
		}
	}
	
	cout<<"YES\n"<<sz(res)<<'\n';
	forv(i,res){
		printf("%d ",res[i]);
	}

	return 0;
}
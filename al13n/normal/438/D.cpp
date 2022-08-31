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
typedef long double ld;
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
const ld EPS = 1e-12;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
lng powmod(lng a,lng p,lng m){lng r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
#define TASKA "iota"

int mx[410000];
lng sum[410000];

int A[110000];

void init(int a,int b,int k){
	if(b==a+1){
		mx[k]=A[a];
		sum[k]=A[a];
		return;
	}
	int c=(a+b)/2;
	init(a,c,k*2+1);
	init(c,b,k*2+2);
	mx[k]=max(mx[k*2+1],mx[k*2+2]);
	sum[k]=sum[k*2+1]+sum[k*2+2];
}

lng getsum(int l,int r,int a,int b,int k){
	if(l>=b || r<=a)
		return 0;
	if(l<=a && r>=b)
		return sum[k];
	int c=(a+b)/2;
	return getsum(l,r,a,c,k*2+1)+getsum(l,r,c,b,k*2+2);
}

void setval(int p,int v,int a,int b,int k){
	if(b==a+1){
		sum[k]=v;
		mx[k]=v;
		return;
	}
	int c=(a+b)/2;
	if(p<c)
		setval(p,v,a,c,k*2+1);
	else
		setval(p,v,c,b,k*2+2);
	mx[k]=max(mx[k*2+1],mx[k*2+2]);
	sum[k]=sum[k*2+1]+sum[k*2+2];
}

void setmod(int l,int r,int x,int a,int b,int k){
	if(mx[k]<x || l>=b || r<=a)
		return;
	if(b==a+1){
		sum[k]%=x;
		mx[k]%=x;
		return;
	}
	int c=(a+b)/2;
	setmod(l,r,x,a,c,k*2+1);
	setmod(l,r,x,c,b,k*2+2);
	sum[k]=sum[k*2+1]+sum[k*2+2];
	mx[k]=max(mx[k*2+1],mx[k*2+2]);
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASKA".in", "r", stdin); freopen(TASKA".out", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	cin>>n>>m;
	forn(i,n){
		cin>>A[i];
	}
	
	init(0,n,0);
	
	forn(q,m){
		int t;
		cin>>t;
		if(t==1){
			int l,r;
			cin>>l>>r;
			--l;
			cout<<getsum(l,r,0,n,0)<<'\n';
		}else if(t==2){
			int l,r,x;
			cin>>l>>r>>x;
			--l;
			setmod(l,r,x,0,n,0);
		}else if(t==3){
			int p,v;
			cin>>p>>v;
			--p;
			setval(p,v,0,n,0);
		}else
			exit(123);
	}
	
	return 0;
}
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
template<class T> inline T sqr(T x) { return x * x; }
template<class T> inline string tostr(const T & x) { stringstream ss; ss << x; return ss.str(); }
typedef long long lng;
typedef unsigned long long ulng;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<string, string> PSS;
typedef pair<PII, int> PIII;
typedef pair<lng, lng> PLL;
typedef pair<lng, int> PLI;
typedef pair<int, lng> PIL;
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
const ld EPS = 1e-9;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
lng powmod(lng a,lng p,lng m){lng r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
#define TASKA "holygame"

vector<PII> E;
int n;
char A[1100][1100];

int doit(int a,int b,int k){
	if(k==1){
		E.pb(mp(a,b));
		return 0;
	}
	if(k%2){
		int t=doit(a,b,k-1);
		int q=a;
		forn(i,t){
			E.pb(mp(q,n));
			q=n;
			++n;
		}
		E.pb(mp(q,b));
		return t;
	}else{
		E.pb(mp(a,n));
		E.pb(mp(n,n+1));
		E.pb(mp(a,n+2));
		E.pb(mp(n+2,n+1));
		n+=3;
		return doit(n-2,b,k/2)+2;
	}
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASKA".in", "r", stdin); freopen(TASKA".out", "w", stdout);
#endif
	
	int k;
	cin>>k;
	n=2;
	doit(0,1,k);
	if(n>1000)
		exit(123);
	forn(i,n){
		forn(j,n){
			A[i][j]='N';
		}
	}
	forv(i,E){
		A[E[i].X][E[i].Y]=A[E[i].Y][E[i].X]='Y';
	}
	cout<<n<<endl;
	forn(i,n){
		printf("%s\n",A[i]);
	}
	
	return 0;
}
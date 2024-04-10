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
typedef double ld;
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
const double EPS = 1e-6;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
uint gcd(uint a,uint b){return a?gcd(b%a,a):b;}

int n,m;
lng H[110000];
lng P[110000];

lng doit(lng p,lng h,lng t){
	if(p>h)
		return h+t;
	if(t<h-p)
		return -LINF;
	lng r=h+(t-(h-p))/2;
	if(t>(h-p)*2)
		r=max(r,h+t-(h-p)*2);
	return r;
}

bool check(lng T){
	int q=0;
	forn(i,n){
		lng d=doit(P[q],H[i],T);
		while(q<m && P[q]<=d)
			++q;
		if(q==m)
			return true;
	}
	return false;
}

int main(int argc, char **argv) {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	
	cin>>n>>m;
	forn(i,n){
		cin>>H[i];
	}
	forn(i,m){
		cin>>P[i];
	}
	
	lng a=-1,b=INF*100LL;
	while(b-a>1){
		lng k=(a+b)/2;
		if(check(k))
			b=k;
		else
			a=k;
	}
	cout<<b;
	
	return 0;
}
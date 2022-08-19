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
#include <unistd.h>
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

struct pt {
	lng x, y;
};

inline bool cmp_x (const pt & a, const pt & b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

inline bool cmp_y (const pt & a, const pt & b) {
	return a.y < b.y;
}

const int MAXN=110000;
pt a[MAXN];

lng mindist;

inline void upd_ans (const pt & a, const pt & b) {
	lng dist = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
	if (dist < mindist)
		mindist = dist;
}

void rec (int l, int r) {
	if (r - l <= 3) {
		for (int i=l; i<=r; ++i)
			for (int j=i+1; j<=r; ++j)
				upd_ans (a[i], a[j]);
		sort (a+l, a+r+1, &cmp_y);
		return;
	}
	
	int m = (l + r) >> 1;
	lng midx = a[m].x;
	rec (l, m),  rec (m+1, r);
	static pt t[MAXN];
	merge (a+l, a+m+1, a+m+1, a+r+1, t, &cmp_y);
	copy (t, t+r-l+1, a+l);
	
	int tsz = 0;
	for (int i=l; i<=r; ++i)
		if (sqr (a[i].x - midx) < mindist) {
			for (int j=tsz-1; j>=0 && sqr(a[i].y - t[j].y) < mindist; --j)
				upd_ans (a[i], t[j]);
			t[tsz++] = a[i];
		}
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASKA".in", "r", stdin); freopen(TASKA".out", "w", stdout);
#endif
	
	int n;
	cin>>n;
	lng s=0;
	forn(i,n){
		int x;
		scanf("%d",&x);
		s+=x;
		a[i].x=i;
		a[i].y=s;
	}
	
	sort (a, a+n, &cmp_x);
	mindist = LINF;
	rec (0, n-1);
	
	cout<<mindist;
	
	return 0;
}
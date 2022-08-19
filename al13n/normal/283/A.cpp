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

lng val[210000];
lng add[210000];
lng sum;
int n;

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	n=1;
	
	int tc;
	cin>>tc;
	forn(qqq,tc){
		int t;
		scanf("%d",&t);
		if(t==1){
			int a,x;
			scanf("%d%d",&a,&x);
			--a;
			add[a]+=x;
			sum+=(a+1LL)*x;
		}else if(t==2){
			int x;
			scanf("%d",&x);
			val[n]=x;
			add[n]=0;
			sum+=x;
			++n;
		}else if(t==3){
			--n;
			sum-=val[n]+add[n];
			add[n-1]+=add[n];
		}else exit(12);
		printf("%.15lf\n",1.*sum/n);
	}

	return 0;
}
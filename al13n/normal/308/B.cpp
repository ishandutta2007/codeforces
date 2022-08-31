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
#define hash asdhash
#define move asdmove
const double EPS = 1e-6;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}

int n,R,C;
char line[7000000];
int A[1100000];
int P[1100000];
int pos0[1100000];
int cur[1100000];
int res[1100000];

int main() {
#ifdef __ASD__
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif

	cin>>n>>R>>C;
	gets(line);
	gets(line);
	int l=0;
	int p=0;
	int st=0;
	for(int i=0;line[i];++i){
		if(line[i]==' ' && l){
			P[p]=st;
			A[p++]=l;
			l=0;
			st=i+1;
		}else{
			++l;
		}
	}
	if(l){
		P[p]=st;
		A[p++]=l;
	}
	l=strlen(line);
	if(line[l-1]==' ')
		exit(5);
	line[l]=' ';
	P[p]=l+1;
	if(p!=n)
		exit(123);

	forn(i,n+1){
		res[i]=i;
	}
	
	p=n;
	l=0;
	for(int i=n-1;i>=0;--i){
		l+=A[i];
		while(l+(p-i-1)>C){
			--p;
			l-=A[p];
		}
		pos0[i]=cur[i]=p;
	}
	pos0[n]=cur[n]=n;

	for(int k=1;k<=R;k*=2){
		if(R&k){
			forn(i,n){
				res[i]=cur[res[i]];
			}
		}
		forn(i,n){
			cur[i]=cur[cur[i]];
		}
	}

	PII best(0,0);
	forn(i,n){
		best=max(best,mp(res[i]-i,i));
	}
	
	p=best.Y;
	forn(q,R){
		if(pos0[p]==p)
			puts("");
		else{
			line[P[pos0[p]]-1]=0;
			puts(line+P[p]);
		}
		p=pos0[p];
	}

	return 0;
}
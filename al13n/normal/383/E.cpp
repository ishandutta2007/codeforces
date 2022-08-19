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
const ld EPS = 1e-10;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795L;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}

const int L=24;
short A[3][1<<L];

void do12(short *v){
	forn(a,1<<L){
		short va=v[a];
		int i=0;
		while(i<L && !(a&(1<<i)))
			++i;
		++i;
		while(i<L && !(a&(1<<i))){
			v[a|(1<<i)]+=va;
			++i;
		}
	}
}
void do12r(short *v){
	forn(a,1<<L){
		short va=v[a];
		int i=L-1;
		while(i>=0 && !(a&(1<<i)))
			--i;
		--i;
		while(i>=0 && !(a&(1<<i))){
			v[a|(1<<i)]+=va;
			--i;
		}
	}
}
void do0(short *v){
	forn(a,1<<L){
		short va=v[a];
		int i=0;
		while(i<L && !(a&(1<<i))){
			v[a|(1<<i)]+=va;
			++i;
		}
	}
}
void do0r(short *v){
	forn(a,1<<L){
		short va=v[a];
		int i=L-1;
		while(i>=0 && !(a&(1<<i))){
			v[a|(1<<i)]+=va;
			--i;
		}
	}
}
void add(short *a,short *b){
	forn(i,1<<L){
		a[i]+=b[i];
	}
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	//freopen("input.txt","w",stdout);gen();return 0;
	
	//ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	forn(i,n){
		char s[10];
		scanf("\n%s",s);
		sort(s,s+3);
		int l=unique(s,s+3)-s;
		int m=0;
		forn(j,l){
			m|=1<<(s[j]-'a');
		}
		++A[l-1][m];
	}
	do12(A[2]);
	add(A[1],A[2]);
	do12r(A[1]);
	add(A[0],A[1]);
	do0(A[0]);
	do0r(A[0]);
	lng ans=0;
	forn(i,1<<L){
		lng r=n-A[0][i];
		ans^=r*r;
	}
	cout<<ans;
	
	return 0;
}
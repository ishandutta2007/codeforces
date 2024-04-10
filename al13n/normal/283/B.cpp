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

lng src[210000];

lng yval[210000];
int dest[210000];
bool inside[210000];
int n;

void doit(lng a){
	if(dest[a])
		return;
	
	if(inside[a]){
		dest[a]=-1;
		return;
	}

	inside[a]=true;
	do{
		yval[a]=src[a];
		lng aa=a-src[a];
		if(aa==1){
			dest[a]=1;
			break;
		}
		if(aa<=0 || aa>n){
			dest[a]=2;
			break;
		}
		yval[a]+=src[aa];
		aa+=src[aa];
		if(aa==1){
			dest[a]=1;
			break;
		}
		if(aa<=0 || aa>n){
			dest[a]=2;
			break;
		}
		
		doit(aa);
		
		dest[a]=dest[aa];
		yval[a]+=yval[aa];
	}while(false);
	inside[a]=false;
}

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	cin>>n;
	forn(i,n-1){
		scanf("%d",src+i+2);
	}
	
	for(lng v=1;v<n;++v){
		doit(v+1);
		if(dest[v+1]==-1 || dest[v+1]==1)
			cout<<-1;
		else
			cout<<yval[v+1]+v;
		cout<<'\n';
	}

	return 0;
}
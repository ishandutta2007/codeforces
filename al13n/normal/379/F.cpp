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
const ld EPS = 1e-14;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795L;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}

const int L=20;
int D[1100000];
int up[1100000][L];

int todep(int v,int d){
	for(int i=L-1;i>=0;--i){
		if(D[up[v][i]]>=d)
			v=up[v][i];
	}
	return v;
}
int lca(int a,int b){
	int d=min(D[a],D[b]);
	a=todep(a,d);
	b=todep(b,d);
	if(a==b)
		return a;
	for(int i=L-1;i>=0;--i){
		if(up[a][i]!=up[b][i])
			a=up[a][i],b=up[b][i];
	}
	return up[a][0];
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	int tc;
	cin>>tc;
	int n=4;
	D[0]=0;
	D[1]=D[2]=D[3]=1;
	int v0=1;
	int res=2;
	forn(qqq,tc){
		int v;
		scanf("%d",&v);
		--v;
		int l=lca(v,v0);
		int r=D[v]+D[v0]-D[l]*2;
		if(r>res)
			exit(123);
		res=max(res+(D[v]==D[v0]),r+1);
		if(D[v]==D[v0])
			v0=n;
		printf("%d\n",res);
		
		n+=2;
		for(int i=n-2;i<=n-1;++i){
			D[i]=D[v]+1;
			up[i][0]=v;
			forn(j,L-1){
				up[i][j+1]=up[up[i][j]][j];
			}
		}
	}
	
	return 0;
}
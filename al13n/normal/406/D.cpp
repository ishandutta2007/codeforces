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
const ld EPS = 1e-12;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
lng powmod(lng a,lng p,lng m){lng r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
#define TASKA "sequence"

int n;
PLL A[110000];
int P[110000][20];
int D[110000];

bool cw(PLL a,PLL b,PLL c){
	return (b.X-a.X)*(c.Y-b.Y)<(b.Y-a.Y)*(c.X-b.X);
}

int todep(int v,int d){
	for(int i=19;i>=0;--i){
		if(D[P[v][i]]>=d)
			v=P[v][i];
	}
	return v;
}

int lca(int a,int b){
	int d=min(D[a],D[b]);
	a=todep(a,d);
	b=todep(b,d);
	if(a==b)
		return a;
	for(int i=19;i>=0;--i){
		if(P[a][i]!=P[b][i])
			a=P[a][i],b=P[b][i];
	}
	return P[a][0];
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASKA".in", "r", stdin); freopen(TASKA".out", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	forn(i,n){
		cin>>A[i].X>>A[i].Y;
	}
	
	vector<int> st;
	for(int i=n-1;i>=0;--i){
		while(sz(st)>=2 && cw(A[st[sz(st)-2]],A[st.back()],A[i]))
			st.pop_back();
		if(i<n-1){
			P[i][0]=st.back();
			D[i]=D[P[i][0]]+1;
			//cout<<i<<": "<<P[i][0]<<endl;
		}
		st.pb(i);
	}
	P[n-1][0]=n-1;
	
	forn(k,19){
		forn(i,n){
			P[i][k+1]=P[P[i][k]][k];
		}
	}
	
	int tc;
	cin>>tc;
	forn(qqq,tc){
		int a,b;
		cin>>a>>b;
		--a;--b;
		cout<<lca(a,b)+1<<' ';
	}
	
	return 0;
}
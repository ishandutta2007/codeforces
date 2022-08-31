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

char A[1100][100];
int dsu[1100];
vector<int> gr[1100];
bool was[1100];

int get(int a){
	return dsu[a]==a?a:dsu[a]=get(dsu[a]);
}

void dfs(int v,int pr){
	if(was[v])
		return;
	was[v]=true;
	cout<<v+1<<' '<<pr+1<<'\n';
	forv(i,gr[v]){
		dfs(gr[v][i],v);
	}
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASKA".in", "r", stdin); freopen(TASKA".out", "w", stdout);
#endif

	int n,m,k,w;
	cin>>n>>m>>k>>w;
	static char line[15];
	gets(line);
	forn(q,k){
		forn(i,n){
			gets(line);
			memcpy(A[q]+i*m,line,m);
		}
	}
	n*=m;
	
	vector<pair<int,PII> > E;
	E.reserve(k*(k-1)/2);
	forn(b,k){
		forn(a,b){
			int c=0;
			forn(i,n){
				if(A[a][i]!=A[b][i])
					++c;
			}
			E.pb(mp(c,mp(a,b)));
		}
	}
	
	forn(i,k){
		dsu[i]=i;
	}
	
	sort(all(E));
	int ans=n*k;
	forv(q,E){
		if(E[q].X*w>=n)
			break;
		int aa=E[q].Y.X;
		int bb=E[q].Y.Y;
		int a=get(aa);
		int b=get(bb);
		if(a==b)
			continue;
		ans+=E[q].X*w-n;
		dsu[a]=b;
		gr[aa].pb(bb);
		gr[bb].pb(aa);
	}
	cout<<ans<<'\n';
	
	forn(i,k){
		if(was[i])
			continue;
		dfs(i,-1);
	}
	
	return 0;
}
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
typedef double ld;
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
#define FAIL { cerr<<"assertion failed on line "<<__LINE__<<endl; exit(123);}

const int MAXN=110000;
vector<int> gr[MAXN];
bool C[MAXN];
bool H[MAXN];

bool dfs1(int v,int pr){
	H[v]=C[v];
	forv(i,gr[v]){
		int p=gr[v][i];
		if(p==pr)
			continue;
		H[v]|=dfs1(p,v);
	}
	return H[v];
}

const lng mod=INF+7;

PLL dfs2(int v,int pr){
	vector<PLL> ts;
	lng my=1;
	forv(i,gr[v]){
		int p=gr[v][i];
		if(p==pr || !H[p])
			continue;
		PLL t=dfs2(p,v);
		ts.pb(t);
		(my*=t.Y)%=mod;
	}
	
	if(C[v]){
		return mp(my,my);
	}
	
	vector<lng> mys(1,1);
	forv(i,ts){
		mys.pb(mys.back()*ts[i].Y%mod);
	}
	
	lng r=0;
	lng m=1;
	for(int i=sz(ts)-1;i>=0;--i){
		(r+=ts[i].X*m%mod*mys[i])%=mod;
		(m*=ts[i].Y)%=mod;
	}

	return mp(r,(r+my)%mod);
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);cin.tie(0);

	int n;
	cin>>n;
	forn(i,n-1){
		int a;
		cin>>a;
		gr[i+1].pb(a);
		gr[a].pb(i+1);
	}
	int v0=-1;
	forn(i,n){
		cin>>C[i];
		if(C[i])
			v0=i;
	}
	
	if(v0==-1)
		exit(123);
		
	dfs1(v0,-1);
	
	PLL r=dfs2(v0,-1);
	cout<<r.X;

	return 0;
}
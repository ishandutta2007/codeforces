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
#define fail(msg) { cerr<<msg<<endl; cout<<msg<<endl; exit((__LINE__-1) % 200 + 1);}

vector<vector<PII> > gr;
vector<char> was;
vector<lng> W;

pair<int,lng> dfs(int v,int e0){
	if(was[v])
		return mp(0,0);
	was[v]=true;
	pair<int,lng> r(1,W[v]);
	forv(i,gr[v]){
		if(gr[v][i].Y>=e0)
			continue;
		int p=gr[v][i].X;
		auto t=dfs(p,e0);
		r.X+=t.X;
		r.Y+=t.Y;
	}
	return r;
}

bool check(int e0){
	was.assign(sz(gr),0);
	vector<pair<int,lng> > A;
	lng s=0;
	forv(i,gr){
		if(!was[i]){
			A.pb(dfs(i,e0));
			s+=A.back().Y;
		}
	}
	forv(i,A){
		if(A[i].X>s-A[i].Y)
			return false;
	}
	return true;
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);cin.tie(0);

	int n;
	cin>>n;
	gr.resize(n);
	vector<int> es;
	forn(i,n-1){
		int a,b,c;
		cin>>a>>b>>c;
		--a;--b;
		gr[a].pb(mp(b,c));
		gr[b].pb(mp(a,c));
		es.pb(c);
	}
	W.resize(n);
	forn(i,n){
		cin>>W[i];
	}
	
	sort(all(es));
	es.erase(unique(all(es)),es.end());
	
	int a=0,b=sz(es);
	while(b>a+1){
		int c=(a+b)/2;
		if(check(es[c]))
			a=c;
		else
			b=c;
	}
	
	cout<<(sz(es)?es[a]:0);
	
	return 0;
}
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

int n;

vector<int> doit(int a,int b){
	vector<int> r;
	
	if(a+b>=n){
		a=n-a-1;
		b=n-b-1;
	}
	if(a>b)
		swap(a,b);

	r.pb(a+b);
	if(b-a>=2)
		r.pb(b-a-2);

	return r;
}

map<int,vector<PII> > gr;
map<int,int> C;
set<int> was;

void setc(int a,int c){
	if(C.count(a) && C[a]!=c){
		cout<<0;
		exit(0);
	}
	C[a]=c;
}

void dfs(int v,int c){
	setc(v,c);
	if(was.count(v))
		return;
	was.insert(v);
	for(auto it : gr[v]){
		dfs(it.X,c^it.Y);
	}
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);cin.tie(0);

	int k;
	cin>>n>>k;
	forn(i,k){
		int a,b;
		char c;
		cin>>a>>b>>c;
		c=c=='o';
		--a;--b;
		auto t=doit(a,b);
		if(sz(t)==1)
			setc(t[0],c);
		else if(sz(t)==2){
			gr[t[0]].pb(mp(t[1],c));
			gr[t[1]].pb(mp(t[0],c));
		}else
			exit(123);
	}
	
	for(auto &it : C){
		int v=it.X;
		if(was.count(v))
			continue;
		dfs(v,it.Y);
	}
	
	const lng mod=INF+7;
	lng ans=1;
	forn(v,n){
		if(was.count(v))
			continue;
		dfs(v,0);
		(ans*=2)%=mod;
	}
	
	cout<<ans;

	return 0;
}
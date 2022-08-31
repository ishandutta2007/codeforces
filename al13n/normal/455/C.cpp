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

vector<vector<int> > gr;
vector<int> dsu;
vector<int> K;

int get(int a){
	return dsu[a]==a?a:dsu[a]=get(dsu[a]);
}

PII dfs(int v,int pr){
	PII r(0,v);
	forv(i,gr[v]){
		int p=gr[v][i];
		if(p==pr)
			continue;
		PII t=dfs(p,v);
		++t.X;
		r=max(r,t);
	}
	return r;
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	//ios_base::sync_with_stdio(false);

	int n,m,Q;
	cin>>n>>m>>Q;
	gr.resize(n);
	dsu.resize(n);
	K.resize(n);
	forn(i,n){
		dsu[i]=i;
	}
	forn(i,m){
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		gr[a].pb(b);
		gr[b].pb(a);
		dsu[get(a)]=get(b);
	}
	
	forn(v,n){
		if(v!=get(v))
			continue;
		PII t=dfs(v,-1);
		K[v]=dfs(t.Y,-1).X;
	}
	
	forn(qqq,Q){
		int T,x,y;
		scanf("%d%d",&T,&x);
		--x;
		x=get(x);
		if(T==1){
			printf("%d\n",K[x]);
		}else{
			scanf("%d",&y);
			--y;
			y=get(y);
			if(x!=y){
				K[x]=max(max(K[x],K[y]),(K[x]+1)/2+(K[y]+1)/2+1);
				dsu[y]=x;
			}
		}
	}

	return 0;
}
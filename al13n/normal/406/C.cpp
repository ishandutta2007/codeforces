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
vector<int> gr[110000];
int D[110000];
vector<pair<int,PII> > ans;

bool dfs(int v,int d,int pr){
	D[v]=d;
	int x=-1;
	forv(i,gr[v]){
		int p=gr[v][i];
		bool t=false;
		if(D[p]){
			if(p != pr && D[p]<d)
				t=true;
		}else
			t=dfs(p,d+1,v);
		if(!t)
			continue;
		if(x==-1)
			x=p;
		else{
			ans.pb(mp(p,mp(v,x)));
			x=-1;
		}
	}
	if(x!=-1){
		ans.pb(mp(pr,mp(v,x)));
		return false;
	}
	return true;
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASKA".in", "r", stdin); freopen(TASKA".out", "w", stdout);
#endif
	
	int m;
	cin>>n>>m;
	forn(i,m){
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	if(!dfs(0,1,-1)){
		cout<<"No solution";
		return 0;
	}
	forv(i,ans){
		printf("%d %d %d\n",ans[i].X + 1, ans[i].Y.X+1, ans[i].Y.Y+1);
	}
	
	return 0;
}
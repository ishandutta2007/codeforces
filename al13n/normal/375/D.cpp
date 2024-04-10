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

struct thing{
	map<int,int> cnt;
	vector<int> res;
	int n;
	
	thing():n(0){}
	
	void add(int x){
		int a=cnt[x]++;
		if(a==sz(res))
			res.pb(1);
		else
			++res[a];
		++n;
	}
	void merge(const thing &b){
		for(map<int,int>::const_iterator it=b.cnt.begin();it!=b.cnt.end();++it){
			forn(i,it->Y){
				add(it->X);
			}
		}
	}
};

int n,m;
int ans[110000];
vector<int> gr[110000];
vector<PII> qu[110000];
int C[110000];

thing* merge(thing *a,thing *b){
	if(b->n>a->n)
		swap(a,b);
	a->merge(*b);
	return a;
}

thing* dfs(int v,int pr){
	thing *r=new thing;
	r->add(C[v]);
	forv(i,gr[v]){
		int p=gr[v][i];
		if(p==pr)
			continue;
		r=merge(r,dfs(p,v));
	}
	forv(i,qu[v]){
		int k=qu[v][i].X;
		int p=qu[v][i].Y;
		ans[p]=k-1<sz(r->res)?r->res[k-1]:0;
	}
	return r;
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	cin>>n>>m;
	forn(i,n){
		scanf("%d",C+i);
	}
	forn(i,n-1){
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	forn(i,m){
		int v,k;
		scanf("%d%d",&v,&k);
		--v;
		qu[v].pb(mp(k,i));
	}
	dfs(0,0);
	forn(i,m){
		printf("%d\n",ans[i]);
	}
	
	return 0;
}
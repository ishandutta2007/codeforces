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

int n,k;
vector<int> gr[110000];
const int lim=17;
int J[110000][lim];
int D[110000];
int tin[110000];
int vert[110000];
int timer;

void dfs(int v,int d,int pr){
	tin[v]=timer;
	vert[timer]=v;
	++timer;
	D[v]=d;
	J[v][0]=pr;
	for(int i=1;i<lim;++i){
		J[v][i]=J[J[v][i-1]][i-1];
	}
	forv(i,gr[v]){
		int p=gr[v][i];
		if(p==pr)
			continue;
		dfs(p,d+1,v);
	}
}

int todep(int a,int d){
	if(D[a]==d)
		return a;
	for(int i=lim-1;i>=0;--i){
		if(D[a]-d>=(1<<i))
			a=J[a][i];
	}
	if(D[a]!=d)
		exit(123);
	return a;
}

int lca(int a,int b){
	int d=min(D[a],D[b]);
	a=todep(a,d);
	b=todep(b,d);
	if(a==b)
		return a;
	for(int i=lim-1;i>=0;--i){
		if(J[a][i]!=J[b][i])
			a=J[a][i],b=J[b][i];
	}
	return J[a][0];
}

set<int> S;
int cnt;

void doit(const set<int>::iterator &t,int s){
	int v=*t;
	int a,b;
	set<int>::iterator it=t;
	++it;
	if(it==S.end())
		b=*S.begin();
	else
		b=*it;
	if(t==S.begin())
		a=*S.rbegin();
	else{
		it=t;
		--it;
		a=*it;
	}
	cnt+=s*D[vert[v]];
	cnt+=s*D[lca(vert[a],vert[b])];
	cnt-=s*D[lca(vert[a],vert[v])];
	cnt-=s*D[lca(vert[b],vert[v])];
}

void add(int v){
	pair<set<int>::iterator,bool> t=S.insert(v);
	if(!t.Y)
		exit(5);
	doit(t.X,1);
}

void del(int v){
	set<int>::iterator t=S.find(v);
	if(t==S.end())
		exit(7);
	doit(t,-1);
	S.erase(t);
}

bool check(int w){
	cnt=1;
	S.clear();
	forn(i,n){
		add(tin[i]);
		if(i-w>=0)
			del(tin[i-w]);
		if(i+1>=w && cnt<=k)
			return true;
	}
	return false;
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	cin>>n>>k;
	forn(i,n-1){
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	dfs(0,0,0);
	
	int a=1,b=n+1;
	while(b>a+1){
		int w=(a+b)/2;
		if(check(w))
			a=w;
		else
			b=w;
	}
	
	cout<<a;
	
	return 0;
}
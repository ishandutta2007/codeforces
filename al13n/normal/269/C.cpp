#pragma comment(linker, "/STACK:256000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
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
typedef double ld;
typedef pair<int, int> PII;
typedef pair<lng, lng> PLL;
typedef pair<lng, int> PLI;
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
const double EPS = 1e-9;
const int INF = 1000*1000*1000;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;

int n,m;
vector<pair<PII,int> > gr[210000];
int need[210000];
PII edges[210000];
int res[210000];

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	
	clr(res,-1);
	cin>>n>>m;
	forn(i,m){
		int a,b,c;
		cin>>a>>b>>c;
		--a;--b;
		gr[a].pb(mp(mp(b,c),i));
		gr[b].pb(mp(mp(a,c),i));
		edges[i]=mp(a,b);
	}
	forn(i,n){
		int s=0;
		forv(j,gr[i]){
			s+=gr[i][j].X.Y;
		}
		if(!i)
			need[i]=0;
		else if(i==n-1)
			need[i]=s;
		else{
			if(s%2)
				exit(44);
			need[i]=s/2;
		}
	}
	vector<int> qu;
	qu.pb(0);
	while(!qu.empty()){
		int v=qu.back();
		qu.pop_back();
		forv(i,gr[v]){
			int p=gr[v][i].X.X;
			int w=gr[v][i].X.Y;
			int e=gr[v][i].Y;
			if(res[e]!=-1)
				continue;
			res[e]=edges[e].Y==v;
			need[p]-=w;
			if(!need[p])
				qu.pb(p);
		}
	}
	forn(i,m){
		if(res[i]==-1)
			exit(66);
		cout<<res[i]<<'\n';
	}
	
	return 0;
}
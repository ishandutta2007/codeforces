#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
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
typedef pair<PII, int> PIII;
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
#define hash asdhash
const double EPS = 1e-6;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;

int n,m;
PII gr[11000];
int comp1[11000][510];
int comp2[11000][510];

struct dsu{
	int go[510];
	int cnt;
	
	dsu(){
		forn(i,n){
			go[i]=i;
		}
		cnt=n;
	}
	
	int get(int a){
		return go[a]==a?a:(go[a]=get(go[a]));
	}
	void merge(int a,int b){
		a=get(a);
		b=get(b);
		if(a==b)
			return;
		--cnt;
		go[a]=b;
	}
	void getall(int *r){
		forn(i,n){
			r[i]=get(i);
		}
	}
};

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	
	cin>>n>>m;
	dsu d;
	d.getall(comp1[0]);
	forn(i,m){
		int a,b;
		cin>>a>>b;
		--a;--b;
		gr[i]=mp(a,b);
		d.merge(a,b);
		d.getall(comp1[i+1]);
	}
	d=dsu();
	d.getall(comp2[m]);
	for(int i=m-1;i>=0;--i){
		d.merge(gr[i].X,gr[i].Y);
		d.getall(comp2[i]);
	}
	
	int tc;
	cin>>tc;
	forn(qqq,tc){
		int a,b;
		cin>>a>>b;
		--a;
		dsu d;
		forn(i,n){
			d.merge(i,comp1[a][i]);
			d.merge(i,comp2[b][i]);
		}
		cout<<d.cnt<<'\n';
	}

	return 0;
}
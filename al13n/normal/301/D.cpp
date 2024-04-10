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

int tree[2000000];

void add(int p,int v,int a,int b,int k){
	if(b==a+1){
		tree[k]+=v;
		return;
	}
	int c=(a+b)/2;
	if(p<c)
		add(p,v,a,c,k*2+1);
	else
		add(p,v,c,b,k*2+2);
	tree[k]=tree[k*2+1]+tree[k*2+2];
}

int getsum(int l,int r,int a,int b,int k){
	if(r<=a||l>=b)
		return 0;
	if(l<=a&&r>=b)
		return tree[k];
	int c=(a+b)/2;
	return getsum(l,r,a,c,k*2+1)+getsum(l,r,c,b,k*2+2);
}

vector<PII> rs[210000];
vector<int> ds[210000];
int P[210000];
int res[210000];
int n;

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	int m;
	cin>>n>>m;
	forn(i,n){
		int a;
		scanf("%d",&a);
		P[a]=i;
	}
	forn(i,m){
		int l,r;
		scanf("%d%d",&l,&r);
		--l;
		rs[l].pb(mp(r,i));
	}
	for(int a=1;a<=n;++a){
		for(int b=a;b<=n;b+=a){
			int x=P[a];
			int y=P[b];
			if(y<x)
				swap(x,y);
			ds[x].pb(y);
		}
	}
	for(int i=n-1;i>=0;--i){
		forv(j,ds[i]){
			add(ds[i][j],1,0,n,0);
		}
		forv(j,rs[i]){
			res[rs[i][j].Y]=getsum(0,rs[i][j].X,0,n,0);
		}
	}
	forn(i,m){
		printf("%d\n",res[i]);
	}
	
	return 0;
}
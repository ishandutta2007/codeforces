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

int tree[2000000];

void pre(int k){
	if(tree[k]!=INF){
		tree[k*2+1]=tree[k*2+2]=tree[k];
		tree[k]=INF;
	}
}

int get(int p,int a,int b,int k){
	if(tree[k]!=INF)
		return tree[k];
	int c=(a+b)/2;
	if(p<c)
		return get(p,a,c,k*2+1);
	else
		return get(p,c,b,k*2+2);
}

void setval(int l,int r,int v,int a,int b,int k){
	if(r<=l || r<=a || l>=b)
		return;
	if(l<=a && r>=b){
		tree[k]=v;
		return;
	}
	pre(k);
	int c=(a+b)/2;
	setval(l,r,v,a,c,k*2+1);
	setval(l,r,v,c,b,k*2+2);
}

int ab[210000];

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	
	int n,m;
	cin>>n>>m;
	forn(i,n+n){
		cin>>ab[i];
	}
	
	tree[0]=n;
	
	forn(i,m){
		int t;
		cin>>t;
		if(t==1){
			int x,y,k;
			cin>>x>>y>>k;
			--x;--y;
			setval(y,y+k,x-y,0,n,0);
		}else{
			int x;
			cin>>x;
			--x;
			cout<<ab[x+get(x,0,n,0)]<<'\n';
		}
	}

	return 0;
}
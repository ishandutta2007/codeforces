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
typedef double ld;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<int, lng> PLL;
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
#define move asdmove
#define pow10 asdpow10
const double EPS = 1e-6;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
uint gcd(uint a,uint b){return a?gcd(b%a,a):b;}

const lng mod=INF+7;
lng tree[500000];

void setv(int p,lng v,int a,int b,int k){
	if(b==a+1){
		tree[k]=v;
		return;
	}
	int c=(a+b)/2;
	if(p<c)
		setv(p,v,a,c,k*2+1);
	else
		setv(p,v,c,b,k*2+2);
	tree[k]=(tree[k*2+1]+tree[k*2+2])%mod;
}

lng getsum(int l,int r,int a,int b,int k){
	if(r<=a||l>=b)
		return 0;
	if(a>=l&&b<=r)
		return tree[k];
	int c=(a+b)/2;
	return (getsum(l,r,a,c,k*2+1)+getsum(l,r,c,b,k*2+2))%mod;
}

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	
	int n;
	cin>>n;
	vector<int> ar(n);
	forn(i,n){
		cin>>ar[i];
	}
	vector<int> vs=ar;
	sort(all(vs));
	vs.erase(unique(all(vs)),vs.end());
	int m=sz(vs)+1;
	setv(0,1,0,m,0);
	forn(i,n){
		int k=lower_bound(all(vs),ar[i])-vs.begin();
		++k;
		setv(k,getsum(0,k+1,0,m,0)*ar[i]%mod,0,m,0);
	}
	cout<<getsum(1,m,0,m,0);
	
	return 0;
}
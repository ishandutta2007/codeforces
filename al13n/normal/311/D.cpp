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
const double EPS = 1e-6;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
uint gcd(uint a,uint b){return a?gcd(b%a,a):b;}

const lng mod=95542721;
const int per=48;

struct node{
	int s[per];
	int add;
};

node tree[1000000];
lng A[110000];

void init(int a,int b,int k){
	if(b==a+1){
		lng v=A[a];
		forn(i,per){
			tree[k].s[i]=(int)v;
			v=v*v%mod*v%mod;
		}
		return;
	}
	int c=(a+b)/2;
	init(a,c,k*2+1);
	init(c,b,k*2+2);
	forn(i,per){
		tree[k].s[i]=(tree[k*2+1].s[i]+tree[k*2+2].s[i])%mod;
	}
}

void pre(int k){
	int t=tree[k].add%=per;
	if(!t)
		return;
	rotate(tree[k].s,tree[k].s+t,tree[k].s+per);
	tree[k].add=0;
	tree[k*2+1].add+=t;
	tree[k*2+2].add+=t;
}

void doit(int l,int r,int a,int b,int k){
	pre(k);
	if(r<=a || l>=b)
		return;
	if(l<=a && r>=b){
		tree[k].add+=1;
		pre(k);
		return;
	}
	int c=(a+b)/2;
	doit(l,r,a,c,k*2+1);
	doit(l,r,c,b,k*2+2);
	forn(i,per){
		tree[k].s[i]=(tree[k*2+1].s[i]+tree[k*2+2].s[i])%mod;
	}
}

lng getsum(int l,int r,int a,int b,int k){
	pre(k);
	if(l>=b || r<=a)
		return 0;
	if(l<=a && r>=b)
		return tree[k].s[0];
	int c=(a+b)/2;
	return (getsum(l,r,a,c,k*2+1)+getsum(l,r,c,b,k*2+2))%mod;
}

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin>>n;
	forn(i,n){
		int a;
		scanf("%d",&a);
		A[i]=a;
	}
	init(0,n,0);
	int q;
	cin>>q;
	forn(i,q){
		int t,a,b;
		scanf("%d%d%d",&t,&a,&b);
		--a;
		if(t==2){
			doit(a,b,0,n,0);
		}else{
			printf("%d\n",(int)getsum(a,b,0,n,0));
		}
	}
	
	return 0;
}
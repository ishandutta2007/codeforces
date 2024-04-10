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

int A0[1<<20];
int A[1<<20];
int T[1<<20];
lng I1[25];
lng I2[25];

void mergesort(int a,int k){
	if(!k)
		return;
	int b=a+(1<<(k-1));
	int c=a+(1<<k);
	mergesort(a,k-1);
	mergesort(b,k-1);
	int i=a,j=b;
	int p=a;
	while(i<b || j<c){
		if(i<b && (j==c || A[i]<=A[j])){
			T[p++]=A[i++];
		}else{
			I2[k]+=b-i;
			T[p++]=A[j++];
		}
	}
	for(int i=a;i<c;++i){
		A[i]=T[i];
	}
}

void gen(){
	freopen("input.txt", "w", stdout);
	cout<<20<<endl;
	forn(i,1<<20){
		cout<<rand()<<'\n';
	}
	cout<<1000000<<'\n';
	forn(i,1000000){
		cout<<rand()%21<<'\n';
	}
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASKA".in", "r", stdin); freopen(TASKA".out", "w", stdout);
#endif
	
	//ios_base::sync_with_stdio(false);
	
	//gen();return 0;
	
	int n;
	cin>>n;
	forn(i,1<<n){
		scanf("%d",A0+i);
	}
	
	forn(i,1<<n){
		A[i]=-A0[i];
	}
	mergesort(0,n);
	forn(i,n+1){
		I1[i]=I2[i];
		I2[i]=0;
	}
	forn(i,1<<n){
		A[i]=A0[i];
	}
	mergesort(0,n);
	
	int m;
	cin>>m;
	forn(qqq,m){
		int q;
		scanf("%d",&q);
		//*
		for(int k=1;k<=q;++k){
			swap(I1[k],I2[k]);
		}//*/
		lng r=0;
		for(int k=1;k<=n;++k){
			r+=I2[k];
		}
#ifdef __ASD__
		cout<<r<<'\n';
#else
		printf("%I64d\n",r);
#endif
	}

	return 0;
}
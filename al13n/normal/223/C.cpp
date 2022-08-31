#pragma comment(linker,"/STACK:256000000")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <complex>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <memory.h>
using namespace std;
#define sz(v) ((int)(v).size())
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define pb push_back
#define mp make_pair
#define istr stringstream
#define fi first
#define se second
#define X first
#define Y second
#define clr(a) memset((a),0,sizeof(a))
#define clr2(a) memset((a),-1,sizeof(a))
#define y0 asdy0
#define y1 asdy1
#define j0 asdj0
#define j1 asdj1
#define next asdnext
#define prev asdprev
#define link asdlink
#define unlink asdunlink
#define left asdleft
#define right asdright
#define hash asdhash
#define all(v) (v).begin(),(v).end()
typedef long long lng;
typedef unsigned int uint;
typedef unsigned long long ulng;
typedef unsigned char uchar;
typedef double ld;
typedef pair<int,int> PII;
typedef pair<ld,ld> PDD;
typedef pair<lng,lng> PLL;
typedef complex<double> com;
const ld PI=3.1415926535897932384626433832795;
const ld EPS=1e-3;
const int inf=1000000000;
const lng linf=1000000000000000000LL;
template<class T> inline T sqr(T x) { return x * x; }
int gcd(int a,int b){return a?gcd(b%a,a):b;}

const lng mod=inf+7;

lng powmod(lng a,lng p){
	lng r=1;
	while(p){
		if(p%2){
			r=r*a%mod;
		}
		p/=2;
		a=a*a%mod;
	}
	return r;
}

lng P[2100];
lng A[2100];

int main() {
#ifdef __ASD__
    freopen("input.txt","rt",stdin);freopen("output.txt","wt",stdout);
#endif
	
	int n;
	lng k;
	cin>>n>>k;
	--k;
	forn(i,n){
		cin>>A[i];
	}
	P[0]=1;
	for(int i=1;i<=n;++i){
		P[i]=P[i-1]*(i+k)%mod*powmod(i,mod-2)%mod;
	}
	
	forn(p,n){
		lng r=0;
		forn(i,p+1){
			r=(r+P[i]*A[p-i])%mod;
		}
		cout<<r<<' ';
	}
	
	return 0;
}
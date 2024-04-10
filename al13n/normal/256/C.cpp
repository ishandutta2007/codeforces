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
#define clr(a,v) memset((a),(v),sizeof(a))
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
#define div asddiv
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
const ld EPS=1e-12;
const int inf=1000000000;
const lng linf=1000000000000000000LL;
template<class T> inline T sqr(T x) { return x * x; }
int gcd(int a,int b){return a?gcd(b%a,a):b;}

const int lim=1000000;
int gr[lim];
int was[lim];
lng A[110000];

int main() {
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

	lng a=0,b=0;
	for(lng x=0;x<lim;++x){
		while(b*b<=x&&b<x){
			++was[gr[b]];
			++b;
		}
		while(a*a*a*a<x){
			--was[gr[a]];
			++a;
		}
		gr[x]=0;
		while(was[gr[x]])
			++gr[x];
	}
	
	int n;
	cin>>n;
	forn(i,n){
		cin>>A[i];
	}
	sort(A,A+n);
	int res=0;
	a=b=0;
	clr(was,0);
	forn(i,n){
		lng x=A[i];
		while(b*b<=x&&b<x){
			++was[gr[b]];
			++b;
		}
		while(a*a*a*a<x){
			--was[gr[a]];
			++a;
		}
		int g=0;
		while(was[g])
			++g;
		res^=g;
	}
	
	cout<<(res?"Furlo":"Rublo");

	return 0;
}
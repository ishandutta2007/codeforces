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
const ld EPS=1e-8;
const int inf=1000000000;
const lng linf=1000000000000000000LL;
template<class T> inline T sqr(T x) { return x * x; }
int gcd(int a,int b){return a?gcd(b%a,a):b;}



int main() {
#ifdef __ASD__
    freopen("input.txt","rt",stdin);freopen("output.txt","wt",stdout);
#endif

	int n,h;
	cin>>n>>h;
	vector<int> v(n);
	vector<PII> vv(n);
	forn(i,n){
		scanf("%d",&v[i]);
		vv[i]=mp(v[i],i);
	}
	sort(all(v));
	sort(all(vv));
	
	int t1=(v[n-2]+v[n-1]) - (v[0]+v[1]);
	int t2=max(v[n-2]+v[n-1],v[0]+v[n-1]+h)-min(v[0]+v[1]+h,n>2?(v[1]+v[2]):inf);
	
	cout<<min(t1,t2)<<'\n';
	forn(i,n){
		if(t1>t2 && i==vv[0].Y)
			cout<<"1 ";
		else
			printf("2 ");
	}
	
	return 0;
}
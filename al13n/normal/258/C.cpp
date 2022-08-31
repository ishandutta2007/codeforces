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

int cnt[110000];
int sum[110000];
const int n=101000;
const lng mod=inf+7;
int div[110000];

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

int main() {
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	
	int m;
	cin>>m;
	forn(i,m){
		int a;
		scanf("%d",&a);
		++cnt[a];
	}
	forn(i,n){
		sum[i+1]=sum[i]+cnt[i];
	}
	
	lng res=0;
	for(int a=1;a<n;++a){
		int c=0;
		for(int i=1;i*i<=a;++i){
			if(a%i==0){
				div[c++]=i;
				if(i*i!=a)
					div[c++]=a/i;
			}
		}
		sort(div,div+c);
		lng r=1;
		forn(i,c-1){
			r=r*powmod(i+1,sum[div[i+1]]-sum[div[i]])%mod;
		}
		r=r*(powmod(c,sum[n]-sum[a])-powmod(c-1,sum[n]-sum[a])+mod)%mod;
		res=(res+r)%mod;
	}
	cout<<res;
	
	return 0;
}
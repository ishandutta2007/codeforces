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
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}

int n,maxb,T;
int ar[110000];
int K;
int BS[11][110000];

int solve(int *B){
	vector<int> tv(B,B+n);
	sort(all(tv));
	int cnt=unique(all(tv))-tv.begin();
	if(T>=cnt)
		return cnt;
	clr(ar,0);
	int m=0;
	int lim=T;
	forn(p,lim){
		if(m >= cnt)
			break;
		if(T-p+m>=cnt)
			return cnt;
		forn(i,n){
			int a=B[i];
			int l=p,r=m+1;
			while(r>l+1){
				int p=(l+r)/2;
				if(ar[p]<a)
					l=p;
				else
					r=p;
			}
			ar[l+1]=a;
			if(l==m)
				++m;
		}
	}
	return m;
}

void gentest(){
	n=4472;
	maxb=4472;
	T=maxb-1;
	K=10;
	forn(q,K){
		forn(i,n){
			BS[q][i]=maxb-i;
		}
	}
}

void readtest(){
	cin>>K>>n>>maxb>>T;
	forn(i,K){
		forn(j,n){
			scanf("%d",BS[i]+j);
		}
	}
}

int main() {
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	
	//gentest();
	readtest();

	forn(i,K){
		cout<<solve(BS[i])<<'\n';
	}

	return 0;
}
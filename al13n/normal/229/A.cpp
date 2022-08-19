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

char src[110][11000];
int ar[110][11000];
int n,m;

int main() {
#ifdef __ASD__
    freopen("input.txt","rt",stdin);freopen("output.txt","wt",stdout);
#endif
	
	cin>>n>>m;
	gets(src[0]);
	forn(i,n){
		gets(src[i]);
		bool f=false;
		forn(j,m){
			src[i][j]-='0';
			if(src[i][j])
				f=true;
		}
		if(!f){
			cout<<-1;
			exit(0);
		}
	}
	
	forn(i,n){
		forn(j,m){
			ar[i][j]=inf;
		}
		forn(j,m+m){
			if(!src[i][j%m])
				continue;
			ar[i][j%m]=0;
			for(int k=j+1;!src[i][k%m];++k){
				ar[i][k%m]=min(ar[i][k%m],k-j);
			}
		}
		reverse(src[i],src[i]+m);
		reverse(ar[i],ar[i]+m);
		forn(j,m+m){
			if(!src[i][j%m])
				continue;
			ar[i][j%m]=0;
			for(int k=j+1;!src[i][k%m];++k){
				ar[i][k%m]=min(ar[i][k%m],k-j);
			}
		}
	}
	
	int r=inf;
	forn(j,m){
		int s=0;
		forn(i,n){
			s+=ar[i][j];
		}
		r=min(r,s);
	}
	
	cout<<r;
	
	return 0;
}
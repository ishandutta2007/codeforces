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

lng doit(lng k,lng a,lng b){
	if(k<=0)
		return 0;
	if(k<=a&&k<=b)
		return k*(k+1)/2;
	if(k>=a&&k>=b)
		return a*b-doit(a+b-1-k,a,b);
	if(a>b)
		swap(a,b);
	return a*(k+k-a+1)/2;
}

vector<int> pos[1100000];

int main() {
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	vector<int> ind;
	forn(i,n){
		int a;
		cin>>a;
		pos[a].pb(i);
		ind.pb(a);
	}
	sort(all(ind));
	ind.erase(unique(all(ind)),ind.end());
	int res=1;
	forv(a,ind){
		vector<int> &A=pos[ind[a]];
res=max(res,sz(A));
		forn(b,a){
			vector<int> &B=pos[ind[b]];
			int i=0,j=0;
			int r=0;
			int p=-1;
			while(i<sz(A)||j<sz(B)){
				if(i<sz(A)&&(j==sz(B)||A[i]<B[j])){
					++i;
					if(p!=0)
						++r;
					p=0;
				}else{
					++j;
					if(p!=1)
						++r;
					p=1;
				}
			}
			res=max(res,r);
		}
	}
	cout<<res;

	return 0;
}
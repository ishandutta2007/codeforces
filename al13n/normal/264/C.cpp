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

int V[110000];
int C[110000];
lng dp[110000];

int main() {
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

	int n,q;
	cin>>n>>q;
	forn(i,n){
		scanf("%d",V+i);
	}
	forn(i,n){
		scanf("%d",C+i);
	}
	forn(qq,q){
		int A,B;
		cin>>A>>B;
		forn(i,n+10){
			dp[i]=-linf;
		}
		pair<lng,int> mx1(-linf,0),mx2(-linf,1);
		forn(i,n){
			int c=C[i];
			lng v=V[i];
			lng t=mx1.Y==c?mx2.X:mx1.X;
			lng r=max(max(B*v,dp[c]+A*v),t+B*v);
			if(r>dp[c]){
				dp[c]=r;
				if(mx1.Y==c)
					mx1.X=r;
				else if(mx2.Y==c){
					mx2.X=r;
					if(mx2>mx1)
						swap(mx1,mx2);
				}else if(r>mx1.X){
					mx2=mx1;
					mx1=mp(r,c);
				}else if(r>mx2.X){
					mx2=mp(r,c);
				}
			}
		}
		cout<<max(0LL,mx1.X)<<'\n';
	}

	return 0;
}
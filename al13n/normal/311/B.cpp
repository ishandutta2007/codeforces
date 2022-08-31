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

int n,p;
lng A[110000];
lng sum[110000];
lng dp[110][110000];
PLL qu[110000];

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	int n0,m0;
	cin>>n0>>m0>>p;
	vector<lng> d0(n0);
	d0[0]=0;
	for(int i=1;i<n0;++i){
		int a;
		scanf("%d",&a);
		d0[i]=d0[i-1]+a;
	}
	n=m0;
	forn(i,m0){
		int h,t;
		scanf("%d%d",&h,&t);
		--h;
		A[i]=t-d0[h];
	}
	
	sort(A,A+n);
	sum[0]=0;
	forn(i,n){
		sum[i+1]=sum[i]+A[i];
	}
	
	forn(i,n+1){
		dp[0][i]=LINF;
	}
	dp[0][0]=0;
	
	for(int c=1;c<=p;++c){
		dp[c][0]=0;
		int x=0,y=0;
		qu[y++]=mp(0,dp[c-1][0]+sum[0]);
		for(int i=1;i<=n;++i){
			lng add=i*A[i-1]-sum[i];
			lng v=qu[x].Y-qu[x].X*A[i-1];
			while(y>x+1){
				++x;
				lng t=qu[x].Y-qu[x].X*A[i-1];
				if(t>=v){
					--x;
					break;
				}
				v=t;
			}
			dp[c][i]=v+add;
			PLL q(i,dp[c-1][i]+sum[i]);
			while(y>x+1 && (q.X-qu[y-1].X)*(qu[y-1].Y-qu[y-2].Y)>=(q.Y-qu[y-1].Y)*(qu[y-1].X-qu[y-2].X))
				--y;
			qu[y++]=q;
			
			//cout<<c<<' '<<i<<": "<<dp[c][i]<<endl;
		}
	}
	
	cout<<dp[p][n];
	
	return 0;
}
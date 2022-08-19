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

int dp[2000000];

int main() {
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	
	lng A0,B0;
	int k;
	cin>>B0>>A0>>k;
	const int n=8*9*5*7*11*13;
	int aa=A0%n;
	int bb=B0%n;
	
	clr(dp,-1);
	dp[aa]=0;
	for(int i=aa+1;i<n;++i){
		dp[i]=dp[i-1]+1;
		for(int x=2;x<=k;++x){
			int t=i/x*x;
			if(dp[t]!=-1)
				dp[i]=min(dp[i],dp[t]+1);
		}
	}
	if(A0/n==B0/n){
		cout<<dp[bb];
	}else{
		lng res=dp[n-1]+1;
		clr(dp,-1);
		dp[0]=0;
		for(int i=1;i<n;++i){
			dp[i]=dp[i-1]+1;
			for(int x=2;x<=k;++x){
				int t=i/x*x;
				if(dp[t]!=-1)
					dp[i]=min(dp[i],dp[t]+1);
			}
		}
		res+=dp[bb];
		res+=(dp[n-1]+1)*(B0/n-A0/n-1);
		cout<<res;
	}
	
	return 0;
}
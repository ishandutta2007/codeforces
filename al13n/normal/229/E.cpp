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

int n,m;
vector<int> src[1100];
double dp[1100][1100];
double C[1100][1100];

int main() {
#ifdef __ASD__
    freopen("input.txt","rt",stdin);freopen("output.txt","wt",stdout);
#endif
	
	forn(i,1050){
		C[i][i]=C[i][0]=1;
		for(int j=1;j<i;++j){
			C[i][j]=min(1e20,C[i-1][j-1]+C[i-1][j]);
		}
	}
	
	vector<int> items;
	cin>>n>>m;
	forn(i,m){
		int k;
		cin>>k;
		forn(j,k){
			int a;
			cin>>a;
			src[i].pb(a);
			items.pb(a);
		}
	}
	sort(all(items));
	reverse(all(items));
	items.pb(0);
	int val=items[n],cnt=0;
	while(n-cnt-1>=0 && items[n-cnt-1]==val)
		++cnt;
	
	dp[0][0]=1;
	int s=0;
	forn(i,m){
		int c=0,cc=sz(src[i]);
		bool f=false;
		forv(j,src[i]){
			int t=src[i][j];
			if(t==val)
				f=true;
			if(t>val)
				++c;
		}
		if(f)
			++s;
		dp[i+1][0]=dp[i][0]/C[cc][c];
		if(dp[i+1][0]<1e-12)
			dp[i+1][0]=0;
		for(int k=1;k<=cnt;++k){
			if(f){
				dp[i+1][k]=1.*k/s*dp[i][k-1]/C[cc][c+1]+(1-1.*k/s)*dp[i][k]/C[cc][c];
			}else{
				dp[i+1][k]=dp[i][k]/C[cc][c];
			}
			if(dp[i+1][k]<1e-12)
				dp[i+1][k]=0;
		}
	}
	
	printf("%.15lf",dp[m][cnt]);
	
	return 0;
}
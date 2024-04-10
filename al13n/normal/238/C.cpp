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

int n;
vector<PII> gr[3100];
int dp[3100][3];

void dfs(int v,int pr){
	int sum0=0;
	int mn1=inf;
	int mn2=inf;
	forv(i,gr[v]){
		int p=gr[v][i].X;
		if(p==pr)
			continue;
		int d=gr[v][i].Y;
		dfs(p,v);
		int c0=dp[p][0]+(d==1?0:1);
		sum0+=c0;
		mn1=min(mn1,dp[p][1]+(d==1?1:0)-c0);
		mn2=min(mn2,min(dp[p][1],dp[p][2]+(d==1?0:1))-c0);
	}
	dp[v][0]=sum0;
	dp[v][1]=min(sum0,sum0+mn1);
	dp[v][2]=min(sum0,sum0+mn2);
}

int main() {
#ifdef __ASD__
    freopen("input.txt","rt",stdin);freopen("output.txt","wt",stdout);
#endif

	cin>>n;
	forn(i,n-1){
		int a,b;
		cin>>a>>b;
		--a;--b;
		gr[a].pb(mp(b,1));
		gr[b].pb(mp(a,-1));
	}
	
	int res=inf;
	forn(i,n){
		dfs(i,-1);
		res=min(res,dp[i][2]);
	}
	
	cout<<res;
	
	return 0;
}
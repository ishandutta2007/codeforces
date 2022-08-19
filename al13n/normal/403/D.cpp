#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
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
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<string, string> PSS;
typedef pair<PII, int> PIII;
typedef pair<lng, lng> PLL;
typedef pair<lng, int> PLI;
typedef pair<int, lng> PIL;
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
const ld EPS = 1e-12;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
lng powmod(lng a,lng p,lng m){lng r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
#define TASKA "sequence"

const int K=50;
const int N=1010;

const int mod=INF+7;
int dp[2][N+1][N+1];
int ans[N][N];

void dodp(){
	int cur=0;
	int prev=1;
	forn(n,N+1){
		forn(p,N+1){
			dp[cur][n][p]=1;
		}
	}
	for(int k=1;k<K;++k){
		swap(cur,prev);
		forn(p,N+1){
			dp[cur][0][p]=0;
		}
		for(int n=0;n<N;++n){
			dp[cur][n+1][0]=0;
			int sum=0;
			for(int p=0;p<N;++p){
				int x=n-p>=0 ? dp[prev][n-p][p] : 0;
				(sum+=x)%=mod;
				dp[cur][n+1][p+1]=(dp[cur][n][p+1]+sum)%mod;
			}
		}
		
		/*
		cout<<"k="<<k<<endl;
		for(int n=0;n<=N;++n){
			for(int p=0;p<=N;++p){
				cout<<dp[cur][n][p]<<' ';
			}
			cout<<'\n';
		}
		cout<<endl;//*/
		
		lng f=1;
		for(int i=2;i<=k;++i){
			f=f*i%mod;
		}
		
		forn(n,N){
			ans[k][n]=f*dp[cur][n+1][N]%mod;
		}
	}
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASKA".in", "r", stdin); freopen(TASKA".out", "w", stdout);
#endif
	
	dodp();
	
	int tc;
	cin>>tc;
	forn(qqq,tc){
		int n,k;
		scanf("%d%d",&n,&k);
		printf("%d\n",ans[k][n-1]);
	}
	
	return 0;
}
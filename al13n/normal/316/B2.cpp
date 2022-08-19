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
#define pow10 asdpow10
const double EPS = 1e-6;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
uint gcd(uint a,uint b){return a?gcd(b%a,a):b;}

int src[1100];
int head[1100];
int dist[1100];
int len[1100];
int n;

bool dp[1100];

void doit(int a){
	if(len[a])
		return;
	if(src[a]==-1){
		head[a]=a;
		len[a]=1;
		dist[a]=1;
		return;
	}
	doit(src[a]);
	head[a]=head[src[a]];
	dist[a]=1+dist[src[a]];
	len[head[a]]=max(len[head[a]],dist[a]);
}

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	int x;
	cin>>n>>x;
	--x;
	forn(i,n){
		cin>>src[i];
		--src[i];
	}
	forn(i,n){
		doit(i);
	}
	int xpos=dist[x];
	vector<int> segs;
	forn(i,n){
		if(src[i]==-1 && i!=head[x]){
			segs.pb(len[i]);
		}
	}
	
	dp[0]=true;
	forv(i,segs){
		int s=segs[i];
		for(int j=n-s;j>=0;--j){
			dp[j+s]|=dp[j];
		}
	}
	
	forn(i,n){
		if(dp[i])
			cout<<i+xpos<<'\n';
	}
	
	return 0;
}
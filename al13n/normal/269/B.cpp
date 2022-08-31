#pragma comment(linker, "/STACK:256000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
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
typedef double ld;
typedef pair<int, int> PII;
typedef pair<lng, lng> PLL;
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
const double EPS = 1e-9;
const int INF = 1000*1000*1000;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;

int src[5100];
int dp[5100];
int n,m;

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	
	cin>>n>>m;
	forn(i,n){
		double asd;
		cin>>src[i]>>asd;
	}
	int res=0;
	forn(i,n){
		dp[i]=1;
		forn(j,i){
			if(src[i]>=src[j])
				dp[i]=max(dp[i],dp[j]+1);
		}
		res=max(res,dp[i]);
	}
	cout<<n-res;
	
	return 0;
}
#pragma comment(linker, "/STACK:256000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
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
typedef pair<int, PII> PIII;
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

const double EPS = 1e-10;
const int INF = 1000*1000*1000;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;

int n,m;
const lng mod=INF+7;
lng dp[160][160][160][2][2];

void add(lng &a,lng b){
	if(&a==&dp[1][2][2][1][0]){
		//cerr<<"hi"<<endl;
	}
	a=(a+b)%mod;
}

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	//ios_base::sync_with_stdio(false);

	cin>>n>>m;
	lng res=0;
	forn(y2,n){
		forn(y1,y2+1){
			dp[0][y1][y2][0][0]=1;
			add(res,m);
		}
	}
	forn(x,m-1){
		forn(y2,n){
			forn(y1,y2+1){
				forn(f1,2){
					forn(f2,2){
						add(dp[x+1][y1][y2][f1][f2],dp[x][y1][y2][f1][f2]);
					}
					if(y1<y2){
						add(dp[x+1][y1+1][y2][1][f1],dp[x][y1][y2][0][f1]);
						add(dp[x+1][y1][y2-1][f1][1],dp[x][y1][y2][f1][0]);
					}
				}
				if(y1+1<y2){
					add(dp[x+1][y1+1][y2-1][1][1],dp[x][y1][y2][0][0]);
				}
			}
		}
		++x;
		forn(y2,n){
			for(int y1=0;y1<y2;++y1){
				add(dp[x][y1+1][y2][1][0],dp[x][y1][y2][1][0]);
				add(dp[x][y1+1][y2][1][1],dp[x][y1][y2][1][1]);
			}
		}
		forn(y1,n){
			for(int y2=y1;y2+1<n;++y2){
				add(dp[x][y1][y2+1][0][0],dp[x][y1][y2][0][0]);
				add(dp[x][y1][y2+1][1][0],dp[x][y1][y2][1][0]);
			}
		}
		forn(y1,n){
			for(int y2=n-1;y2>y1;--y2){
				add(dp[x][y1][y2-1][0][1],dp[x][y1][y2][0][1]);
				add(dp[x][y1][y2-1][1][1],dp[x][y1][y2][1][1]);
			}
		}
		forn(y2,n){
			for(int y1=y2;y1>0;--y1){
				add(dp[x][y1-1][y2][0][0],dp[x][y1][y2][0][0]);
				add(dp[x][y1-1][y2][0][1],dp[x][y1][y2][0][1]);
			}
		}
		forn(y2,n){
			forn(y1,y2+1){
				forn(f1,2){
					forn(f2,2){
						//cout<<x<<' '<<y1<<' '<<y2<<' '<<f1<<' '<<f2<<": "<<dp[x][y1][y2][f1][f2]<<endl;
						add(res,dp[x][y1][y2][f1][f2]*(m-x));
					}
				}
			}
		}
		--x;
	}
	cout<<res;
	
	return 0;
}
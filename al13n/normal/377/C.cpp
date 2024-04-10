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
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<short, short> PSS;
typedef pair<PII, int> PIII;
typedef pair<lng, lng> PLL;
typedef pair<lng, int> PLI;
typedef pair<ld, ld> PDD;
#define left asdleft
#define right asdright
#define link asdlink
#define unlink asdunlink
//#define next asdnext
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
const ld EPS = 1e-14;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795L;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}

int n;
int S[110];
int m;
pair<char,int> A[25];
int dp[2][1<<20];

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	
	cin>>n;
	forn(i,n){
		cin>>S[i];
	}
	cin>>m;
	forn(i,m){
		cin>>A[i].X>>A[i].Y;
	}
	sort(S,S+n);
	reverse(S,S+n);
	n=min(m,n);
	
	int cur=0,prev=1;
	for(int q=m-1;q>=0;--q){
		swap(cur,prev);
		forn(msk,1<<n){
			if(A[q].X=='p'){
				forn(i,n){
					if(msk&(1<<i)){
						dp[cur][msk]=S[i]+(A[q+1].Y==A[q].Y?1:-1)*dp[prev][msk^(1<<i)];
						break;
					}
				}
			}else{
				int r=-INF;
				forn(i,n){
					if(!(msk&(1<<i)))
						continue;
					r=max(r,(A[q+1].Y==A[q].Y?1:-1)*dp[prev][msk^(1<<i)]);
				}
				dp[cur][msk]=r;
			}
		}
	}
	cout<<(A[0].Y==1?1:-1)*dp[cur][(1<<n)-1];
	
	return 0;
}
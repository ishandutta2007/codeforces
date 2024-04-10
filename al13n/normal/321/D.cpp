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
#define hash asdhash
#define move asdmove
const double EPS = 1e-6;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
uint gcd(uint a,uint b){return a?gcd(b%a,a):b;}

int A[35][35];
int B[35][35];

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin>>n;
	forn(i,n){
		forn(j,n){
			cin>>A[i][j];
		}
	}
	int m=n/2;
	int res=-INF;
	forn(msk,1<<(m+1)){
		memcpy(B,A,sizeof(A));
		forn(i,m+1){
			if(!(msk&(1<<i)))
				continue;
			for(int a=i;a<=i+m;++a){
				for(int b=m;b<=m+m;++b){
					B[a][b]*=-1;
				}
			}
		}
		int r=0;
		forn(i,n){
			r+=B[i][m];
		}
		forn(j,m){
			int s1=B[m][j]+B[m][j+m+1];
			int s2=-s1;
			forn(i,m){
				int v1=B[i][j];
				int v2=B[i][j+m+1];
				int v3=B[i+m+1][j];
				int v4=B[i+m+1][j+m+1];
				s1+=abs(v1+v2+v3+v4);
				s2+=abs(v1+v2-v3-v4);
			}
			r+=max(s1,s2);
		}
		res=max(res,r);
	}
	cout<<res;
	
	return 0;
}
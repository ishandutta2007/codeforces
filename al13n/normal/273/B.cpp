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

int A[110000];
int B[110000];
int n;
lng M;
map<int,PII> cnt;
lng fact[210000];
lng pw2[210000];
int fp[210000];

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);

	int n;
	cin>>n;
	forn(i,n){
		cin>>A[i];
	}
	forn(i,n){
		cin>>B[i];
	}
	forn(i,n){
		if(A[i]==B[i])
			++cnt[A[i]].Y;
		else{
			++cnt[A[i]].X;
			++cnt[B[i]].X;
		}
	}
	cin>>M;
	fact[0]=1;
	pw2[0]=1;
	fp[0]=0;
	forn(i,n+n+10){
		pw2[i+1]=pw2[i]*2%M;
		int t=i+1;
		fp[i+1]=fp[i];
		while(t%2==0){
			t/=2;
			++fp[i+1];
		}
		fact[i+1]=fact[i]*t%M;
	}
	lng res=1;
	for(map<int,PII>::iterator it = cnt.begin(); it!=cnt.end(); ++it){
		int a=it->Y.X;
		int b=it->Y.Y;
		int t=fp[a+b+b]-b;
		if(t<0)
			exit(33);
		res=res*fact[a+b+b]%M*pw2[t]%M;
	}
	cout<<res;
	
	return 0;
}
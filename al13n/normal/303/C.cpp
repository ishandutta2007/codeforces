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

const int lim=1001000;
int A[5100];
int as[lim][12];
int n,k;
int wasa[lim];
int wasr[lim];
int cur;

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	cin>>n>>k;
	forn(i,n){
		cin>>A[i];
		//A[i]=(1LL*rand()*(RAND_MAX+1LL)+rand())%(1000001-5010);
	}
	sort(A,A+n);
	int t=0;
	forn(i,n){
		A[i]+=t;
		if(i && A[i]==A[i-1]){
			++t;
			++A[i];
		}
	}
	
	forn(i,n){
		forn(j,i){
			int t=A[i]-A[j];
			if(as[t][0]<10){
				as[t][++as[t][0]]=A[i];
				as[t][++as[t][0]]=A[j];
			}
		}
	}
	
	for(int m=1;m<lim;++m){
		++cur;
		int c=0;
		int u=0;
		for(int d=m;d<lim;d+=m){
			forn(ii,as[d][0]){
				int a=as[d][ii+1];
				if(wasa[a]!=cur){
					wasa[a]=cur;
					++c;
				}
				int r=a%m;
				if(wasr[r]!=cur){
					wasr[r]=cur;
					++u;
				}
				if(c-u>k)
					break;
			}
			if(c-u>k)
				break;
		}
		if(c-u<=k){
			cout<<m;
			return 0;
		}
	}
	return 1;

	return 0;
}
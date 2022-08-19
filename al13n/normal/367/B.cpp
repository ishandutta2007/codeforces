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
const ld EPS = 1e-10;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}



int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	int n,m,p;
	cin>>n>>m>>p;
	vector<int> a(n);
	forn(i,n){
		scanf("%d",&a[i]);
	}
	map<int,int> cnt;
	forn(i,m){
		int b;
		scanf("%d",&b);
		++cnt[b];
	}
	int nz=sz(cnt);
	vector<int> ans;
	for(int i0=0;i0<p && i0+p*(m-1)<n;++i0){
		for(int i=i0;i-p*(m-1)<n;i+=p){
			int ii=i-p*(m-1);
			if(i<n){
				if(!cnt[a[i]])
					++nz;
				--cnt[a[i]];
				if(!cnt[a[i]])
					--nz;
				if(ii>=0 && !nz)
					ans.pb(ii);
			}
			if(ii>=0){
				if(!cnt[a[ii]])
					++nz;
				++cnt[a[ii]];
				if(!cnt[a[ii]])
					--nz;
			}
		}
	}
	sort(all(ans));
	cout<<sz(ans)<<endl;
	forv(i,ans){
		printf("%d ",ans[i]+1);
	}
	
	return 0;
}
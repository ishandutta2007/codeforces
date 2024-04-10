#pragma comment(linker, "/STACK:512000000")
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
const double EPS = 1e-6;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;

int need;
char S[100];
char S2[100];
int bits[1<<10];
vector<string> res;

bool ok(char *a,int l){
	if(l<1)
		return false;
	if(l==1)
		return true;
	if(a[0]=='0')
		return false;
	
	if(l<3)
		return true;
	if(l>3)
		return false;
	
	if(a[0]<'2')
		return true;
	if(a[0]>'2')
		return false;
	
	if(a[1]<'5')
		return true;
	if(a[1]>'5')
		return false;
	
	return a[2]<'6';
}

void doit2(int a,int c,int p,int n){
	if(a==n){
		if(c<3)
			return;
		if(!ok(S+p,a-p))
			return;
		S2[a+c]='\0';
		res.pb(S2);
		return;
	}
	if(c<3 && ok(S+p,a-p)){
		S2[a+c]='.';
		doit2(a,c+1,a,n);
	}
	if(a-p<3){
		S2[a+c]=S[a];
		doit2(a+1,c,p,n);
	}
}

void doit(int n,int m){
	if(bits[need]-bits[m]>6-n)
		return;
	if(n>=2 && m==need){
		memcpy(S+n,S,n);
		reverse(S+n,S+n+n);
		doit2(0,0,0,n+n);
		memcpy(S+n,S,n-1);
		reverse(S+n,S+n+n-1);
		doit2(0,0,0,n+n-1);
	}
	if(n<6){
		forn(d,10){
			if(!(need&(1<<d)))
				continue;
			S[n]='0'+d;
			doit(n+1,m|(1<<d));
		}
	}
}

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	
	forn(i,1<<10){
		int t=0;
		while(t){
			bits[i]+=t&1;
			t>>=1;
		}
	}
	
	need=0;
	int l;
	cin>>l;
	forn(i,l){
		int a;
		cin>>a;
		need|=1<<a;
	}
	
	doit(0,0);
	
	cout<<sz(res)<<'\n';
	forv(i,res){
		cout<<res[i]<<'\n';
	}

	return 0;
}
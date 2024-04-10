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

lng P[60];
lng pw[60][60];
int K[60];
int n;
lng res;

void doit(int a,lng x,lng y,lng z){
	if(a==n){
		lng t=x;
		if(y>t)
			t=y;
		if(z>t)
			t=z;
		if(x+y+z-t-t>0){
			++res;
			//cout<<x<<' '<<y<<' '<<z<<endl;
		}else{
			//cout<<"- "<<x<<' '<<y<<' '<<z<<endl;
		}
		return;
	}
	lng p=P[a];
	int k=K[a];
	for(int ix=0;ix<=k;++ix){
		for(int iy=0;ix+iy<=k;++iy){
			int iz=k-ix-iy;
			lng xx=x*pw[a][ix];
			lng yy=y*pw[a][iy];
			lng zz=z*pw[a][iz];
			if(p==2 && ((xx+yy+zz)&1))
				continue;
			doit(a+1,xx,yy,zz);
		}
	}
}

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	lng v;
	cin>>v;
	
	if(v%3){
		cout<<0;
		return 0;
	}
	v/=3;
	
	for(lng i=2;i*i<=v;++i){
		if(v%i)
			continue;
		P[n]=i;
		K[n]=0;
		pw[n][0]=1;
		while(v%i==0){
			v/=i;
			++K[n];
			pw[n][K[n]]=pw[n][K[n]-1]*i;
		}
		++n;
	}
	if(v>1){
		P[n]=v;
		K[n]=1;
		pw[n][0]=1;
		pw[n][1]=v;
		++n;
	}
	
	doit(0,1,1,1);
	
	cout<<res;
	
	return 0;
}
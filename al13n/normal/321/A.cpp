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
const double EPS = 1e-6;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
uint gcd(uint a,uint b){return a?gcd(b%a,a):b;}

void yep(){
	cout<<"Yes";
	exit(0);
}

void nope(){
	cout<<"No";
	exit(0);
}

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	lng x,y;
	cin>>x>>y;
	string s;
	cin>>s;
	lng sx=0,sy=0;
	int dx[256]={0},dy[256]={0};
	dy['U']=1;
	dy['D']=-1;
	dx['L']=-1;
	dx['R']=1;
	forv(i,s){
		sx+=dx[s[i]];
		sy+=dy[s[i]];
	}
	lng px=0,py=0;
	forv(i,s){
		lng tx=x-px;
		lng ty=y-py;
		px+=dx[s[i]];
		py+=dy[s[i]];
		if(!tx && !ty)
			yep();
		if(!sx && !sy)
			continue;
		if(tx && !sx)
			continue;
		if(ty && !sy)
			continue;
		if(sx && (tx%abs(sx) || tx/sx<0))
			continue;
		if(sy && (ty%abs(sy) || ty/sy<0))
			continue;
		if(sx && sy && tx/sx != ty/sy)
			continue;
		yep();
	}
	
	nope();
	
	return 0;
}
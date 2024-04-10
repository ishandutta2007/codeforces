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
typedef pair<int, lng> PIL;
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
vector<PII> pos;
const lng mod=INF+7;

lng powmod(lng a,lng p){
	lng r=1;
	while(p){
		if(p&1)
			r=r*a%mod;
		p>>=1;
		a=a*a%mod;
	}
	return r;
}

lng C(int n,int k){
	lng r=1;
	for(int i=n-k+1;i<=n;++i){
		r=r*i%mod*powmod(n-i+1,mod-2)%mod;
	}
	return r;
}

lng doit(int a,int b,int t){
	lng res=1;
	for(int i=1;i<sz(pos);++i){
		int p=pos[i].Y;
		int d=pos[i].X;
		int aa,bb;
		if(p<a){
			aa=p+1;
			bb=b+((d-t)-(a-p));
			if(bb<b || bb>n)
				return 0;
		}else if(p>=b){
			bb=p;
			aa=a-((d-t)-(p+1-b));
			if(aa>a || aa<0)
				return 0;
		}else
			return 0;
		res=res*C(a-aa+bb-b,a-aa)%mod;
		if(p<a)
			--aa;
		else
			++bb;
		a=aa;
		b=bb;
		t=d;
	}
	if(a<0||b>n)
		return 0;
	res=res*C(a+n-b,a)%mod;
	return res;
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	cin>>n;
	forn(i,n){
		int a;
		scanf("%d",&a);
		if(a)
			pos.pb(mp(a,i));
	}
	sort(all(pos));
	if(!sz(pos)){
		cout<<powmod(2,n-1);
		return 0;
	}
	
	lng res;
	if(pos[0].X==1){
		res=doit(pos[0].Y,pos[0].Y+1,1);
	}else{
		res=(doit(pos[0].Y,pos[0].Y+pos[0].X,pos[0].X)*powmod(2,pos[0].X-2)+
			 doit(pos[0].Y-pos[0].X+1,pos[0].Y+1,pos[0].X)*powmod(2,pos[0].X-2))%mod;
	}
	cout<<res;
	
	return 0;
}
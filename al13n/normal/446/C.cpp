#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
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
typedef long long lng;
typedef unsigned long long ulng;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef double ld;
typedef pair<int, int> PII;
typedef pair<short, short> PSS;
typedef pair<PII, int> PIII;
typedef pair<lng, lng> PLL;
typedef pair<ulng, ulng> PUU;
typedef pair<lng, int> PLI;
typedef pair<int, lng> PIL;
typedef pair<ld, ld> PDD;
template<class T> inline T sqr(T x) { return x * x; }
template<class T> inline string tostr(const T & x) { stringstream ss; ss << x; return ss.str(); }
inline lng parse(const string & s) { stringstream ss(s); lng x; ss >> x; return x; }
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
const ld EPS = 1e-9;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
lng powmod(lng a,lng p,lng m){lng r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
#define fail(msg) { cerr<<msg<<endl; cout<<msg<<endl; exit((__LINE__-1) % 200 + 1);}

const lng mod=INF+9;
vector<lng> F;

lng A[310000];

PLL add[1300000];
lng sum[1300000];

PLL shift(PLL v,int a){
	if(!a)
		return v;
	return mp((v.X*F[a-1]+v.Y*F[a])%mod,(v.X*F[a]+v.Y*F[a+1])%mod);
}

lng fibsum(PLL v,int a){
	return (v.X*F[a]+v.Y*(F[a+1]+mod-1))%mod;
}

void init(int a,int b,int k){
	if(b==a+1){
		add[k]=mp(A[a],0);
		sum[k]=A[a];
		return;
	}
	int c=(a+b)/2;
	init(a,c,k*2+1);
	init(c,b,k*2+2);
	sum[k]=(sum[k*2+1]+sum[k*2+2] + fibsum(add[k],b-a))%mod;
}

void addval(int l,int r,PLL v,int a,int b,int k){
	if(l>=b || r<=a)
		return;
	if(l<=a && r>=b){
		v=shift(v,a-l);
		(add[k].X+=v.X)%=mod;
		(add[k].Y+=v.Y)%=mod;
		(sum[k]+=fibsum(v,b-a))%=mod;
		return;
	}
	int c=(a+b)/2;
	addval(l,r,v,a,c,k*2+1);
	addval(l,r,v,c,b,k*2+2);
	sum[k]=(sum[k*2+1]+sum[k*2+2] + fibsum(add[k],b-a))%mod;
}

lng getsum(int l,int r,int a,int b,int k){
	if(l>=b || r<=a)
		return 0;
	if(l<=a && r>=b)
		return sum[k];
	int c=(a+b)/2;
	return (getsum(l,r,a,c,k*2+1) + getsum(l,r,c,b,k*2+2) + fibsum(shift(add[k],max(a,l)-a),min(b,r)-max(a,l)))%mod;
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);cin.tie(0);

	int n,m;
	cin>>n>>m;
	F.pb(0);
	F.pb(1);
	forn(i,n+n/10+10){
		F.pb((F.back()+F[sz(F)-2])%mod);
	}
	
	forn(i,n){
		cin>>A[i];
	}
	
	init(0,n,0);
	
	forn(qqq,m){
		int t,a,b;
		cin>>t>>a>>b;
		--a;
		if(t==1){
			addval(a,b,mp(1,1),0,n,0);
		}else{
			cout<<getsum(a,b,0,n,0)<<'\n';
		}
	}
	
	return 0;
}
#pragma comment(linker, "/STACK:512000000")
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
typedef long double ld;
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
//#define unlink asdunlink
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
const ld EPS = 1e-12;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
lng powmod(lng a,lng p,lng m){lng r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
#define TASKA "iota"

lng myabs(lng a){
	return a<0?-a:a;
}

struct vec{
	lng x,y;
	
	vec(){}
	vec(lng x,lng y):x(x),y(y){}
	
	void read(){
		cin>>x>>y;
	}
	
	vec pp()const{
		return vec(-y,x);
	}
	
	lng dot(const vec &b)const{
		return x*b.x+y*b.y;
	}
	
	vec operator+(const vec &b)const{
		return vec(x+b.x,y+b.y);
	}
	vec operator-(const vec &b)const{
		return vec(x-b.x,y-b.y);
	}
	
	vec norm()const{
		lng g=gcd(myabs(x),myabs(y));
		return vec(x/g,y/g);
	}
	
	ld ang()const{
		return atan2l(ld(y),ld(x));
	}
};

vector<vec> A;
vector<vector<char> > V;

bool between(vec v0,vec a,vec b,vec c){
	ld a1=(a-v0).norm().ang();
	ld a2=(b-v0).norm().ang();
	ld a3=(c-v0).norm().ang();
	while(a2<=a1+EPS)
		a2+=2*PI;
	while(a3<=a2+EPS)
		a3+=2*PI;
	ld a4=a1;
	while(a4<=a3+EPS)
		a4+=2*PI;
	if(fabs(a4-a1-4*PI)<.1)
		return false;
	if(fabs(a4-a1-2*PI)<.1)
		return true;
	exit(123);
}

lng sign(lng a){
	if(!a)
		return 0;
	return a<0?-1:1;
}

bool inters(vec a,vec b,vec c,vec d){
	if((b-a).pp().dot(d-c)==0)
		return false;
	if(sign((b-a).pp().dot(d-a))*sign((b-a).pp().dot(c-a))>0)
		return false;
	swap(a,c);
	swap(b,d);
	if(sign((b-a).pp().dot(d-a))*sign((b-a).pp().dot(c-a))>0)
		return false;
	return true;
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASKA".in", "r", stdin); freopen(TASKA".out", "w", stdout);
#endif

	int n;
	cin>>n;
	A.resize(n);
	V.resize(n,vector<char>(n));
	forn(i,n){
		A[i].read();
	}
	
	lng s=0;
	forv(i,A){
		s+=A[(i+1)%n].pp().dot(A[i]);
	}
	if(s<0)
		reverse(all(A));
	
	forn(b,n){
		forn(a,b){
			if(b==a+1){
				V[a][b]=1;
				continue;
			}
			
			if(!between(A[a],A[(a+n-1)%n],A[b],A[(a+1)%n]) ||
			   !between(A[b],A[(b+n-1)%n],A[a],A[(b+1)%n]))
			   continue;

			V[a][b]=1;
			forn(i,n){
				if((i+1)%n==a || i==a || (i+1)%n==b || i==b)
					continue;
				if(inters(A[a],A[b],A[i],A[(i+1)%n])){
					V[a][b]=0;
					break;
				}
			}
		}
	}
	
	const lng mod=INF+7;
	vector<vector<lng> > dp(n,vector<lng>(n,0));
	for(int a=n-1;a>=0;--a){
		for(int b=a+1;b<n;++b){
			if(b==a+1){
				dp[a][b]=1;
				continue;
			}
			
			for(int k=a+1;k<b;++k){
				if(V[a][k] && V[k][b])
					(dp[a][b]+=dp[a][k]*dp[k][b])%=mod;
			}
		}
	}
	
	cout<<dp[0][n-1];
	
	return 0;
}
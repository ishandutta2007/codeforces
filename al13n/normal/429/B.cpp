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
#include <unistd.h>
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

typedef vector<vector<int> > mat;
mat A;
mat D[4];

void turn(mat &a){
	mat t=a;
	int m=sz(a);
	int n=sz(a[0]);
	a=mat(n,vector<int>(m));
	forn(i,n){
		forn(j,m){
			a[i][j]=t[j][n-i-1];
		}
	}
}

void turn(){
	turn(A);
	forn(q,4){
		turn(D[q]);
	}
}

void dodp(mat &D){
	forv(i,A){
		forv(j,A[0]){
			D[i][j]=0;
			if(i)
				D[i][j]=D[i-1][j];
			if(j)
				D[i][j]=max(D[i][j],D[i][j-1]);
			D[i][j]+=A[i][j];
		}
	}
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASKA".in", "r", stdin); freopen(TASKA".out", "w", stdout);
#endif
	
	int n,m;
	cin>>n>>m;
	A = mat(n,vector<int>(m));
	forn(q,4){
		D[q]=A;
	}
	forn(i,n){
		forn(j,m){
			scanf("%d",&A[i][j]);
		}
	}
	
	forn(q,4){
		dodp(D[q]);
		turn();
	}
	
	int ans=0;
	for(int i=1;i+1<n;++i){
		for(int j=1;j+1<m;++j){
			ans=max(ans,D[0][i][j-1]+D[1][i-1][j]+D[2][i][j+1]+D[3][i+1][j]);
			ans=max(ans,D[3][i][j-1]+D[0][i-1][j]+D[1][i][j+1]+D[2][i+1][j]);
		}
	}
	
	cout<<ans;
	
	return 0;
}
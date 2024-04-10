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

int P;
int Q;
int g;
int A;
vector<int> V;
vector<int> D;

int powmod(lng a,lng p){
	lng r=1;
	while(p){
		if(p&1){
			r=r*a%P;
		}
		p>>=1;
		a=a*a%P;
	}
	return (int)r;
}

bool isgen(){
	for(int d=1;d*d<=P-1;++d){
		if((P-1)%d)
			continue;
		if(powmod(Q,d)==1 || (d!=1 && powmod(Q,(P-1)/d)==1))
			return false;
	}
	return true;
}

const int B=1000000;
static PII ar[B];
lng S;

void genb(){
	lng v=1;
	forn(i,B){
		ar[i]=mp((int)v,i);
		v=v*Q%P;
	}
	sort(ar,ar+B);
	S=powmod(Q,B);
}

int plog(lng a){
	lng s=S;
	lng v=a;
	lng p=0;
	while(p<P*2){
		int i=lower_bound(ar,ar+B,mp((int)v,0))-ar;
		if(i<B && ar[i].X == v)
			return (int)(((ar[i].Y-p)%(P-1)+(P-1))%(P-1));
		v=v*s%P;
		p+=B;
	}
	exit(122);
}

void gentest(){
	freopen("input.txt", "w", stdout);
	int n=10000;
	int m=100000;
	int P=999999937;
	cout << n << ' ' << m << ' ' << P << endl;
	forn(i,n){
		cout<<rand()%(P-1)+1<<' ';
	}
	cout<<endl;
	forn(i,m){
		cout<<rand()%INF+1<<' ';
	}
}

int main(){
	//gentest();return 0;
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	cerr<<'0'<<endl;
	int n,m;
	cin>>n>>m>>P;
	Q=2;
	while(!isgen())
		++Q;
	cerr<<'1'<<endl;
	genb();
	cerr<<"1.5"<<endl;
	forn(i,n){
		int a;
		cin>>a;
		V.pb(gcd(plog(a),P-1));
	}
	cerr<<'2'<<endl;
	g=P-1;
	forn(i,m){
		int a;
		cin>>a;
		g=gcd(g,a);
	}
	cerr<<'3'<<endl;
	A=(P-1)/g;
	forn(i,n){
		V[i]=gcd(V[i],A);
	}
	
	cerr<<'4'<<endl;
	sort(all(V));
	V.erase(unique(all(V)),V.end());
	
	for(int d=1;d*d<=A;++d){
		if(A%d)
			continue;
		D.pb(d);
		if(d*d!=A)
			D.pb(A/d);
	}
	sort(all(D));
	
	cerr<<'5'<<endl;
	vector<int> dp=D;
	for(int i=sz(D)-1;i>=0;--i){
		dp[i]=A/D[i];
		for(int j=i+1;j<sz(D);++j){
			if(D[j]%D[i])
				continue;
			dp[i]-=dp[j];
		}
	}
	
	cerr<<'6'<<endl;
	int res=0;
	vector<char> take(sz(D),0);
	forv(i,V){
		forv(j,D){
			if(D[j]%V[i] || take[j])
				continue;
			take[j]=true;
			res+=dp[j];
		}
	}
	
	cerr<<'7'<<endl;
	cout<<res;
	
	return 0;
}
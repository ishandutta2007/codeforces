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

int compr(const char *s,int n){
	int r=0;
	forn(i,n){
		r=r*27+1+(s[i]-'a');
	}
	return r;
}

const double R=20;
map<int,vector<int> > A;
map<PII,int> mem;

int dobig(const vector<int> &a, const vector<int> &b){
	int j=0;
	int r=INF;
	forv(i,a){
		while(j<sz(b) && b[j]<a[i])
			++j;
		if(j==sz(b))
			break;
		r=min(r,b[j]-a[i]);
	}
	return r;
}

int doleft(const vector<int> &a, const vector<int> &b){
	int r=INF;
	forv(i,a){
		int k=lower_bound(all(b),a[i])-b.begin();
		if(k==sz(b))
			break;
		r=min(r,b[k]-a[i]);
	}
	return r;
}

int doright(const vector<int> &a, const vector<int> &b){
	int r=INF;
	for(int i=sz(b)-1;i>=0;--i){
		int k=upper_bound(all(a),b[i])-a.begin();
		if(!k)
			break;
		r=min(r,b[i]-a[k-1]);
	}
	return r;
}

int doit(int ai,int bi){
	if(mem.count(mp(ai,bi)))
		return mem[mp(ai,bi)];

	const vector<int> &a=A[ai];
	const vector<int> &b=A[bi];

	int r;
	if(sz(b)>sz(a)*R)
		r=doleft(a,b);
	else if(sz(a)>sz(b)*R)
		r=doright(a,b);
	else
		r=dobig(a,b);

	return mem[mp(ai,bi)]=r;
}

int solve(const string &as,const string &bs){
	int a=compr(as.data(),sz(as));
	int b=compr(bs.data(),sz(bs));
	if(!sz(A[a]) || !sz(A[b]))
		return -1;
	return min(max(sz(as),doit(a,b)+sz(bs)),max(sz(bs),doit(b,a)+sz(as)));
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	//ios_base::sync_with_stdio(0);cin.tie(0);

	string S;
	cin>>S;
	forv(i,S){
		for(int k=1;k<=4 && i+k<=sz(S);++k){
			A[compr(S.data()+i,k)].pb(i);
		}
	}
	
	int tc;
	cin>>tc;
	forn(qqq,tc){
		string as,bs;
		cin>>as>>bs;
		cout<<solve(as,bs)<<'\n';
	}
	
	return 0;
}
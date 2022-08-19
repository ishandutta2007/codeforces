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

struct thing{
	lng r=0;
	priority_queue<lng> A,B;
	
	void add(lng x){
		if(!A.empty() && A.top()>x){
			r-=A.top();
			r+=x;
			B.push(-A.top());
			A.pop();
			A.push(x);
		}else{
			B.push(-x);
		}
	}
	
	lng get(int kk){
		while(sz(A)<kk && !B.empty()){
			r+=-B.top();
			A.push(-B.top());
			B.pop();
		}
		return sz(A)<kk?LINF:r;
	}
};

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	int c0=0;
	map<int,vector<lng> > M;
	forn(i,n){
		int a,b;
		cin>>a>>b;
		if(!a){
			++c0;
			continue;
		}
		M[a].pb(b);
	}
	vector<vector<lng> > V;
	lng S=0;
	int C=c0;
	for(auto &it : M){
		vector<lng> &v=it.Y;
		sort(all(v));
		reverse(all(v));
		if(sz(V)<sz(v))
			V.resize(sz(v));
		forv(i,v){
			V[i].pb(v[i]);
			S+=v[i];
			++C;
		}
	}
	
	lng ans=S;
	thing T;
	forv(q,V){
		forv(i,V[q]){
			lng x=V[q][i];
			S-=x;
			--C;
			T.add(x);
		}
		ans=min(ans,S+T.get(max(0,q+2-C)));
	}
	
	cout<<ans;

	return 0;
}
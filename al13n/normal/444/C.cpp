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

lng tree[410000];
lng add[410000];

void addval(int l,int r,lng v,int a,int b,int k){
	if(r<=a || l>=b)
		return;
	if(l<=a && r>=b){
		add[k]+=v;
		tree[k]+=v*(b-a);
		return;
	}
	int c=(a+b)/2;
	addval(l,r,v,a,c,k*2+1);
	addval(l,r,v,c,b,k*2+2);
	tree[k]=add[k]*(b-a)+tree[k*2+1]+tree[k*2+2];
}

lng getsum(int l,int r,int a,int b,int k){
	if(r<=a || l>=b)
		return 0;
	if(l<=a && r>=b)
		return tree[k];
	int c=(a+b)/2;
	return getsum(l,r,a,c,k*2+1)+getsum(l,r,c,b,k*2+2)+add[k]*(min(r,b)-max(l,a));
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);cin.tie(0);

	int n,m;
	cin>>n>>m;
	set<PII> S;
	forn(i,n){
		S.insert(mp(i,i+1));
	}
	S.insert(mp(n,-1));
	forn(qqq,m){
		int type,a,b;
		cin>>type>>a>>b;
		--a;
		if(type==1){
			int x;
			cin>>x;
			auto it=S.upper_bound(mp(a,INF));
			--it;
			int c0=-1;
			while(true){
				auto it2=it;
				++it2;
				int l=it->X;
				int r=it2->X;
				int c=it->Y;
				addval(max(l,a),min(r,b),abs(c-x),0,n,0);
				if(l>=a && l<b)
					S.erase(it);
				if(r>b)
					c0=c;
				if(r>=b)
					break;
				it=it2;
			}
			S.insert(mp(a,x));
			if(c0!=-1)
				S.insert(mp(b,c0));
		}else{
			cout<<getsum(a,b,0,n,0)<<'\n';
		}
	}
	
	return 0;
}
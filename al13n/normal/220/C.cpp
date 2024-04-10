#pragma comment(linker,"/STACK:256000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <complex>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <cstring>
using namespace std;
#define bublic public:
#define sz(v) ((int)(v).size())
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define pb push_back
#define mp make_pair
#define istr stringstream
#define fi first
#define se second
#define X first
#define Y second
#define clr(a) memset((a),0,sizeof(a))
#define clr2(a) memset((a),-1,sizeof(a))
#define y0 asdy0
#define y1 asdy1
#define j0 asdj0
#define j1 asdj1
#define next asdnext
#define prev asdprev
#define link asdlink
#define unlink asdunlink
#define left asdleft
#define right asdright
#define hash asdhash
#define all(v) (v).begin(),(v).end()
typedef long long lng;
typedef unsigned int uint;
typedef unsigned long long ulng;
typedef unsigned char uchar;
typedef long double ld;
typedef pair<int,int> PII;
typedef pair<ld,ld> PDD;
typedef pair<lng,lng> PLL;
typedef complex<double> com;
const ld PI=3.1415926535897932384626433832795;
const ld EPS=1e-3;
const int inf=1000000000;
const lng linf=1000000000000000000LL;
template<class T> inline T sqr(T x) { return x * x; }

vector<pair<PII,PII> > evs[110000];
int A[110000];
int B[110000];
int res[110000];
int n;

int main() {
#ifdef __ASD__
    freopen("q.in","rt",stdin);freopen("q.out","wt",stdout);
#endif

	cin>>n;
	forn(i,n){
		int a;
		cin>>a;
		--a;
		A[a]=i;
	}
	forn(i,n){
		int a;
		cin>>a;
		--a;
		B[a]=i;
	}
	multiset<int> s[2]; // 0 - inc, 1 - dec
	forn(i,n){
		int a=A[i];
		int b=B[i];
		if(a>=b){
			s[1].insert(a-b);
			evs[a-b].pb(mp(mp(1,a-b),mp(0,-(a-b))));
			evs[n-1-b].pb(mp(mp(0,-(a-b)),mp(1,a+(n-b))));
		}else{
			s[0].insert(b-a);
			evs[n-1-b].pb(mp(mp(0,b-a),mp(1,a+(n-b))));
			evs[a-b+n].pb(mp(mp(1,a+(n-b)),mp(0,-(a-b+n))));
		}
	}

	forn(i,n){
		int &r=res[(n-i)%n];
		r=inf;
		if(s[0].size()){
			r=min(r,*s[0].begin()+i);
		}
		if(s[1].size()){
			r=min(r,*s[1].begin()-i);
		}
		forv(j,evs[i]){
			pair<PII,PII> p=evs[i][j];
			s[p.X.X].erase(s[p.X.X].lower_bound(p.X.Y));
			s[p.Y.X].insert(p.Y.Y);
		}
	}

	forn(i,n)
		cout<<res[i]<<'\n';

	return 0;
}
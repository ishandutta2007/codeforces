#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
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
typedef pair<PII, int> PIII;
typedef pair<lng, lng> PLL;
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
const double EPS = 1e-6;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;


int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	int n,m;
	cin>>n>>m;
	vector<PLL> evs;
	forn(i,m){
		int y1,y2,t;
		scanf("%d%d%d",&y1,&y2,&t);
		++t;
		evs.pb(mp(y1,t));
		evs.pb(mp(y2,-t));
	}
	sort(all(evs));
	vector<pair<lng,PLL> > evs2;
	multiset<lng> ts;
	forv(q,evs){
		lng y=evs[q].X;
		
		if(q && y>evs[q-1].X && sz(ts)){
			lng tt=*ts.begin();
			lng y1=evs[q-1].X;
			lng y2=y;
			//cout<<tt<<' '<<y1<<' '<<y2<<endl;
			evs2.pb(mp(tt-y2,mp(1,-(tt-y2))));
			evs2.pb(mp(tt-y1,mp(-1,tt-y1)));
		}
		
		lng t=evs[q].Y;
		
		if(t<0)
			ts.erase(ts.find(-t));
		else
			ts.insert(t);
	}
	forn(i,n){
		int t;
		scanf("%d",&t);
		++t;
		evs2.pb(mp(t,mp(0,i)));
	}
	
	sort(all(evs2));
	lng add=0,mul=0;
	forv(q,evs2){
		lng t=evs2[q].X;
		lng a=evs2[q].Y.X;
		lng b=evs2[q].Y.Y;
		//cout<<t<<' '<<a<<' '<<b<<endl;
		if(!a){
			printf("%d\n",(int)(add+t*mul));
		}else{
			mul+=a;
			add+=b;
		}
	}

	return 0;
}
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
typedef double ld;
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
#define hash asdhash
#define move asdmove
const double EPS = 1e-6;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
uint gcd(uint a,uint b){return a?gcd(b%a,a):b;}

int n,m;
PLL jiro[110];
lng ciel[110];

bool myless(PLL a,PLL b){
	return mp(a.Y,a.X)<mp(b.Y,b.X);
}

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	
	cin>>n>>m;
	forn(i,n){
		string s;
		cin>>s>>jiro[i].X;
		jiro[i].Y=s=="DEF";
		if(jiro[i].Y)
			++jiro[i].X;
	}
	forn(i,m){
		cin>>ciel[i];
	}
	sort(ciel,ciel+m);
	sort(jiro,jiro+n,myless);
	lng res=0;
	
	do{
		multiset<lng> st(ciel,ciel+m);
		bool ok=true;
		forn(i,n){
			if(jiro[i].Y){
				multiset<lng>::iterator it=st.lower_bound(jiro[i].X);
				if(it==st.end()){
					ok=false;
					break;
				}
				st.erase(it);
			}
		}
		if(!ok)
			break;
		lng r=0;
		forn(i,n){
			if(!jiro[i].Y){
				multiset<lng>::iterator it=st.lower_bound(jiro[i].X);
				if(it==st.end()){
					ok=false;
					break;
				}
				r+=*it-jiro[i].X;
				st.erase(it);
			}
		}
		if(!ok)
			break;
		while(!st.empty()){
			r+=*st.begin();
			st.erase(st.begin());
		}
		res=max(res,r);
	}while(false);
	
	{
		for(int k=1;k<n && k<=m;++k){
			if(jiro[k-1].Y)
				break;
			lng r=0;
			bool ok=true;
			forn(i,k){
				if(jiro[i].X > ciel[m-k+i]){
					ok=false;
					break;
				}
				r+=ciel[m-k+i]-jiro[i].X;
			}
			if(ok)
				res=max(res,r);
		}
	}
	
	cout<<res;
	
	return 0;
}
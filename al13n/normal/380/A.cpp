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
typedef pair<int, lng> PIL;
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
const ld EPS = 1e-14;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795L;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}



int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	
	int m,n;
	cin>>m;
	vector<pair<int,PLL> > A(m);
	forn(i,m){
		cin>>A[i].X>>A[i].Y.X;
		if(A[i].X==2)
			cin>>A[i].Y.Y;
	}
	cin>>n;
	vector<lng> B(n);
	forn(i,n){
		cin>>B[i];
	}
	int bi=0;
	const int lim=110000;
	vector<int> v;
	lng p=0;
	vector<int> ans;
	forn(i,m){
		if(bi==sz(B))
			break;
		if(A[i].X==2){
			lng l=A[i].Y.X;
			lng c=A[i].Y.Y;
			while(bi<sz(B) && B[bi]<=p+l*c){
				ans.pb(v[(B[bi]-1-p)%l]);
				++bi;
			}
			for(int j=0;j<l*c;++j){
				if(sz(v)>=lim)
					break;
				v.pb(v[j%l]);
			}
			p+=l*c;
		}else{
			if(p+1==B[bi]){
				ans.pb(A[i].Y.X);
				++bi;
			}
			if(sz(v)<lim)
				v.pb(A[i].Y.X);
			++p;
		}
	}
	forv(i,ans){
		cout<<ans[i]<<' ';
	}
	
	return 0;
}
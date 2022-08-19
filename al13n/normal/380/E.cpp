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

const int L=50;
ld A[310000];
int n;

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	cin>>n;
	vector<pair<ld,int> > pos;
	forn(i,n){
		scanf("%lf",A+i);
		pos.pb(mp(A[i],i));
	}
	sort(all(pos));
	reverse(all(pos));
	ld ans=0;
	set<int> st;
	forn(q,n){
		int p=pos[q].Y;
		ld x=pos[q].X;
		typedef set<int>::iterator iter;
		iter it0=st.insert(p).X;
		ld s1=0,s2=0;
		iter it=it0;
		forn(i,L){
			if(it==st.end())
				break;
			int p1=*it;
			++it;
			int p2;
			if(it==st.end())
				p2=n;
			else
				p2=*it;
			s1+=(p2-p1+0.)/(1LL<<i);
		}
		
		it=it0;
		forn(i,L){
			int p2=*it;
			int p1;
			bool done=it==st.begin();
			if(done)
				p1=-1;
			else{
				--it;
				p1=*it;
			}
			s2+=(p2-p1+0.)/(1LL<<i);
			if(done)
				break;
		}
		ans+=x*s1*s2;
		//cout<<x<<' '<<s1<<' '<<s2<<endl;
	}
	ans/=2.*n*n;
	printf("%.15lf",(double)ans);
	
	return 0;
}
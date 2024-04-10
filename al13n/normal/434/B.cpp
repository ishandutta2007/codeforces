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

int n,m;
vector<string> A;
vector<vector<int> > D;
vector<pair<int,PII> > Q;
vector<int> ans;

void turn(){
	vector<string> a=A;
	swap(n,m);
	A=vector<string>(n,string(m,' '));
	forn(i,n){
		forn(j,m){
			A[i][j]=a[j][n-i-1];
		}
	}
	forv(i,Q){
		swap(Q[i].Y.X,Q[i].Y.Y);
		Q[i].Y.X=n-Q[i].Y.X-1;
	}
}

void makeDrow(const vector<string> &A,int i){
	D[i][m-1]=A[i][m-1]=='#';
	for(int j=m-2;j>=0;--j){
		if(A[i][j]=='#')
			D[i][j]=D[i][j+1]+1;
		else
			D[i][j]=0;
	}
}

void makeD(){
	D.clear();D.resize(n,vector<int>(m));
	forn(i,n){
		makeDrow(A,i);
	}
}

int getans(int a,int b){
	vector<PII> st;
	st.pb(mp(-1,-1));
	int ans=0;
	forn(i,n+1){
		int d=i<n ? D[i][b] : 0;
		while(st.back().Y>=d){
			int pi=st[sz(st)-2].X;
			int s=st.back().Y*(i-1-pi);
			if(pi<a && i>a)
				ans=max(ans,s);
			st.pop_back();
		}
		st.pb(mp(i,d));
	}
	return ans;
}

void solve(){
	vector<string> A=::A;
	forv(q,Q){
		int a=Q[q].Y.X;
		int b=Q[q].Y.Y;
		if(Q[q].X==1){
			A[a][b]=(A[a][b]=='#')?' ':'#';
			makeDrow(A,a);
		}else{
			ans[q]=max(ans[q],getans(a,b));
		}
	}
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASKA".in", "r", stdin); freopen(TASKA".out", "w", stdout);
#endif
	
	int q;
	cin>>n>>m>>q;
	A.resize(n,string(m,' '));
	ans.resize(q,0);
	forn(i,n){
		forn(j,m){
			int a;
			scanf("%d",&a);
			if(a)
				A[i][j]='#';
		}
	}
	Q.resize(q);
	forn(i,q){
		cin>>Q[i].X>>Q[i].Y.X>>Q[i].Y.Y;
		--Q[i].Y.X;
		--Q[i].Y.Y;
	}
	
	forn(qqq,4){
		makeD();
		solve();
		turn();
	}
	
	forv(i,Q){
		if(Q[i].X==2)
			cout<<ans[i]<<'\n';
	}
	
	return 0;
}
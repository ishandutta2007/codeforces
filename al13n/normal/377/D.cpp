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
const ld EPS = 1e-14;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795L;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}

PII tree[410000];
int delta[410000];

void init(int a,int b,int k){
	if(b==a+1){
		tree[k]=mp(0,a);
		return;
	}
	int c=(a+b)/2;
	init(a,c,k*2+1);
	init(c,b,k*2+2);
	tree[k]=min(tree[k*2+1],tree[k*2+2]);
}

void pre(int a,int b,int k){
	if(!delta[k])
		return;
	tree[k].X+=delta[k];
	if(b>a+1){
		delta[k*2+1]+=delta[k];
		delta[k*2+2]+=delta[k];
	}
	delta[k]=0;
}

void add(int l,int r,int v,int a,int b,int k){
	if(l>=b || r<=a){
		pre(a,b,k);
		return;
	}
	if(l<=a&&r>=b){
		delta[k]+=v;
		pre(a,b,k);
		return;
	}
	pre(a,b,k);
	int c=(a+b)/2;
	add(l,r,v,a,c,k*2+1);
	add(l,r,v,c,b,k*2+2);
	tree[k]=max(tree[k*2+1],tree[k*2+2]);
}

vector<lng> rs;

void add(lng v,lng r,int s){
	int vi=lower_bound(all(rs),v)-rs.begin();
	int ri=upper_bound(all(rs),r)-rs.begin();
	add(vi,ri,s,0,sz(rs),0);
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	
	int n;
	cin>>n;
	vector<pair<pair<PLL,lng>,int> > A(n);
	vector<pair<lng,PLL> > B(n);
	forn(i,n){
		cin>>A[i].X.X.X>>A[i].X.Y>>A[i].X.X.Y;
		B[i]=mp(A[i].X.Y,A[i].X.X);
		rs.pb(A[i].X.X.Y);
		A[i].Y=i;
	}
	sort(all(A));
	sort(all(B));
	sort(all(rs));
	rs.erase(unique(all(rs)),rs.end());
	init(0,sz(rs),0);
	
	int bi=n-1;
	pair<int,PLL> res(-1,mp(0,0));
	for(int i=n-1;i>=0;--i){
		while(bi>=0 && B[bi].X>=A[i].X.X.X){
			add(B[bi].X,B[bi].Y.Y,1);
			--bi;
		}
		pre(0,sz(rs),0);
		res=max(res,mp(tree[0].X,mp(A[i].X.X.X,rs[tree[0].Y])));
		add(A[i].X.Y,A[i].X.X.Y,-1);
	}
	
	vector<int> ans;
	forn(i,n){
		if(A[i].X.X.X<=res.Y.X && A[i].X.X.Y>=res.Y.Y && A[i].X.Y>=res.Y.X && A[i].X.Y<=res.Y.Y)
			ans.pb(A[i].Y);
	}
	if(sz(ans)!=res.X)
		exit(123);
	
	cout<<sz(ans)<<'\n';
	forv(i,ans){
		cout<<ans[i]+1<<' ';
	}
	
	return 0;
}
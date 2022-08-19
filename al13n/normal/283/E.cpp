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

int tree[1100000];
int add[1100000];

void flip(int l,int r,int a,int b,int k){
	if(r<=a || l>=b)
		return;
	if(l<=a && r>=b){
		tree[k]=b-a-tree[k];
		add[k]^=1;
		return;
	}
	int c=(a+b)/2;
	flip(l,r,a,c,k*2+1);
	flip(l,r,c,b,k*2+2);
	tree[k]=tree[k*2+1]+tree[k*2+2];
	if(add[k])
		tree[k]=b-a-tree[k];
}

int getsum(int l,int r,int a,int b,int k){
	l=max(l,a);
	r=min(r,b);
	if(r<=l)
		return 0;
	if(l==a && r==b)
		return tree[k];
	int c=(a+b)/2;
	int t=getsum(l,r,a,c,k*2+1)+getsum(l,r,c,b,k*2+2);
	if(add[k])
		t=r-l-t;
	return t;
}

vector<int> qu1[110000];
vector<int> qu2[110000];

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	
	int n,k;
	cin>>n>>k;
	vector<PII> qus(k);
	vector<int> vals(n);
	forn(i,n){
		cin>>vals[i];
	}
	sort(all(vals));
	forn(i,k){
		int a,b;
		cin>>a>>b;
		a=lower_bound(all(vals),a)-vals.begin();
		b=upper_bound(all(vals),b)-vals.begin();
		qu1[a].pb(b);
		qu2[b].pb(a);
	}
	
	lng res=1LL*n*(n-1)*(n-2)/6;
	forn(i,n){
		forv(j,qu1[i]){
			flip(i,qu1[i][j],0,n,0);
		}
		forv(j,qu2[i]){
			flip(qu2[i][j],i,0,n,0);
		}
		int t1=getsum(i+1,n,0,n,0);
		int t2=getsum(0,i,0,n,0);
		int s=(n-i-1)-t1+t2;
		lng t=1LL*s*(s-1)/2;
		//cout<<s<<' '<<t<<endl;
		res-=t;
	}
	
	cout<<res;

	return 0;
}
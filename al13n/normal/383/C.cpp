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
typedef pair<string, string> PSS;
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
const ld EPS = 1e-10;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795L;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}

lng tree[1000000];

void addval(lng v,int l,int r,int a,int b,int k){
	if(l<=a&&r>=b){
		tree[k]+=v;
		return;
	}
	if(r<=a||l>=b)
		return;
	int c=(a+b)/2;
	addval(v,l,r,a,c,k*2+1);
	addval(v,l,r,c,b,k*2+2);
}

lng getval(int p,int a,int b,int k){
	if(b==a+1)
		return tree[k];
	int c=(a+b)/2;
	if(p<c)
		return tree[k]+getval(p,a,c,k*2+1);
	else
		return tree[k]+getval(p,c,b,k*2+2);
}

vector<int> gr[210000];
int D[210000];
int tin[210000];
int tout[210000];
int A0[210000];
int cnt;

void dfs1(int v,int d,int pr){
	D[v]=d;
	tin[v]=cnt++;
	forv(i,gr[v]){
		int p=gr[v][i];
		if(p==pr)
			continue;
		dfs1(p,d+1,v);
	}
	tout[v]=cnt;
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	forn(i,n){
		cin>>A0[i];
	}
	forn(i,n-1){
		int a,b;
		cin>>a>>b;
		--a;--b;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	dfs1(0,0,0);
	if(cnt!=n)
		exit(55);
	forn(qq,m){
		int t,v;
		cin>>t>>v;
		--v;
		if(t==1){
			int x;
			cin>>x;
			if(D[v]%2)
				x=-x;
			addval(x,tin[v],tout[v],0,n,0);
		}else{
			cout<<A0[v]+(D[v]%2?-1:1)*getval(tin[v],0,n,0)<<'\n';
		}
	}
	
	return 0;
}
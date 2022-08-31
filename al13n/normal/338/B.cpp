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
const double EPS = 1e-6;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
uint gcd(uint a,uint b){return a?gcd(b%a,a):b;}

int n;
vector<int> gr[110000];
int D[110000];
bool A[110000];
int res;
int L;

int dfs1(int v,int pr){
	int r=-1;
	if(A[v])
		r=0;
	forv(i,gr[v]){
		int p=gr[v][i];
		if(p==pr)
			continue;
		int t=dfs1(p,v);
		if(t!=-1)
			r=max(r,t+1);
	}
	D[v]=r;
	return r;
}

void dfs2(int v,int pr,int d){
	//cout<<v<<' '<<d<<' '<<D[v]<<endl;
	if(d<=L && D[v]<=L){
		//cout<<v<<endl;
		++res;
	}
	if(A[v] && d==-1)
		d=0;
	int mx1=-1,mx2=-1;
	forv(i,gr[v]){
		int p=gr[v][i];
		if(p==pr)
			continue;
		int t=D[p];
		if(t==-1)
			continue;
		++t;
		if(t>mx1){
			mx2=mx1;
			mx1=t;
		}else if(t>mx2){
			mx2=t;
		}
	}
	forv(i,gr[v]){
		int p=gr[v][i];
		if(p==pr)
			continue;
		int t=D[p];
		int x=mx1;
		if(t!=-1 && t+1==mx1){
			x=mx2;
		}
		if(x!=-1)
			++x;
		if(d!=-1)
			x=max(x,d+1);
		dfs2(p,v,x);
	}
}

int main(int argc, char **argv) {

	int m;
	cin>>n>>m>>L;
	forn(i,m){
		int a;
		cin>>a;
		--a;
		A[a]=true;
	}
	forn(i,n-1){
		int a,b;
		cin>>a>>b;
		--a;--b;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	dfs1(0,-1);
	dfs2(0,-1,-1);
	cout<<res;
	
	return 0;
}
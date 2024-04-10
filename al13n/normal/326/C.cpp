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
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
uint gcd(uint a,uint b){return a?gcd(b%a,a):b;}

struct state{
	int n;
	bool w[2][2];
	
	bool operator<(const state &b)const{
		if(n!=b.n)
			return n<b.n;
		forn(i,2){
			forn(j,2){
				if(w[i][j]!=b.w[i][j])
					return w[i][j]<b.w[i][j];
			}
		}
		return false;
	}
	
	bool go(int x,int y,vector<state> &res){
		if(!y && w[0][x])
			return false;
		if(y==n-1 && w[1][x])
			return false;
		down(x,y,res);
		state t=*this;
		swap(t.w[0][0],t.w[1][0]);
		swap(t.w[0][1],t.w[1][1]);
		t.down(x,n-1-y,res);
		return true;
	}
	
	void down(int x,int y, vector<state> &res){
		state r;
		r.n=y;
		r.w[0][0]=w[0][0];
		r.w[0][1]=w[0][1];
		r.w[1][x]=false;
		r.w[1][1-x]=true;
		r.fix(res);
	}
	
	void fix(vector<state> &res){
		if(!n)
			return;
		if(n==1){
			w[0][0]|=w[1][0];
			w[0][1]|=w[1][1];
			if(w[0][0]&&w[0][1])
				return;
			w[1][0]=w[0][0];
			w[1][1]=w[0][1];
			res.pb(*this);
			return;
		}
		res.pb(*this);
	}
};

map<state,int> gr;

int doit(state s){
	if(gr.count(s))
		return gr[s];
	set<int> gs;
	forn(x,2){
		forn(y,s.n){
			vector<state> t;
			if(!s.go(x,y,t))
				continue;
			int g=0;
			forv(i,t){
				g^=doit(t[i]);
			}
			gs.insert(g);
		}
	}
	int r=0;
	while(gs.count(r))
		++r;
	return gr[s]=r;
}

bool src[110][2];

int main(int argc, char **argv) {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	int n,m;
	cin>>n>>m;
	forn(i,m){
		int x,y;
		cin>>y>>x;
		--x;--y;
		src[y][x]=true;
		for(int yy=y-1;yy<=y+1;++yy){
			if(yy>=0 && yy<n)
				src[yy][1-x]=true;
		}
	}
	src[n][0]=src[n][1]=true;
	
	int g=0;
	state s;
	int p=0;
	forn(i,n+1){
		if(src[i][0] && src[i][1]){
			if(p<i){
				s.n=i-p;
				s.w[0][0]=src[p][0];
				s.w[0][1]=src[p][1];
				s.w[1][0]=src[i-1][0];
				s.w[1][1]=src[i-1][1];
				g^=doit(s);
				
			}
			p=i+1;
		}
	}
	
	cout<<(g?"WIN":"LOSE");
	
	return 0;
}
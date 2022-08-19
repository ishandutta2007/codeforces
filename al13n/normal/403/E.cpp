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
#define TASKA "sequence"

int n;

struct tree{
	vector<int> gr[210000];
	int par[210000];
	int tin[210000];
	int tout[210000];
	int now;
	
	void dfs(int v){
		tin[v]=now++;
		forv(i,gr[v]){
			dfs(gr[v][i]);
		}
		tout[v]=now;
	}
	
	void read(){
		forn(i,n-1){
			int a;
			scanf("%d",&a);
			--a;
			gr[a].pb(i+1);
			par[i+1]=a;
		}
		
		now=0;
		dfs(0);
	}
};

struct segtree{
	int tree[210000*4];
	
	void init(int a,int b,int k){
		tree[k]=-INF;
		if(b==a+1)
			return;
		int c=(a+b)/2;
		init(a,c,k*2+1);
		init(c,b,k*2+2);
	}
	
	void setval(int p,int v,int a,int b,int k){
		if(b==a+1){
			tree[k]=v;
			return;
		}
		int c=(a+b)/2;
		if(p<c)
			setval(p,v,a,c,k*2+1);
		else
			setval(p,v,c,b,k*2+2);
		tree[k]=max(tree[k*2+1],tree[k*2+2]);
	}
	
	void get(int l,int r,int v,vector<int> &res,int a,int b,int k){
		if(l>=b || r<=a)
			return;
		if(tree[k]<v)
			return;
		if(b==a+1){
			res.pb(a);
			return;
		}
		int c=(a+b)/2;
		get(l,r,v,res,a,c,k*2+1);
		get(l,r,v,res,c,b,k*2+2);
	}
};

struct pairset{
	segtree mn,mx;
	vector<pair<PII,int> > vmx,vmn;
	int smx,smn;
	
	void add(int a,int b,int id){
		if(b<a)
			swap(a,b);
		vmx.pb(mp(mp(a,b),id));
		vmn.pb(mp(mp(n-b-1,n-a-1),id));
	}
	
	void init(){
		sort(all(vmx));
		sort(all(vmn));
		smx=max(1,sz(vmx));
		smn=max(1,sz(vmn));
		mx.init(0,smx,0);
		mn.init(0,smn,0);
		forv(i,vmx){
			mx.setval(i,vmx[i].X.Y,0,smx,0);
		}
		forv(i,vmn){
			mn.setval(i,vmn[i].X.Y,0,smn,0);
		}
	}
	
	void pop(int a,int b,vector<int> &res){
		int i1,i2;
		
		vector<int> v1;
		i1=lower_bound(all(vmx),mp(mp(a,-INF),-INF))-vmx.begin();
		i2=upper_bound(all(vmx),mp(mp(b,-INF),-INF))-vmx.begin();
		mx.get(i1,i2,b,v1,0,smx,0);
		
		vector<int> v2;
		i1=lower_bound(all(vmn),mp(mp(n-b,-INF),-INF))-vmn.begin();
		i2=upper_bound(all(vmn),mp(mp(n-a,-INF),-INF))-vmn.begin();
		mn.get(i1,i2,n-a,v2,0,smn,0);

		forv(i,v1){
			mx.setval(v1[i],-INF,0,smx,0);
			res.pb(vmx[v1[i]].Y);
		}
		forv(i,v2){
			mn.setval(v2[i],-INF,0,smn,0);
			res.pb(vmn[v2[i]].Y);
		}
	}
};

tree ts[2];
pairset ss[2];

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASKA".in", "r", stdin); freopen(TASKA".out", "w", stdout);
#endif
	
	cin>>n;
	ts[0].read();
	ts[1].read();
	
	vector<int> es(1);
	cin>>es[0];
	
	forn(i,n-1){
		ss[0].add(ts[0].tin[i+1],ts[0].tin[ts[1].par[i+1]],i+1);
		if(i+1!=es[0])
			ss[1].add(ts[1].tin[i+1],ts[1].tin[ts[0].par[i+1]],i+1);
	}
	
	ss[0].init();
	ss[1].init();
	
	set<int> was[2];
	
	int cur=0,prev=1;
	while(sz(es)){
		sort(all(es));
		vector<int> nes;
		forv(i,es){
			if(was[cur].count(es[i]))
				continue;
			was[cur].insert(es[i]);
			nes.pb(es[i]);
		}
		es=nes;
		
		if(!sz(es))
			break;
		
		printf(cur?"Red\n":"Blue\n");
		forv(i,es){
			printf("%d ",es[i]);
		}
		printf("\n");
		
		nes.clear();
		forv(i,es){
			int v=es[i];
			ss[cur].pop(ts[cur].tin[v],ts[cur].tout[v],nes);
		}
		
		es=nes;
		swap(cur,prev);
	}
	
	return 0;
}
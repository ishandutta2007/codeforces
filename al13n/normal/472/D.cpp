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
typedef double ld;
typedef pair<int, int> PII;
//typedef pair<short, short> PSS;
typedef pair<string, string> PSS;
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
const ld EPS = 1e-9;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
lng powmod(lng a,lng p,lng m){lng r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
#define FAIL { cerr<<"assertion failed on line "<<__LINE__<<endl; exit(123);}

int n;
int D[2100][2100];

vector<vector<PIL> > gr;
bool was[2100];

int C[2100];

void nope(){
	cout<<"NO";
	exit(0);
}

void dfs(int v,int pr,lng d,int v0){
	if(was[v])
		nope();
	was[v]=true;
	if(d!=D[v0][v])
		nope();
	forv(i,gr[v]){
		int p=gr[v][i].X;
		lng w=gr[v][i].Y;
		if(p==pr)
			continue;
		dfs(p,v,d+w,v0);
	}
}

void dfs2(int v,int c){
	if(C[v]!=-1){
		if(C[v]!=c)
			exit(123);
		return;
	}
	C[v]=c;
	forv(i,gr[v]){
		dfs2(gr[v][i].X,c);
	}
}

int color(){
	forn(i,n){
		C[i]=-1;
	}
	int c=0;
	forn(i,n){
		if(C[i]==-1)
			dfs2(i,c++);
	}
	return c;
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);cin.tie(0);

	cin>>n;
	gr.resize(n);
	forn(i,n){
		forn(j,n){
			cin>>D[i][j];
			if((i==j) != !D[i][j])
				nope();
		}
	}
	
	while(true){
		int c=color();
		if(c==1)
			break;
		vector<pair<int,PII> > cl(c,mp(INF*2,mp(-1,-1)));
		forn(i,n){
			forn(j,n){
				if(C[i]!=C[j])
					cl[C[i]]=min(cl[C[i]],mp(D[i][j],mp(i,j)));
			}
		}
		forn(q,c){
			if(cl[q].Y.X==-1)
				exit(123);
			int w=C[cl[q].Y.Y];
			if(q<w || C[cl[w].Y.Y]!=q){
				gr[cl[q].Y.X].pb(mp(cl[q].Y.Y,cl[q].X));
				gr[cl[q].Y.Y].pb(mp(cl[q].Y.X,cl[q].X));
			}
		}
	}
	
	forn(q,n){
		clr(was,0);
		dfs(q,-1,0,q);
		forn(i,n){
			if(!was[i])
				nope();
		}
	}
	
	cout<<"YES";

	return 0;
}
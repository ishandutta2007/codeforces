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

int n;
vector<int> gr[510000];
vector<int> qu[510000][3];
char res[510000];
set<int> fills;

set<int>* merge(set<int>* a,set<int>* b){
	if(sz(*a)<sz(*b))
		swap(a,b);
	a->insert(all(*b));
	return a;
}

set<int>* doit(int v,int pr){
	forv(i,qu[v][0])
		fills.insert(qu[v][0][i]);
	set<int> *s=new set<int>(all(qu[v][1]));
	forv(i,gr[v]){
		int p=gr[v][i];
		if(p==pr)
			continue;
		s=merge(s,doit(p,v));
	}
	forv(i,qu[v][2]){
		int t=qu[v][2][i];
		char &r=res[t];
		set<int>::iterator it1,it2;
		it1=fills.lower_bound(t);
		it2=s->lower_bound(t);
		if(it1==fills.begin())
			r=0;
		else if(it2==s->begin())
			r=1;
		else{
			--it1;
			--it2;
			if(*it1<*it2)
				r=0;
			else
				r=1;
		}
	}
	forv(i,qu[v][0])
		fills.erase(qu[v][0][i]);
	return s;
}

int main(int argc, char **argv) {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	forn(i,n-1){
		int a,b;
		cin>>a>>b;
		--a;--b;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	int tc;
	cin>>tc;
	forn(i,tc){
		int c,v;
		cin>>c>>v;
		--v;
		--c;
		qu[v][c].pb(i);
		if(c!=2)
			res[i]=-1;
	}
	
	doit(0,0);
	
	forn(i,tc){
		if(res[i]!=-1)
			cout<<(int)res[i]<<'\n';
	}
	
	return 0;
}
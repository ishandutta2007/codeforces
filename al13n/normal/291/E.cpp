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
#define hash asdhash
const double EPS = 1e-6;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;

const int P=37;
const lng M1=INF+7,M2=INF+9;

struct hash{
	lng a,b;
	
	hash(){}
	hash(lng a,lng b):a(a%M1),b(b%M2){}
	
	hash operator+(const hash &h)const{
		return hash(a+h.a,b+h.b);
	}
	hash operator-(const hash &h)const{
		return hash(a-h.a+M1,b-h.b+M2);
	}
	hash operator*(const hash &h)const{
		return hash(a*h.a,b*h.b);
	}
	bool operator==(const hash &h)const{
		return a==h.a&&b==h.b;
	}
};

hash pw[310000];
vector<pair<int,string> > gr[110000];
hash hs[310000];
int p0;
int p;
int ans;

void push(char c){
	hs[p+1]=hs[p]+pw[p]*hash(c,c);
	++p;
}
void pop(){
	--p;
}

void dfs(int v){
	forv(i,gr[v]){
		string &s=gr[v][i].Y;
		forv(j,s){
			push(s[j]);
			if(p-p0>=p0 && hs[p]-hs[p-p0]==hs[p0]*pw[p-p0])
				++ans;
		}
		dfs(gr[v][i].X);
		forv(j,s){
			pop();
		}
	}
}

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	
	pw[0]=hash(1,1);
	forn(i,305000){
		pw[i+1]=pw[i]*hash(P,P);
	}
	
	int n;
	cin>>n;
	forn(i,n-1){
		int p;
		string s;
		cin>>p>>s;
		--p;
		gr[p].pb(mp(i+1,s));
	}
	string s0;
	cin>>s0;
	forv(i,s0){
		push(s0[i]);
	}
	p0=p;
	
	dfs(0);
	
	cout<<ans;

	return 0;
}
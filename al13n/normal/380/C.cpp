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
const ld EPS = 1e-14;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795L;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}

int tree[4100000];
char S[1100000];
int D[1100000];
int n;

void init(int a,int b,int k){
	if(b==a+1){
		tree[k]=D[a];
		return;
	}
	int c=(a+b)/2;
	init(a,c,k*2+1);
	init(c,b,k*2+2);
	tree[k]=min(tree[k*2+1],tree[k*2+2]);
}

int getmin(int l,int r,int a,int b,int k){
	if(l<=a && r>=b)
		return tree[k];
	if(l>=b || r<=a)
		return INF;
	int c=(a+b)/2;
	return min(getmin(l,r,a,c,k*2+1),getmin(l,r,c,b,k*2+2));
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	gets(S);
	n=strlen(S);
	forn(i,n){
		D[i+1]=D[i]+(S[i]=='('?1:-1);
	}
	init(0,n+1,0);
	int m;
	cin>>m;
	forn(i,m){
		int a,b;
		scanf("%d%d",&a,&b);
		--a;
		int mn=getmin(a,b+1,0,n+1,0);
		int d=D[a]-mn;
		//cerr<<mn<<' '<<d<<endl;
		printf("%d\n",b-a-d-(D[b]-D[a]+d));
	}
	
	return 0;
}
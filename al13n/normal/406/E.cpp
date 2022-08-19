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

lng doit(const vector<lng> &A,const vector<lng> &B){
	vector<lng> v;
	v.pb(0);
	forv(i,A){
		v.pb(v.back()+(upper_bound(all(B),A[i])-B.begin()));
	}
	lng res=0;
	forv(i,B){
		res+=v[upper_bound(all(A),B[i])-A.begin()];
		if(!i || B[i-1]!=B[i]){
			lng a=upper_bound(all(A),B[i])-lower_bound(all(A),B[i]);
			lng b=upper_bound(all(B),B[i])-B.begin()-i;
			res-=a*b*b;
			res+=b*(b-1)/2*a;
		}
	}
	return res;
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASKA".in", "r", stdin); freopen(TASKA".out", "w", stdout);
#endif
	
	lng L;
	int n;
	cin>>L>>n;
	vector<lng> A,B;
	forn(i,n){
		int s,x;
		scanf("%d%d",&s,&x);
		if(s)
			B.pb(x);
		else
			A.pb(x);
	}
	sort(all(A));
	sort(all(B));
	
	if(!sz(A))
		swap(A,B);
	if(!sz(B)){
		if(A[0]==A.back()){
			cout<<1LL*sz(A)*(sz(A)-1)*(sz(A)-2)/6;
			return 0;
		}
		lng c1=A.end()-lower_bound(all(A),A.back());
		lng c2=upper_bound(all(A),A.front())-A.begin();
		lng res=c1*c2*(sz(A)-c1-c2);
		res+=c1*(c1-1)/2*c2;
		res+=c2*(c2-1)/2*c1;
		cout<<res;
		return 0;
	}
	
	if(A[0]>B[0])
		swap(A,B);
	
	if(A.back()<B.front()){
		lng c1=A.end()-lower_bound(all(A),A.back());
		lng c2=upper_bound(all(B),B.front())-B.begin();
		lng res =c1*(c2*(c2-1)/2+c2*(sz(B)-c2));
		    res+=c2*(c1*(c1-1)/2+c1*(sz(A)-c1));
		cout<<res;
		return 0;
	}
	
	cout<<doit(A,B)+doit(B,A);
	
	return 0;
}
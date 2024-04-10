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

lng A[9];
lng M[9];
lng D[9];
int divs[9];
int n;
int res;
int rt;

void doit(int a,int r){
	if(divs[a] > 1)
		++r;
	r+=D[a];
	//cout<<a<<' '<<A[a]<<' '<<r<<' '<<rt<<endl;
	forn(i,n){
	//	cout<<A[i]<<' '<<M[i]<<' '<<D[i]<<endl;
	}
	//cout<<endl;
	if(a==n){
		if(rt>1)
			++r;
		//cout<<"ans "<<r<<endl<<endl;
		res=min(res,r);
		return;
	}
	++rt;
	doit(a+1,r);
	--rt;
	for(int i=a+1;i<n;++i){
		if(M[i]%A[a])
			continue;
		M[i]/=A[a];
		D[i]-=divs[a];
		doit(a+1,r);
		M[i]*=A[a];
		D[i]+=divs[a];
	}
}

int main(int argc, char **argv) {

	cin>>n;
	forn(i,n){
		cin>>A[i];
	}
	sort(A,A+n);
	forn(i,n){
		lng t=A[i];
		for(lng a=2;a*a<=t;++a){
			while(t%a==0){
				t/=a;
				++divs[i];
			}
		}
		if(t>1){
			++divs[i];
		}
		M[i]=A[i];
		D[i]=divs[i];
	}
	res=INF;
	doit(0,0);
	cout<<res;
	
	return 0;
}
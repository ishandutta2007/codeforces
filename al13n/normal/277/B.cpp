#pragma comment(linker, "/STACK:256000000")
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
typedef double ld;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
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
const double EPS = 1e-10;
const int INF = 1000*1000*1000;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;

PLL ar[210];
int n,m;

bool check(){
	forn(i,n){
		forn(j,i){
			forn(k,j){
				if((ar[i].X-ar[j].X)*(ar[j].Y-ar[k].Y)==(ar[i].Y-ar[j].Y)*(ar[j].X-ar[k].X))
					return false;
			}
		}
	}
	forn(i,m){
		int j=(i+1)%m;
		int k=(i+2)%m;
		if((ar[i].X-ar[j].X)*(ar[j].Y-ar[k].Y)<(ar[i].Y-ar[j].Y)*(ar[j].X-ar[k].X))
			return false;
	}
	return true;
}

void solve(){
	const double R =90000000;
	const double R2=95000000;
	const double da=PI/1000;
	forn(i,m){
		double x=cos(i*PI*2/m)*R;
		double y=sin(i*PI*2/m)*R;
		ar[i]=mp(x,y);
	}
	forn(i,n-m){
		double x=cos(i*PI*2/m+da)*R2;
		double y=sin(i*PI*2/m+da)*R2;
		ar[m+i]=mp(x,y);
	}
}

void stress(){
	for(m=3;m<=100;++m){
		n=m*2;
		solve();
		if(!check()){
			cout<<"failed "<<m<<endl;
			return;
		}
	}
	cout<<"passed"<<endl;
}

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	//stress();return 0;
	
	cin>>n>>m;
	if(m==3 && n>4){
		cout<<-1<<'\n';
	}else{
		solve();
		forn(i,n){
			cout<<ar[i].X<<' '<<ar[i].Y<<'\n';
		}
	}

	return 0;
}
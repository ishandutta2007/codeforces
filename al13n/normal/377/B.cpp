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

typedef pair<PLL,int> stud;
int ans[110000];

lng check(const vector<PLL> &A, const vector<stud> &B,int k){
	lng res=0;
	int p=sz(B)-1;
	set<PLI> s;
	for(int i=sz(A)-1;i>=0;){
		while(p>=0 && B[p].X.X>=A[i].X){
			s.insert(mp(B[p].X.Y,B[p].Y));
			--p;
		}
		if(s.empty())
			return LINF;
		res+=s.begin()->X;
		forn(q,k){
			if(i<0)
				break;
			ans[A[i].Y]=s.begin()->Y;
			--i;
		}
		s.erase(s.begin());
	}
	return res;
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	int n,m;
	lng s;
	cin>>n>>m>>s;
	vector<PLL> A(m);
	vector<stud> B(n);
	forv(i,A){
		cin>>A[i].X;
		A[i].Y=i;
	}
	forv(i,B){
		cin>>B[i].X.X;
	}
	forv(i,B){
		cin>>B[i].X.Y;
		B[i].Y=i;
	}
	sort(all(A));
	sort(all(B));
	
	int a=0,b=m+1;
	while(b>a+1){
		int k=(a+b)/2;
		if(check(A,B,k)>s)
			a=k;
		else
			b=k;
	}
	
	if(b==m+1)
		cout<<"NO";
	else{
		check(A,B,b);
		cout<<"YES\n";
		forn(i,m){
			cout<<ans[i]+1<<' ';
		}
	}
	
	return 0;
}
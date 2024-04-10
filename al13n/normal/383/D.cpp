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
const ld EPS = 1e-10;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795L;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}

int A[1100];
const lng mod=INF+7;
lng ans;

vector<lng> dodp(const vector<int> &v){
	int S=0;
	forv(i,v){
		S+=v[i];
	}
	vector<lng> res(S+1);
	vector<lng> dp(S+1);
	vector<lng> tmp(S+1);
	dp[0]=1;
	int s=0;
	forv(i,v){
		tmp=dp;
		dp.assign(S+1,0);
		forn(a,s+1){
			(dp[a+v[i]]+=tmp[a])%=mod;
			(dp[abs(a-v[i])]+=tmp[a])%=mod;
		}
		s+=v[i];
		forn(i,s+1){
			(res[i]+=dp[i])%=mod;
		}
	}
	return res;
}

void doit(int a,int b){
	if(b==a+1)
		return;
	int c=(a+b)/2;
	doit(a,c);
	doit(c,b);
	vector<int> v1,v2;
	for(int i=c-1;i>=a;--i)
		v1.pb(A[i]);
	for(int i=c;i<b;++i)
		v2.pb(A[i]);
	vector<lng> d1=dodp(v1),d2=dodp(v2);
	/*if(a==0&&b==4){
		cout<<"nya\n";
		forv(i,d1){
			cout<<d1[i]<<' ';
		}
		cout<<endl;
	}*/
	lng res=0;
	forn(i,min(sz(d1),sz(d2))){
		(res+=d1[i]*d2[i]%mod*(i?500000004:1))%=mod;
	}
	(ans+=res)%=mod;
	if(res)
		;//cout<<a<<' '<<c<<' '<<b<<": "<<res<<endl;
}

void gen(){
	cout<<"1000\n";
	forn(i,490){
		cout<<"1 ";
	}
	forn(i,9){
		cout<<"1000 ";
	}
	forn(i,501){
		cout<<"1 ";
	}
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	//freopen("input.txt","w",stdout);gen();return 0;
	
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	forn(i,n){
		cin>>A[i];
	}
	doit(0,n);
	cout<<ans;
	
	return 0;
}
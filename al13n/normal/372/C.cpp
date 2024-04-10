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

struct minqu{
	vector<PLL> a,b;
	minqu(){
		a.pb(mp(LINF,LINF));
		b.pb(mp(LINF,LINF));
	}
	
	int size(){
		return sz(a)+sz(b)-2;
	}
	void clear(){
		a.resize(1);
		b.resize(1);
	}
	void push(lng v){
		a.pb(mp(v,min(v,a.back().Y)));
	}
	lng get(){
		return min(a.back().Y,b.back().Y);
	}
	void pop(){
		if(sz(b)>1){
			b.pop_back();
			return;
		}
		while(sz(a)>1){
			b.push_back(mp(a.back().X,min(b.back().Y,a.back().X)));
			a.pop_back();
		}
		if(sz(b)>1){
			b.pop_back();
			return;
		}
		exit(79);
	}
	void print(){
		forv(i,a){
			cout<<a[i].X<<' '<<a[i].Y<<endl;
		}
		cout<<endl;
		forv(i,b){
			cout<<b[i].X<<' '<<b[i].Y<<endl;
		}
		cout<<endl;
	}
};

int n,m,d;
lng dp[2][155000];

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	cin>>n>>m>>d;
	lng res=0;
	vector<PII> evs;
	forn(i,m){
		int a,b,t;
		scanf("%d%d%d",&a,&b,&t);
		--a;
		evs.pb(mp(t,a));
		res+=b;
	}
	
	evs.pb(mp(-155000,0));
	evs.pb(mp(INF+10,0));
	sort(all(evs));
	minqu qu;
	int cur=0,prev=1;
	for(int q=sz(evs)-2;q>=0;--q){
		swap(prev,cur);
		lng w=1LL*(evs[q+1].X-evs[q].X)*d;
		qu.clear();
		for(int i=0;i<w && i<n; ++i)
			qu.push(dp[prev][i]);
		forn(i,n){
			if(i+w<n)
				qu.push(dp[prev][i+w]);
			if(i-w-1>=0)
				qu.pop();
			if(q==sz(evs)-3 && i==25){
			//	cout<<qu.get()<<endl;
			//	qu.print();
			}
			dp[cur][i]=qu.get()+abs(i-evs[q].Y);
			//cout<<dp[cur][i]<<' ';
		}
		//cout<<endl;
	}
	cout<<res-dp[cur][0];
	
	return 0;
}
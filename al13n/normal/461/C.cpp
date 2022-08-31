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
typedef pair<short, short> PSS;
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

struct tree{
	vector<int> T;
	
	tree(int n):T(n*4+10){init(0,n,0);}

	void init(int a,int b,int k){
		T[k]=b-a;
		if(b==a+1)
			return;
		int c=(a+b)/2;
		init(a,c,k*2+1);
		init(c,b,k*2+2);
	}
	
	void add(int p,int v,int a,int b,int k){
		if(b==a+1){
			T[k]+=v;
			return;
		}
		int c=(a+b)/2;
		if(p<c)
			add(p,v,a,c,k*2+1);
		else
			add(p,v,c,b,k*2+2);
		T[k]=T[k*2+1]+T[k*2+2];
	}
	
	int getsum(int l,int r,int a,int b,int k){
		if(l>=b || r<=a)
			return 0;
		if(l<=a && r>=b)
			return T[k];
		int c=(a+b)/2;
		return getsum(l,r,a,c,k*2+1)+getsum(l,r,c,b,k*2+2);
	}
};

struct arr{
	int n;
	tree t;
	int a,b;
	bool r=false;
	
	arr(int n):n(n),t(n),a(0),b(n){}
	
	int size(){
		return b-a;
	}
	int getsum(int l,int r){
		if(this->r){
			r=size()-r;
			l=size()-l;
			swap(l,r);
		}
		return t.getsum(a+l,a+r,0,n,0);
	}
	vector<int> pop_front(int k){
		vector<int> v(k);
		forn(i,k){
			v[i]=getsum(i,i+1);
		}
		if(r)
			b-=k;
		else
			a+=k;
		return v;
	}
	void rev(){
		r^=1;
	}
	void add(int i,int v){
		if(r)
			i=size()-i-1;
		t.add(a+i,v,0,n,0);
	}
};

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);cin.tie(0);

	int n,tc;
	cin>>n>>tc;
	arr a(n);
	forn(qqq,tc){
		/*
		cout<<endl<<qqq<<":"<<endl;
		forv(i,a){
			cout<<a.getsum(i,i+1)<<' ';
		}
		cout<<endl<<endl;//*/
	
		int t;
		cin>>t;
		if(t==1){
			int p;
			cin>>p;
			if(p>sz(a)-p){
				a.rev();
				p=sz(a)-p;
			}
			vector<int> v=a.pop_front(p);
			reverse(all(v));
			forv(i,v){
				a.add(i,v[i]);
			}
		}else{
			int l,r;
			cin>>l>>r;
			cout<<a.getsum(l,r)<<'\n';
		}
	}

	return 0;
}
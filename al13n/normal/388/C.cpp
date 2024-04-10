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
const ld EPS = 1e-10;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
lng powmod(lng a,lng p,lng m){lng r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
#define TASKA "holygame"

lng myabs(lng a){
	return a<0?-a:a;
}

struct vec{
	lng x,y,z;
	vec(){}
	vec(lng x,lng y,lng z):x(x),y(y),z(z){}
	void read(){
		cin>>x>>y>>z;
	}
	lng dot(const vec &b)const{
		return x*b.x+y*b.y+z*b.z;
	}
	vec operator-(const vec &b)const{
		return vec(x-b.x,y-b.y,z-b.z);
	}
	vec operator+(const vec &b)const{
		return vec(x+b.x,y+b.y,z+b.z);
	}
	vec cross(const vec &b)const{
		return vec(y*b.z-z*b.y,b.x*z-b.z*x,x*b.y-y*b.x);
	}
	bool operator!()const{
		return !x&&!y&&!z;
	}
	bool operator<(const vec &b)const{
		return mp(mp(x,y),z)<mp(mp(b.x,b.y),b.z);
	}
	vec operator-()const{
		return vec(-x,-y,-z);
	}
	vec norm()const{
		vec r=*this;
		if(r<vec(0,0,0))
			r=-r;
		lng g=gcd(gcd(myabs(x),myabs(y)),myabs(z));
		r.x/=g;
		r.y/=g;
		r.z/=g;
		return r;
	}
	bool operator==(const vec &b)const{
		return x==b.x&&y==b.y&&z==b.z;
	}
};

struct frac{
	lng a,b;
	void norm(){
		if(b<0){
			b*=-1;
			a*=-1;
		}
		lng g=gcd(abs(a),b);
		a/=g;
		b/=g;
	}
	frac(){}
	frac(lng a,lng b=1):a(a),b(b){
		norm();
	}
	frac operator+(const frac &f)const{
		return frac(a*f.b+b*f.a,b*f.b);
	}
	frac operator*(const frac &f)const{
		return frac(a*f.a,b*f.b);
	}
	bool operator<(const frac &f)const{
		return mp(a,b)<mp(f.a,f.b);
	}
	bool operator==(const frac &f)const{
		return a==f.a && b==f.b;
	}
};

struct fvec{
	frac x,y,z;
	fvec(){}
	fvec(frac x,frac y,frac z):x(x),y(y),z(z){}
	fvec(const vec &v):x(v.x),y(v.y),z(v.z){}
	fvec operator*(frac &f)const{
		return fvec(x*f,y*f,z*f);
	}
	fvec operator+(const fvec &b)const{
		return fvec(x+b.x,y+b.y,z+b.z);
	}
	bool operator<(const fvec &b)const{
		return mp(mp(x,y),z)<mp(mp(b.x,b.y),b.z);
	}
	bool operator==(const fvec &b)const{
		return x==b.x&&y==b.y&&z==b.z;
	}
};

struct plane{
	vec n;
	lng d;
	vec v1,v2;
	
	bool init(const vec &a,const vec &b,const vec &c,const vec &dd, fvec &inters){
		v1=(b-a).norm();
		v2=(c-dd).norm();
		n=v1.cross(v2);
		if(!n)
			return false;
		n=n.norm();
		d=n.dot(a);
		if(n.dot(c) != d)
			return false;
		
		vec tn=vec(0,0,1).cross(v2);
		frac t((c-a).dot(tn),v1.dot(tn));
		inters=fvec(a)+fvec(v1)*t;
		return true;
	}
	
	bool operator<(const plane &b)const{
		return mp(n,d)<mp(b.n,b.d);
	}
};

int n;
pair<vec,vec> A[1100];

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASKA".in", "r", stdin); freopen(TASKA".out", "w", stdout);
#endif
	
	int n;
	cin>>n;
	vector<int> v;
	int s1=0,s2=0;
	forn(i,n){
		int k;
		cin>>k;
		forn(j,k){
			int a;
			cin>>a;
			if(k%2 && j==k/2){
				v.pb(a);
			}else if(j<k/2)
				s1+=a;
			else
				s2+=a;
		}
	}
	sort(all(v));
	reverse(all(v));
	forv(i,v){
		if(i%2)
			s2+=v[i];
		else
			s1+=v[i];
	}
	cout<<s1<<' '<<s2<<endl;
	
	return 0;
}
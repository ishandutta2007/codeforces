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

struct tree{
lng mx[1000000];
lng sum[1000000];
lng add[1000000];

void pre(int a,int b,int k){
	if(!add[k])
		return;
	if(b>a+1){
		add[k*2+1]+=add[k];
		add[k*2+2]+=add[k];
	}
	sum[k]+=add[k]*(b-a);
	mx[k]+=add[k];
	add[k]=0;
}
void post(int a,int b,int k){
	pre(a,b,k);
	int c=(a+b)/2;
	if(b>a+1){
		pre(a,c,k*2+1);
		pre(c,b,k*2+2);
		mx[k]=max(mx[k*2+1],mx[k*2+2]);
		sum[k]=sum[k*2+1]+sum[k*2+2];
	}
}

void addseg(int l,int r,lng v,int a,int b,int k){
	pre(a,b,k);
	if(l<=a && r>=b){
		add[k]+=v;
		return;
	}
	if(l>=b || r<=a)
		return;
	int c=(a+b)/2;
	addseg(l,r,v,a,c,k*2+1);
	addseg(l,r,v,c,b,k*2+2);
	post(a,b,k);
}

lng getsum(int l,int r,int a,int b,int k){
	pre(a,b,k);
	if(l<=a&&r>=b)
		return sum[k];
	if(l>=b||r<=a)
		return 0;
	int c=(a+b)/2;
	return getsum(l,r,a,c,k*2+1)+getsum(l,r,c,b,k*2+2);
}
};

int A[160000];
lng B[160000];
int cnt[160000];
tree tcnt;
tree tmx;
int n;

void add(int v){
	if(!cnt[v]){
		int p=tcnt.getsum(0,v,0,n+1,0);
		tmx.addseg(v,v+1,p-v-tmx.getsum(v,v+1,0,n+1,0),0,n+1,0);
	}
	++cnt[v];
	tcnt.addseg(v,v+1,1,0,n+1,0);
	tmx.addseg(v,n+1,1,0,n+1,0);
}

void del(int v){
	tcnt.addseg(v,v+1,-1,0,n+1,0);
	--cnt[v];
	tmx.addseg(v,n+1,-1,0,n+1,0);
	if(!cnt[v])
		tmx.addseg(v,v+1,-INF-tmx.getsum(v,v+1,0,n+1,0),0,n+1,0);
}

bool valid(){
	tmx.pre(0,n+1,0);
	return tmx.mx[0]<=0;
}

int main(int argc, char **argv) {

	int m;
	lng H;
	cin>>m>>n>>H;
	forn(i,n){
		cin>>B[i];
		B[i]=H-B[i];
	}
	sort(B,B+n);
	forn(i,m){
		lng a;
		cin>>a;
		int p=upper_bound(B,B+n,a)-B;
		A[i]=p;
		//cout<<A[i]<<' ';
	}
	//cout<<endl;
	tmx.addseg(0,n+1,-INF,0,n+1,0);
	int res=0;
	forn(i,m){
		add(A[i]);
		if(i-n>=0)
			del(A[i-n]);
		if(i-n+1>=0 && valid()){
			++res;
	//		cout<<i<<endl;
		}
	}
	cout<<res;
	
	return 0;
}
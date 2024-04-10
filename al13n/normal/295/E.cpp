#pragma comment(linker, "/STACK:512000000")
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
const double EPS = 1e-6;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;

lng xs[210000];
int haspt[210000];

struct val{
	lng res;
	lng sum;
	lng cnt;
	lng l,r;
	
	val(){}
	val(lng l,lng r,lng cnt):res(0),sum(cnt*l),cnt(cnt),l(l),r(r){}
	val(val a,val b){
		l=a.l;
		r=b.r;
		cnt=a.cnt+b.cnt;
		sum=a.sum+b.sum;
		res=a.res+b.res+(a.r*a.cnt-a.sum)*b.cnt+(b.sum-b.l*b.cnt)*a.cnt;
	}
};

val tree[1100000];

void init(int a,int b,int k){
	if(b==a+1){
		tree[k]=val(xs[a],xs[b],haspt[a]);
		return;
	}
	int c=(a+b)/2;
	init(a,c,k*2+1);
	init(c,b,k*2+2);
	tree[k]=val(tree[k*2+1],tree[k*2+2]);
}
void updpt(int p,int v,int a,int b,int k){
	if(b==a+1){
		tree[k]=val(xs[a],xs[b],v);
		return;
	}
	int c=(a+b)/2;
	if(p<c)
		updpt(p,v,a,c,k*2+1);
	else
		updpt(p,v,c,b,k*2+2);
	tree[k]=val(tree[k*2+1],tree[k*2+2]);
}
val getseg(int l,int r,int a,int b,int k){
	if(l==a && r==b)
		return tree[k];
	int c=(a+b)/2;
	if(r<=c)
		return getseg(l,r,a,c,k*2+1);
	if(l>=c)
		return getseg(l,r,c,b,k*2+2);
	return val(getseg(l,c,a,c,k*2+1),getseg(c,r,c,b,k*2+2));
}

lng pts[110000];
lng pts1[110000];
int qtype[110000];
int qa[110000];
int qb[110000];

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(false);

	int n0;
	cin>>n0;
	int n=0;
	forn(i,n0){
		cin>>pts[i];
		pts1[i]=pts[i];
		xs[n++]=pts1[i];
	}
	int m;
	cin>>m;
	forn(i,m){
		cin>>qtype[i]>>qa[i]>>qb[i];
		if(qtype[i]==1){
			--qa[i];
			pts1[qa[i]]+=qb[i];
			xs[n++]=pts1[qa[i]];
		}
	}
	
	sort(xs,xs+n);
	n=unique(xs,xs+n)-xs;
	xs[n]=INF*2;
	
	forn(i,n0){
		int p=lower_bound(xs,xs+n,pts[i])-xs;
		if(xs[p]!=pts[i])
			exit(66);
		haspt[p]=1;
	}
	init(0,n,0);
	
	forn(i,m){
		if(qtype[i]==1){
			int p=lower_bound(xs,xs+n,pts[qa[i]])-xs;
			updpt(p,0,0,n,0);
			pts[qa[i]]+=qb[i];
			p=lower_bound(xs,xs+n,pts[qa[i]])-xs;
			if(xs[p]!=pts[qa[i]])
				exit(123);
			updpt(p,1,0,n,0);
		}else{
			int a=lower_bound(xs,xs+n,qa[i])-xs;
			int b=upper_bound(xs,xs+n,qb[i])-xs;
			lng r;
			if(b==a)
				r=0;
			else
				r=getseg(a,b,0,n,0).res;
			cout<<r<<'\n';
		}
	}

	return 0;
}
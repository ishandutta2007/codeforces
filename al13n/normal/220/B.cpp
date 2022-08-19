#pragma comment(linker,"/STACK:256000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <complex>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <cstring>
using namespace std;
#define bublic public:
#define sz(v) ((int)(v).size())
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define pb push_back
#define mp make_pair
#define istr stringstream
#define fi first
#define se second
#define X first
#define Y second
#define clr(a) memset((a),0,sizeof(a))
#define clr2(a) memset((a),-1,sizeof(a))
#define y0 asdy0
#define y1 asdy1
#define j0 asdj0
#define j1 asdj1
#define next asdnext
#define prev asdprev
#define link asdlink
#define unlink asdunlink
#define left asdleft
#define right asdright
#define hash asdhash
#define all(v) (v).begin(),(v).end()
typedef long long lng;
typedef unsigned int uint;
typedef unsigned long long ulng;
typedef unsigned char uchar;
typedef long double ld;
typedef pair<int,int> PII;
typedef pair<ld,ld> PDD;
typedef pair<lng,lng> PLL;
typedef complex<double> com;
const ld PI=3.1415926535897932384626433832795;
const ld EPS=1e-3;
const int inf=1000000000;
const lng linf=1000000000000000000LL;
template<class T> inline T sqr(T x) { return x * x; }

int src[110000];
int cnt[110000];
int n;
int cur;
int res[110000];

void upd(int v,int s){
	if(v>n)
		return;
	if(cnt[v]==v)
		--cur;
	cnt[v]+=s;
	if(cnt[v]==v)
		++cur;
}

int main() {
#ifdef __ASD__
    freopen("q.in","rt",stdin);freopen("q.out","wt",stdout);
#endif

	int m;
	cin>>n>>m;
	forn(i,n){
		scanf("%d",src+i);
	}
	const int B=300;
	vector<pair<PII,PII> > qu(m);
	forn(i,m){
		int a,b;
		cin>>a>>b;
		--a;
		qu[i]=mp(mp(a/B,b),mp(a,i));
	}

	sort(all(qu));

	int l=0,r=0;
	forv(i,qu){
		int a=qu[i].Y.X;
		int b=qu[i].X.Y;
		int id=qu[i].Y.Y;
		while(l>a)
			upd(src[--l],1);
		while(r<b)
			upd(src[r++],1);
		while(l<a)
			upd(src[l++],-1);
		while(r>b)
			upd(src[--r],-1);
		res[id]=cur;
	}

	forn(i,m)
		cout<<res[i]<<'\n';

	return 0;
}
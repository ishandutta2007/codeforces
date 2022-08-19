#pragma comment(linker,"/STACK:256000000")
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
#include <memory.h>
using namespace std;
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
#define clr(a,v) memset((a),(v),sizeof(a))
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
#define div asddiv
#define all(v) (v).begin(),(v).end()
typedef long long lng;
typedef unsigned int uint;
typedef unsigned long long ulng;
typedef unsigned char uchar;
typedef double ld;
typedef pair<int,int> PII;
typedef pair<ld,ld> PDD;
typedef pair<lng,lng> PLL;
typedef complex<double> com;
const ld PI=3.1415926535897932384626433832795;
const ld EPS=1e-12;
const int inf=1000000000;
const lng linf=1000000000000000000LL;
template<class T> inline T sqr(T x) { return x * x; }
int gcd(int a,int b){return a?gcd(b%a,a):b;}

PII tree[2100000];
int delta[2100000];

void pre(int k){
	if(!delta[k])
		return;
	tree[k].X+=delta[k];
	delta[k*2+1]+=delta[k];
	delta[k*2+2]+=delta[k];
	delta[k]=0;
}

PII add(PII a,PII b){
	if(a.X==b.X)
		return mp(a.X,a.Y+b.Y);
	return min(a,b);
}

void post(int k){
	pre(k);
	pre(k*2+1);
	pre(k*2+2);
	tree[k]=add(tree[k*2+1],tree[k*2+2]);
}

void init(int a,int b,int k){
	if(b==a+1){
		tree[k]=mp(0,1);
		return;
	}
	int c=(a+b)/2;
	init(a,c,k*2+1);
	init(c,b,k*2+2);
	post(k);
}

void inc(int l,int r,int v,int a,int b,int k){
	pre(k);
	if(l<=a&&r>=b){
		delta[k]+=v;
		pre(k);
		return;
	}
	if(l>=b||r<=a)
		return;
	int c=(a+b)/2;
	inc(l,r,v,a,c,k*2+1);
	inc(l,r,v,c,b,k*2+2);
	post(k);
}

vector<int> gr[110000];
vector<int> bs[110000];
int pos1[110000];
int pos2[110000];
int cnt;
int n;
int res[110000];

void dfs1(int v,int pr){
	pos1[v]=cnt++;
	forv(i,gr[v]){
		int p=gr[v][i];
		if(p==pr)
			continue;
		dfs1(p,v);
	}
	pos2[v]=cnt;
}

void dfs2(int v,int pr){
	forv(i,bs[v]){
		int p=bs[v][i];
		inc(pos1[v],pos2[v],1,0,n,0);
		inc(pos1[p],pos2[p],1,0,n,0);
	}
	PII t=tree[0];
	res[v]=n;
	if(!t.X)
		res[v]-=t.Y;
	forv(i,gr[v]){
		int p=gr[v][i];
		if(p==pr)
			continue;
		dfs2(p,v);
	}
	forv(i,bs[v]){
		int p=bs[v][i];
		inc(pos1[v],pos2[v],-1,0,n,0);
		inc(pos1[p],pos2[p],-1,0,n,0);
	}
}

int main() {
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	
	int m;
	cin>>n>>m;
	forn(i,n-1){
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	forn(i,m){
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		bs[a].pb(b);
		bs[b].pb(a);
	}
	init(0,n,0);
	dfs1(0,-1);
	dfs2(0,-1);
	
	forn(i,n){
		if(res[i])
			--res[i];
		printf("%d ",res[i]);
	}
	
	return 0;
}
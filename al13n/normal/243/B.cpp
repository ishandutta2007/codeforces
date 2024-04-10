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
const ld EPS=1e-8;
const int inf=1000000000;
const lng linf=1000000000000000000LL;
template<class T> inline T sqr(T x) { return x * x; }
int gcd(int a,int b){return a?gcd(b%a,a):b;}

int n,m,H,T;
vector<int> gr[110000];
PII E[110000];
bool in[110000];

void answer(int u,int v){
	cout<<"YES"<<'\n';
	cout<<u+1<<' '<<v+1<<'\n';
	set<int> su;
	forv(i,gr[u]){
		su.insert(gr[u][i]);
	}
	vector<int> au,av,az;
	set<int> both;
	forv(i,gr[v]){
		int p=gr[v][i];
		if(p==u)
			continue;
		if(su.count(p)){
			both.insert(p);
			az.pb(p);
		}else{
			av.pb(p);
		}
	}
	forv(i,gr[u]){
		int p=gr[u][i];
		if(p==v)
			continue;
		if(!both.count(p)){
			au.pb(p);
		}
	}
	while(!au.empty() && H){
		--H;
		cout<<au.back()+1<<' ';
		au.pop_back();
	}
	while(!az.empty() && H){
		--H;
		cout<<az.back()+1<<' ';
		az.pop_back();
	}
	if(H)
		exit(123);
	cout<<'\n';
	while(!av.empty() && T){
		--T;
		cout<<av.back()+1<<' ';
		av.pop_back();
	}
	while(!az.empty() && T){
		--T;
		cout<<az.back()+1<<' ';
		az.pop_back();
	}
	if(T)
		exit(123);
	exit(0);
}

int main() {
#ifdef __ASD__
    freopen("input.txt","rt",stdin);freopen("output.txt","wt",stdout);
#endif

	int m;
	cin>>n>>m>>H>>T;
	forn(i,m){
		int a,b;
		cin>>a>>b;
		--a;--b;
		E[i]=mp(a,b);
		gr[a].pb(b);
		gr[b].pb(a);
	}
	forn(v,n){
		forv(q,gr[v]){
			int u=gr[v][q];
			in[u]=true;
		}
		int cv0=sz(gr[v])-1;
		forv(q,gr[v]){
int cv=cv0;
			int u=gr[v][q];
			if(sz(gr[u])>sz(gr[v]) || (sz(gr[u])==sz(gr[v]) && u>v))
				continue;
			int cu=sz(gr[u])-1;
			int cz=0;
			forv(i,gr[u]){
				if(in[gr[u][i]])
					++cz;
			}
			cv-=cz;
			cu-=cz;
			if(cv+cz >= T && cu+cz >= H && min(cv,T)+min(cu,H)+cz >= H+T)
				answer(u,v);
			swap(u,v);
			swap(cu,cv);
			if(cv+cz >= T && cu+cz >= H && min(cv,T)+min(cu,H)+cz >= H+T)
				answer(u,v);
			swap(u,v);
			swap(cu,cv);
		}
		forv(q,gr[v]){
			int u=gr[v][q];
			in[u]=false;
		}
	}
	cout<<"NO";

	return 0;
}
#pragma comment(linker,"/STACK:256000000")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <iomanip>
#include <sstream>
#include <stack>
#include <ctime>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
#define linf 1000000000000000000LL
#define dinf 1e200
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-5
#define EQ(a,b) (fabs((a)-(b))<eps)
#define SQ(a) ((a)*(a))
#define PI 3.14159265359
#define index asdindex
#define FI first
#define SE second
#define prev asdprev
#define PII pair<int,int> 
#define PLL pair<lng,lng> 
#define PDD pair<double,double> 
#define X first
#define Y second
#define unlink asdunlink
typedef unsigned char uchar;
typedef unsigned int uint;
inline int mymax(int a,int b){return a<b?b:a;}
inline int mymin(int a,int b){return a>b?b:a;}
inline lng mymax(lng a,lng b){return a<b?b:a;}
inline lng mymin(lng a,lng b){return a>b?b:a;}

int n;
vector<int> gr[110000];
int dep[110000];
int jmp[110000][20];
int beg[110000];
int end[110000];
map<PII,int> ind;
int res[110000];

int dfs2(int v,int pr){
	int r=-end[v]+beg[v];
	forv(i,gr[v]){
		int p=gr[v][i];
		if(p==pr)
			continue;
		int t=dfs2(p,v);
		res[ind[mp(v,p)]]=t;
		r+=t;
	}
	return r;
}

void dfs(int v,int pr,int d){
	jmp[v][0]=pr;
	dep[v]=d;
	forv(i,gr[v]){
		int p=gr[v][i];
		if(p==pr)
			continue;
		dfs(p,v,d+1);
	}
}

void genjmp(){
	forn(i,19)
		forn(j,n)
			jmp[j][i+1]=jmp[jmp[j][i]][i];
}

int todep(int a,int d){
	for(int i=19;i>=0;--i)
		if(dep[jmp[a][i]]>=d)
			a=jmp[a][i];
	return a;
}

int lca(int a,int b){
	int d=min(dep[a],dep[b]);
	a=todep(a,d);
	b=todep(b,d);
	if(a==b)
		return a;
	for(int i=19;i>=0;--i)
		if(jmp[a][i]!=jmp[b][i]){
			a=jmp[a][i];
			b=jmp[b][i];
		}
	return jmp[a][0];
}

void addhalf(int a,int b){
	if(a==b)
		return;
	++end[a];
	++beg[b];
}

void addpath(int a,int b){
	int c=lca(a,b);
	addhalf(c,a);
	addhalf(c,b);
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	cin>>n;
	forn(i,n-1){
		int a,b;
		cin>>a>>b;
		--a;--b;
		gr[a].pb(b);
		gr[b].pb(a);
		ind[mp(a,b)]=i;
		ind[mp(b,a)]=i;
	}
	dfs(0,0,0);
	genjmp();

	int tc;
	cin>>tc;
	forn(qqq,tc){
		int a,b;
		cin>>a>>b;
		--a;--b;
		addpath(a,b);
	}

	dfs2(0,0);

	forn(i,n-1)
		cout<<res[i]<<' ';

    return 0;
}
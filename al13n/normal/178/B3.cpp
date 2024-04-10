#include <vector>
#include <cstring>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <complex>
#ifdef __ASD__
//#include <windows.h>
#endif
using namespace std;
#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i=0;i<(n);++i)
#define fornn(i,n) for(i=0;i<(n);++i)
#define lng long long
#define SQ(a) ((a)*(a))
#define forv(i,v) for(int i=0;i<(int)v.size();++i)
#define mp make_pair
#define pb push_back
#define ABS(a) ((a)<0?-(a):(a))
#define iinf 1000000000
#define linf 1000000000000000000LL
#define dinf 1e200
#define left asdleft
#define prev asdprev
#define eps 1e-12
#define y1 asdy1
#define y2 asdy2
#define EQ(a,b) abs((a)-(b))<eps
#define PI 3.1415926535897932384626433832795
#define DEG2RAD PI/180
#define ulng unsigned lng
#define next asdnext
#define prev asdprev
#define PII pair<int,int> 
#define X first
#define Y second
void mytimer(string task){
#ifdef __ASD__
        //static LARGE_INTEGER prev;      LARGE_INTEGER cur,freq; QueryPerformanceCounter(&cur);  QueryPerformanceFrequency(&freq);       if(task!="")            cout<<task<<" took "<<(cur.QuadPart-prev.QuadPart)*1.0/freq.QuadPart<<endl;     prev=cur;
#endif
}
void ext(int c){
#ifdef __ASD__
        exit(c);
#endif
}

vector<PII> *gr=new vector<PII>[110000];
int comp[110000];
int cnt;
vector<int> *tree=new vector<int>[110000];
int tin[110000];
int tim;
int dep[110000];
int jmp[110000][20];
int n;

int dfs1(int v,int pr){
	if(tin[v])
		return tin[v];
	int r=tin[v]=++tim;
	forv(i,gr[v]){
		int p=gr[v][i].X;
		if(p==pr)
			continue;
		int t=dfs1(p,v);
		if(t>tin[v])
			gr[v][i].Y=1;
		r=min(r,t);
	}
	return r;
}

void dfs2(int v,int c){
	if(comp[v]!=-1)
		return;
	comp[v]=c;
	forv(i,gr[v]){
		int p=gr[v][i].X;
		int t=gr[v][i].Y?cnt++:c;
		dfs2(p,t);
		if(c!=t){
			tree[c].pb(t);
			tree[t].pb(c);
		}
	}
}

void dfs3(int v,int pr,int d){
	jmp[v][0]=pr;
	dep[v]=d;
	forv(i,tree[v]){
		int p=tree[v][i];
		if(p==pr)
			continue;
		dfs3(p,v,d+1);
	}
}

void genjmp(){
	forn(i,19){
		forn(v,n){
			jmp[v][i+1]=jmp[jmp[v][i]][i];
		}
	}
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
		if(jmp[a][i]!=jmp[b][i])
			a=jmp[a][i],b=jmp[b][i];
	return jmp[a][0];
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

	ios_base::sync_with_stdio(false);

	int m;
	cin>>n>>m;
	forn(i,m){
		int a,b;
		cin>>a>>b;
		--a;--b;
		gr[a].pb(mp(b,0));
		gr[b].pb(mp(a,0));
	}
	forn(i,n)
		comp[i]=-1;

	dfs1(0,-1);
	dfs2(0,cnt++);

	n=cnt;

	dfs3(0,0,0);
	genjmp();

	int tc;
	cin>>tc;
	forn(qqq,tc){
		int a,b;
		cin>>a>>b;
		--a;--b;
		a=comp[a];
		b=comp[b];

		int c=lca(a,b);
		cout<<dep[a]+dep[b]-2*dep[c]<<'\n';
	}

	return 0;
}
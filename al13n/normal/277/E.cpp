#pragma comment(linker, "/STACK:256000000")
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
typedef double ld;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
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
const double EPS = 1e-10;
const int INF = 1000*1000*1000;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;

struct graph{
	struct edge{
		int to,cap,back;
		double cost;
	};

	vector<edge> gr[810];
	int n,S,T;
	
	double P[810];
	double dist[810];
	PII prev[810];
	bool done[810];
	
	void add(int a,int b,int cap,double cost){
		edge e1,e2;
		
		e1.to=b;
		e1.cap=cap;
		e1.cost=cost;
		e1.back=sz(gr[b]);
		
		e2.to=a;
		e2.cap=0;
		e2.cost=-cost;
		e2.back=sz(gr[a]);
		
		gr[a].pb(e1);
		gr[b].pb(e2);
	}
	
	pair<int,double> augment(){
		priority_queue<pair<double,int> > qu;
		forn(i,n){
			dist[i]=1e200;
			done[i]=false;
		}
		dist[S]=0;
		qu.push(mp(-0,S));
		while(!qu.empty()){
			int v;
			do{
				v=qu.top().Y;
				qu.pop();
			}while(!qu.empty() && done[v]);
			if(done[v])
				break;
			done[v]=true;
			forv(i,gr[v]){
				const edge & e = gr[v][i];
				int p=e.to;
				if(e.cap && !done[p] && dist[p]>dist[v]+e.cost){
					dist[p]=dist[v]+e.cost;
					prev[p]=mp(v,i);
					qu.push(mp(-dist[p]+P[p],p));
				}
			}
		}
		if(!done[T])
			return mp(0,0);
		
		int v=T;
		while(v!=S){
			edge & e1=gr[prev[v].X][prev[v].Y];
			edge & e2=gr[v][e1.back];
			--e1.cap;
			++e2.cap;
			v=prev[v].X;
		}
		
		forn(i,n){
			P[i]=dist[i];
		}
		
		return mp(1,dist[T]);
	}
	
	pair<int,double> mincost(){
		clr(P,0);
		
		int c=0;
		double res=0;
		while(true){
			pair<int,double> t=augment();
			if(!t.X)
				break;
			c+=t.X;
			res+=t.Y;
		}
		
		return mp(c,res);
	}
};

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	graph gr;
	int n;
	cin>>n;
	gr.n=n*2+2;
	gr.S=gr.n-2;
	gr.T=gr.n-1;
	vector<PDD> src(n);
	forn(i,n){
		cin>>src[i].X>>src[i].Y;
	}
	forn(i,n){
		gr.add(gr.S,i*2+0,1,0);
		gr.add(i*2+1,gr.T,2,0);
		forn(j,n){
			if(src[j].Y>src[i].Y)
				gr.add(i*2+0,j*2+1,1,sqrt(sqr(src[i].X-src[j].X)+sqr(src[i].Y-src[j].Y)));
		}
	}
	pair<int,double> t=gr.mincost();
	if(t.X==n-1)
		printf("%.15lf",t.Y);
	else
		cout<<-1;

	return 0;
}
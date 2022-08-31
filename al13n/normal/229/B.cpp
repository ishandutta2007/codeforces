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
typedef double ld;
typedef pair<int,int> PII;
typedef pair<ld,ld> PDD;
typedef pair<lng,lng> PLL;
typedef complex<double> com;
const ld PI=3.1415926535897932384626433832795;
const ld EPS=1e-3;
const int inf=1000000000;
const lng linf=1000000000000000000LL;
template<class T> inline T sqr(T x) { return x * x; }
int gcd(int a,int b){return a?gcd(b%a,a):b;}

vector<PII> gr[110000];
set<pair<int,lng> > bad;
lng dist[110000];
bool done[110000];
int n;

int main() {
#ifdef __ASD__
    freopen("input.txt","rt",stdin);freopen("output.txt","wt",stdout);
#endif
	
	int m;
	cin>>n>>m;
	forn(i,m){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		--a;--b;
		gr[a].pb(mp(b,c));
		gr[b].pb(mp(a,c));
	}
	forn(i,n){
		int k;
		scanf("%d",&k);
		forn(j,k){
			int a;
			scanf("%d",&a);
			bad.insert(mp(i,(lng)a));
		}
	}
	
	priority_queue<PII> qu;
	forn(i,n){
		dist[i]=linf;
	}
	dist[0]=0;
	qu.push(mp(-0,0));
	
	while(!qu.empty()){
		int v;
		do{
			v=qu.top().Y;
			qu.pop();
		}while(!qu.empty()&&done[v]);
		if(done[v])
			break;
		done[v]=true;
		lng d=dist[v];
		while(bad.count(mp(v,d)))
			++d;
		forv(i,gr[v]){
			int p=gr[v][i].X;
			int w=gr[v][i].Y;
			if(dist[p]>d+w){
				dist[p]=d+w;
				qu.push(mp(-dist[p],p));
			}
		}
	}
	
	if(dist[n-1]==linf)
		cout<<-1;
	else
		cout<<dist[n-1];
	
	return 0;
}
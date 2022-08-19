#pragma comment(linker,"/STACK:1024000000")
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
#include <cstdlib>
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
#define div asddiv
#define divides asddivides
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned lng ulng;
inline int mymax(int a,int b){return a<b?b:a;}
inline int mymin(int a,int b){return a>b?b:a;}
inline lng mymax(lng a,lng b){return a<b?b:a;}
inline lng mymin(lng a,lng b){return a>b?b:a;}
inline lng abs(lng a){return a<0?-a:a;}
#ifdef __ASD__
#define LOG(x) cerr<<x<<endl
#else
#define LOG(x)
#endif

int n,m;
vector<pair<int,int> > gr[110000];
int dsuu[110000];
lng dist[110000];
int comp[110000];
bool done[110000];
vector<pair<lng,PII> > gr2;

int get(int a){
	return dsuu[a]==a?a:dsuu[a]=get(dsuu[a]);
}
void merge(int a,int b){
	dsuu[get(a)]=get(b);
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	cin>>n>>m;
	priority_queue<pair<lng,int>,vector<pair<lng,int> >,greater<pair<lng,int> > > qu;
	forn(i,n){
		dist[i]=linf;
	}
	forn(i,m){
		int a,b,w;
		cin>>a>>b>>w;
		--a;--b;
		gr[a].pb(mp(b,w));
		gr[b].pb(mp(a,w));
	}
	int k;
	cin>>k;
	forn(i,k){
		int a;
		cin>>a;
		--a;
		dist[a]=0;
		qu.push(mp(0,a));
		comp[a]=i;
		dsuu[i]=i;
	}

	while(!qu.empty()){
		int v;
		do{
			v=qu.top().Y;
			qu.pop();
		}while(!qu.empty()&&done[v]);
		if(done[v])
			break;
		done[v]=true;
		forv(i,gr[v]){
			int p=gr[v][i].X;
			int w=gr[v][i].Y;
			if(done[p]){
				
				continue;
			}
			if(dist[v]+w<dist[p]){
				dist[p]=dist[v]+w;
				comp[p]=comp[v];
				qu.push(mp(dist[p],p));
			}
		}
	}
	forn(v,n){
		forv(i,gr[v]){
			int p=gr[v][i].X;
			int w=gr[v][i].Y;
			gr2.pb(mp(dist[v]+dist[p]+w,mp(comp[v],comp[p])));
		}
	}
	
	lng res=dist[0];
	sort(all(gr2));
	forv(i,gr2){
		int a=gr2[i].Y.X;
		int b=gr2[i].Y.Y;
		lng w=gr2[i].X;
		if(get(a)!=get(b)){
			merge(a,b);
			res+=w;
		}
	}

	cout<<res;

    return 0;
}
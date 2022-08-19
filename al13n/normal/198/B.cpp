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
#define fors(i,s) forn(i,(int)(s).length())
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define EQ(a,b) (fabs((a)-(b))<eps)
#define SQ(a) ((a)*(a))
#define index asdindex
#define prev asdprev
#define X first
#define Y second
#define unlink asdunlink
#define div asddiv
#define tr1 asdtr1
typedef unsigned char uchar;
typedef unsigned int uint;
typedef long long lng;
typedef pair<int,int> PII;
typedef pair<lng,lng> PLL;
typedef pair<double,double> PDD;
const int iinf=1000000000;
const lng linf=1000000000000000000LL;
const double dinf=1e200;
//const double eps=1e-8;
const double PI=3.14159265359;
inline int mymax(int a,int b){return a<b?b:a;}
inline int mymin(int a,int b){return a>b?b:a;}
inline lng mymax(lng a,lng b){return a<b?b:a;}
inline lng mymin(lng a,lng b){return a>b?b:a;}
inline lng myabs(lng a){return a<0?-a:a;}

int n,k;
char src[2][110000];
int dist[2][110000];
bool done[2][110000];

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	cin>>n>>k;
	gets(src[0]);
	gets(src[0]);
	gets(src[1]);

	forn(i,2)
		forn(j,n)
			dist[i][j]=iinf;
	priority_queue<pair<int,PII> > qu;
	dist[0][0]=0;
	qu.push(mp(-0,mp(0,0)));
	int res=iinf;
	while(!qu.empty()){
		int a,b;
		do{
			a=qu.top().Y.X;
			b=qu.top().Y.Y;
			qu.pop();
		}while(!qu.empty()&&done[a][b]);
		if(done[a][b])
			break;
		done[a][b]=true;
		int d=dist[a][b];
		if(b>=d+2&&d+1<dist[a][b-1]&&src[a][b-1]=='-'){
			dist[a][b-1]=d+1;
			qu.push(mp(-(d+1),mp(a,b-1)));
		}
		if(b>=n-k)
			res=min(res,d+1);
		else{
			if(d+1<dist[a][b+1]&&src[a][b+1]=='-'){
				dist[a][b+1]=d+1;
				qu.push(mp(-(d+1),mp(a,b+1)));
			}
			if(d+1<dist[1-a][b+k]&&src[1-a][b+k]=='-'){
				dist[1-a][b+k]=d+1;
				qu.push(mp(-(d+1),mp(1-a,b+k)));
			}
		}
	}

	cout<<(res==iinf?"NO":"YES");

    return 0;
}
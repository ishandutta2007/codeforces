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
#define y0 asdy0
typedef unsigned char uchar;
typedef unsigned int uint;
typedef long long lng;
typedef pair<int,int> PII;
typedef pair<lng,lng> PLL;
typedef pair<double,double> PDD;
const int iinf=1000000000;
const lng linf=1000000000000000000LL;
const double dinf=1e200;
const double eps=1e-16;
const double PI=3.14159265359;
inline int mymax(int a,int b){return a<b?b:a;}
inline int mymin(int a,int b){return a>b?b:a;}
inline lng mymax(lng a,lng b){return a<b?b:a;}
inline lng mymin(lng a,lng b){return a>b?b:a;}
inline lng myabs(lng a){return a<0?-a:a;}
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}

int n,m;

int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	//ios_base::sync_with_stdio(false);

	cin>>n>>m;
	lng sqx=0,sx=0,sqy=0,sy=0,sc=0;
	forn(i,n){
		forn(j,m){
			int c;
			scanf("%d",&c);
			lng x=j*4+2;
			lng y=i*4+2;
			sc+=c;
			sqx+=c*x*x;
			sx+=c*x;
			sqy+=c*y*y;
			sy+=c*y;
		}
	}

	pair<lng,PII> res(linf*4,mp(0,0));
	forn(i,n+1){
		forn(j,m+1){
			lng x=j*4;
			lng y=i*4;
			res=min(res,mp(sqx-2*x*sx+SQ(x)*sc+sqy-2*y*sy+SQ(y)*sc,mp(i,j)));
		}
	}

	cout<<res.X<<'\n'<<res.Y.X<<' '<<res.Y.Y;

	return 0;
}
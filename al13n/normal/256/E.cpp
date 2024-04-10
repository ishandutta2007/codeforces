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

const lng mod=777777777;

lng tree[1000000];

void init(int a,int b,int k){
	tree[k]=1;
	if(b==a+1)
		return;
	int c=(a+b)/2;
	init(a,c,k*2+1);
	init(c,b,k*2+2);
}
void setval(int p,lng v,int a,int b,int k){
	if(b==a+1){
		tree[k]=v;
		return;
	}
	int c=(a+b)/2;
	if(p<c)
		setval(p,v,a,c,k*2+1);
	else
		setval(p,v,c,b,k*2+2);
	tree[k]=tree[k*2+1]*tree[k*2+2]%mod;
}

lng dp[4][4][80000];
lng good[4][4];
int A[80000];
int n;

int main() {
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

	int m;
	cin>>n>>m;
	forn(i,3){
		forn(j,3){
			cin>>good[i+1][j+1];
		}
	}
	forn(i,3){
		forn(j,3){
			dp[i+1][j+1][1]=good[i+1][j+1];
		}
		good[0][i+1]=1;
		good[i+1][0]=1;
		dp[0][i+1][1]=1;
		dp[i+1][0][1]=1;
	}
	for(int d=1;d<=n+10;++d){
		forn(i,4){
			forn(j,4){
				forn(t,3){
					dp[i][j][d]=(dp[i][j][d]+dp[i][t+1][d-1]*good[t+1][j])%mod;
				}
			}
		}
	}

	init(0,n+2,0);
	set<int> pos;
	pos.insert(0);
	pos.insert(n+1);
	forn(qqq,m){
		int p,v;
		scanf("%d%d",&p,&v);
		
		set<int>::iterator a=pos.lower_bound(p);
		--a;
		set<int>::iterator b=pos.upper_bound(p);
		
		A[p]=v;
		
		if(v){
			setval(*a,dp[A[*a]][v][p-*a],0,n+2,0);
			setval(p,dp[v][A[*b]][*b-p],0,n+2,0);
		}else{
			setval(*a,dp[A[*a]][A[*b]][*b-*a],0,n+2,0);
			setval(p,1,0,n+2,0);
		}
		
		if(v)
			pos.insert(p);
		else
			pos.erase(p);
		
		printf("%d\n",(int)tree[0]);
	}

	return 0;
}
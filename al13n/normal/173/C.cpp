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
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
#define linf 1000000000000000000LL
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-10
#define EQ(a,b) (fabs((a)-(b))<eps)
#define SQ(a) ((a)*(a))
#define PI 3.14159265359
#define index asdindex
#define FI first
#define SE second
#define prev asdprev
#define PII pair<int,int> 
#define X first
#define Y second
#define unlink asdunlink
typedef unsigned char uchar;
typedef unsigned int uint;

int n,m;
int src[510][510];
int sum[510][510];
int res;

void dospiral(vector<PII> &sp,int a,int b){
	int s=src[a][b];
	forv(i,sp){
		int aa=a+sp[i].X;
		int bb=b+sp[i].Y;
		if(aa<0||aa>=n||bb<0||bb>=m)
			break;
		s+=sum[max(a,aa)+1][max(b,bb)+1]-sum[min(a,aa)][max(b,bb)+1]-sum[max(a,aa)+1][min(b,bb)]+sum[min(a,aa)][min(b,bb)]-src[a][b];
		a=aa;
		b=bb;
		if((i+1)%5==0)
			res=max(res,s);
	}
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	vector<PII> sp1,sp2;

	sp1.pb(mp(0,2));
	sp1.pb(mp(-2,0));
	sp1.pb(mp(0,-2));
	sp1.pb(mp(0,0));
	sp1.pb(mp(0,0));

	for(int l=6;l<=600;l+=4){
		sp1.pb(mp(0,-2));
		sp1.pb(mp(l-2,0));
		sp1.pb(mp(0,l));
		sp1.pb(mp(-l,0));
		sp1.pb(mp(0,-l));

		sp2.pb(mp(0,-2));
		sp2.pb(mp(l-4,0));
		sp2.pb(mp(0,l-2));
		sp2.pb(mp(-(l-2),0));
		sp2.pb(mp(0,-(l-2)));
	}

	cin>>n>>m;
	forn(i,n){
		forn(j,m){
			cin>>src[i][j];
			sum[i+1][j+1]=sum[i][j+1]+sum[i+1][j]-sum[i][j]+src[i][j];
		}
	}

	res=-iinf*2;

	forn(i,n){
		forn(j,m){
			dospiral(sp1,i,j);
			dospiral(sp2,i,j);
		}
	}

	cout<<res;

    return 0;
}
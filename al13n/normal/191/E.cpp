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
lng sum[110000];
lng tree[20][110000];

void build(int a,int b,int d){
	for(int i=a;i<b;++i)
		tree[d][i]=sum[i];
	if(b==a+1)
		return;
	sort(tree[d]+a,tree[d]+b);
	int c=(a+b)/2;
	build(a,c,d+1);
	build(c,b,d+1);
}

int cntless(lng v,int l,int r,int a,int b,int d){
	if(l==a&&r==b)
		return lower_bound(tree[d]+a,tree[d]+b,v)-tree[d]-a;
	int c=(a+b)/2;
	if(r<=c)
		return cntless(v,l,r,a,c,d+1);
	if(l>=c)
		return cntless(v,l,r,c,b,d+1);
	return cntless(v,l,c,a,c,d+1)+cntless(v,c,r,c,b,d+1);
}



int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	lng k;
	cin>>n>>k;
	forn(i,n){
		int a;
		cin>>a;
		sum[i+1]=sum[i]+a;
	}
	build(0,n,0);
	lng a=-iinf*1000000LL,b=iinf*1000000LL;
	while(b>a+1){
		lng v=(a+b)/2;
		lng cnt=0;
		for(int i=1;i<=n;++i){
			cnt+=cntless(sum[i]-v+1,0,i,0,n,0);
		}
		if(cnt>=k)
			a=v;
		else
			b=v;
	}
	cout<<a;

    return 0;
}
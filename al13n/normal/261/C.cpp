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
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}

lng dp[100][100];

lng doit(lng n,int k){
	if(!n)
		return 0;
	if(!k)
		return 1;
	int i=0;
	while((1LL<<(i+1))<=n)
		++i;
	lng r=dp[i][k];
	r+=doit(n-(1LL<<i),k-1);
	return r;
}

int main() {
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	
	dp[0][0]=1;
	for(int i=1;i<100;++i){
		for(int j=0;j<100;++j){
			dp[i][j]=dp[i-1][j];
			if(j)
				dp[i][j]+=dp[i-1][j-1];
		}
	}
	
	lng n,t;
	cin>>n>>t;
	++n;
	int k=0;
	while(!(t&(1LL<<k)))
		++k;
	if(t!=(1LL<<k)){
		cout<<0;
		return 0;
	}
	
	lng res=0;
	for(int i=0;n;++i){
		if((1LL<<i)<=n){
			n-=1LL<<i;
			res+=dp[i][k];
		}else{
			res+=doit(n,k);
			n=0;
		}
	}

	if(t==1)
		--res;
	cout<<res;

	return 0;
}
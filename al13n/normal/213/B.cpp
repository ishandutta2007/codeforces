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
#define pow10 asdpow10
#define pos asdpos
typedef unsigned char uchar;
typedef unsigned int uint;
typedef long long lng;
typedef unsigned long long ulng;
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

const lng mod=iinf+7;
lng dp[15][110];
int A[10];
lng C[110][110];
int n;
lng res;

void solve(){
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<=10;++i){
		for(int j=A[i-1];j<=n;++j){
			for(int k=A[i-1];k<=j;++k){
				dp[i][j]=(dp[i][j]+dp[i-1][j-k]*C[j][k])%mod;
			}
		}
	}
	forn(i,n)
		res=(res+dp[10][i])%mod;
}

int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	//ios_base::sync_with_stdio(false);

	forn(i,110){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;++j)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}

	cin>>n;
	forn(i,10)
		cin>>A[i];

	for(int i=1;i<10;++i){
		int v=A[i];
		if(A[i])
			--A[i];
		solve();
		A[i]=v;
	}

	cout<<res;

	return 0;
}
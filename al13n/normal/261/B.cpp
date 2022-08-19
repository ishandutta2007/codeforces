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

lng C[100][100];
lng dp[55][55][55];

double doit(vector<int> ar, int m){
	int n=sz(ar);
	clr(dp,0);
	dp[0][0][0]=1;
	forn(i,n){
		forn(j,i+1){
			forn(k,m+1){
				dp[i+1][j][k]+=dp[i][j][k];
				if(k+ar[i]<=m)
					dp[i+1][j+1][k+ar[i]]+=dp[i][j][k];
			}
		}
	}
	double res=0;
	forn(i,n+1){
		lng s=0;
		forn(j,m+1){
			s+=dp[n][i][j];
		}
		res+=1.*s/C[n][i]/(n+1);
	}
	if(res>1+1e-3)
		exit(32);
	return res;
}

int main() {
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	
	forn(i,100){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;++j){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	}

	int n;
	cin>>n;
	vector<int> v(n);
	forn(i,n){
		cin>>v[i];
	}
	int p;
	cin>>p;
	
	double res=0;
	forn(i,n){
		if(v[i]>p)
			continue;
		vector<int> vv=v;
		vv.erase(vv.begin()+i);
		res+=doit(vv,p-v[i]);
	}
	printf("%.15lf",res);

	return 0;
}
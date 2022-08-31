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
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
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

const int B=203;
double dp[210][410];
double P[210];
int A[210];

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	int n,L,K;
	cin>>n>>L>>K;
	forn(i,n){
		cin>>P[i];
		P[i]/=100;
	}
	forn(i,n){
		cin>>A[i];
	}
	dp[0][B+K]=1;
	forn(i,n){
		for(int l=i;l>=0;--l){
			forn(s,B*2+1){
				dp[l+1][max(0,min(B*2,s+A[i]))]+=dp[l][s]*P[i];
				dp[l][s]*=1-P[i];
			}
		}
	}

	double res=0;
	for(int l=L;l<=n;++l){
		for(int s=B;s<=2*B;++s){
			res+=dp[l][s];
		}
	}

	printf("%.15lf",res);

    return 0;
}
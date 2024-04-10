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
typedef unsigned char uchar;
typedef unsigned int uint;

char S[5100],T[5100];
int n,m;
const int mod=iinf+7;

uint dp[5010];

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	gets(S);
	gets(T);
	n=strlen(S);
	m=strlen(T);

	forn(i,n+1){
		dp[i]=1;
	}
	forn(i,m){
		for(int j=n-1;j>=0;--j){
			if(S[j]==T[i]){
				dp[j+1]+=dp[j];
				if(dp[j+1]>=mod)
					dp[j+1]-=mod;
			}
		}
	}

	uint res=0;
	forn(i,n+1){
		res=(0LL+res+dp[i]-1+mod)%mod;
	}

	cout<<res;

    return 0;
}
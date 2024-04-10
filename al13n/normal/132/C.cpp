#pragma comment(linker,"/STACK:256000000")
#include <vector>
#include <cstring>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <complex>
#include <memory.h>
using namespace std;
#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i=0;i<(n);++i)
#define fornn(i,n) for(i=0;i<(n);++i)
#define lng long long
#define SQ(a) ((a)*(a))
#define forv(i,v) for(int i=0;i<(int)v.size();++i)
#define mp make_pair
#define pb push_back
#define ABS(a) ((a)<0?-(a):(a))
#define iinf 1000000000
#define linf SQ(1LL*iinf)
#define left asdleft
#define prev asdprev
#define hash asdhash
#define div asddiv
#define time asdtime
#define eps 1e-9
#define y1 asdy1
#define y2 asdy2
#define EQ(a,b) abs((a)-(b))<eps
#define PI 3.1415926535897932384626433832795
#define DEG2RAD PI/180
#define ulng unsigned lng
const double dinf = 1e200;
void ext(int c){
#ifdef __ASD__
    exit(c);
#endif
}

char src[100000];
int n,m;
int dp[110][60][2];

#define taska "vigenere"
int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
    //freopen(taska".in","r",stdin);freopen(taska".out","w",stdout);
#endif

    //ios_base::sync_with_stdio(false);

	gets(src);
	cin>>m;
	n=strlen(src);
	
	int res=0;
	forn(d0,2){
		forn(i,m+1)
			forn(j,2)
				dp[0][i][j]=-iinf;
		dp[0][0][d0]=0;
		for(int p=1;p<=n;++p){
			for(int k=0;k<=m;++k){
				forn(d,2){
					dp[p][k][d]=-iinf;
					forn(kk,k+1){
						bool mv=src[p-1]=='F';
						if((kk-k)%2)
							mv=!mv;
						dp[p][k][d]=max(dp[p][k][d],dp[p-1][kk][d^!mv]+(mv?(d*2-1):0));
					}
				}
			}
		}
		res=max(res,dp[n][m][0]);
		res=max(res,dp[n][m][1]);
	}
	if(res<0)
		exit(123);
	cout<<res;

    return 0;
}
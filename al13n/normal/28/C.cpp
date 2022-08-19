#pragma comment(linker,"/STACK:256000000")
//#pragma comment(linker,"/STACK:536870912")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <cstring>
#include <ctime>
#include <memory.h>
using namespace std;

#define lng long long
#define PB push_back
#define pii pair<int,int>
#define MPII make_pair<int,int>
#define PLL pair<lng,lng>
#define MPLL make_pair<lng,lng>
#define PI 3.1415926535897932384626433832795
#define DEG2RAD (PI/180.0)
#define RAD2DEG (1.0/DEG2RAD)
#define pb push_back
#define mp make_pair
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define forn(i,n) for(int i=0;i<n;++i)
#define fornr(i,n) for(int i=n-1;i>=0;--i)
#define forn1(i,n) for(i=0;i<n;++i)
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define rep1(i,a,b) for(i=(a);i<(b);++i)
#define forv(i,v) for(int i=0;i<v.size();++i)
#define forvr(i,v) for(int i=v.size()-1;i>=0;--i)
#define fors(i,s) for(int i=0;i<s.length();++i)
#define EPS 1e-9
#define eps EPS
#define ABS(a) ((a)<0?-(a):(a))
#define EQ(a,b) (ABS((a)-(b))<EPS)
#define iinf 1000000000
#define linf 100000000000000000LL
#define maxll ((1LL<<62)-1+(1LL<<62))
#define dinf 10000000000000000000000.0
#define SQ(a) ((a)*(a))
#define SWAP(t,a,b) {t ____tmpasdasdasd=(a);(a)=(b);(b)=____tmpasdasdasd;}
#define left _left
#define y1 asdy1
#define y2 asdy2
#define y0 asdy0
#define abs(a) ((a)<0?-(a):(a))
#define mat _mat
#define ALL(a) (a).begin(),(a).end()
#ifdef __TRATATA__
#include "my.h"
#endif

double C[51][51];
double power[51][51];
int A[51];

double dp[51][51][51]; // [max max queue][rooms filled][ppl used]

int main(){
#ifdef __TRATATA__
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    forn(i,51){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;++j)
            C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
    forn(i,51){
        power[i][0]=1;
        for(int j=1;j<=50;++j)
            power[i][j]=power[i][j-1]*i;
    }

    int n,m;
    cin>>n>>m;
    forn(i,m)
        cin>>A[i];

    for(int q=0;q<=n;++q){
        dp[q][0][0]=1;
        for(int r=1;r<=m;++r){
            for(int p=0;p<=n;++p){
                for(int k=0;k<=p&&(k+A[r-1]-1)/A[r-1]<=q;++k){
                    double pr=C[n-p+k][k]/power[m-r+1][n-p+k]*power[m-r][n-p];
                    dp[q][r][p]+=pr*dp[q][r-1][p-k];
                }
            }
        }
    }
    double res=0;
    for(int q=1;q<=n;++q){
        double pr=dp[q][m][n]-dp[q-1][m][n];
        res+=pr*q;
    }
    printf("%.15lf",res);

    return 0;
}
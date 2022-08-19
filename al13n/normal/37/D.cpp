#pragma comment(linker,"/STACK:228000000")
#include <vector>
#include <string.h>
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

using namespace std;
#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i=0;i<n;++i)
#define fornr(i,n) for(int i=n-1;i>=0;--i)
#define lng long long
#define PI 3.1415926535897932384626433832795
#define SQ(a) ((a)*(a))
#define sqr(a) ((a)*(a))
#define VI vector<int>
#define VD vector<double>
#define VS vector<string>
#define forv(i,v) for(int i=0;i<(int)v.size();++i)
#define forvr(i,v) for(int i=(int)v.size()-1;i>=0;--i)
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define ABS(a) ((a)<0?-(a):(a))
#define EQ(a,b) (ABS((a)-(b))<eps)
#define iinf 1000000000
#define dinf 100000000000000000000.0
#define linf 1000000000000000000LL
#define y1 asdy1
#define y2 asdy2
#define DEG2RAD 0.01745329251994329576923690768489
#define eps 1e-12
#define prev asdprev
#define left asdleft
#define fixed asdfixed
#define time asdtime
#define free asdfree
inline lng abs(lng a){return a<0?-a:a;}
#ifdef __ASD__
//#include "my.h"
#endif

const lng mod=1000000007;
lng C[1100][110];

int x[110];
int y[110];
lng dp[110][1100];

int main()
{
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    forn(i,1100){
        C[i][0]=1;
        if(i<110)
            C[i][i]=1;
        for(int j=1;j<i&&j<110;++j)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }

    int n;
    cin>>n;
    int s=0;
    forn(i,n){
        cin>>x[i];
        s+=x[i];
    }
    forn(i,n)
        cin>>y[i];

    dp[n][0]=1;
    int sy=0;
    int sx=s;
    lng res=1;
    for(int p=n-1;p>=0;--p){
        sy+=y[p];
        res=(res*C[sx][x[p]])%mod;
        sx-=x[p];
        for(int k=0;k+x[p]<=sy&&k<=sx;++k){
            for(int j=0;j<=y[p]&&j<=k+x[p];++j){
                dp[p][k]=(dp[p][k]+dp[p+1][k+x[p]-j]*C[k+x[p]][j])%mod;
            }
        }
    }
    cout<<(res*dp[0][0])%mod;

    return 0;
}
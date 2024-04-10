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
#define left asdleft

string src;
int cost[26][26];
int dp[101][101][26];

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int k;
    cin>>src>>k;
    int m;
    cin>>m;
    forn(i,m){
        char a,b;
        int c;
        cin>>a>>b>>c;
        cost[a-'a'][b-'a']=c;
    }
    int n=src.length();
    forn(i,n+1)
        forn(j,k+1)
            forn(c,26)
                dp[i][j][c]=-iinf;
    forn(i,26)
        if(i!=src[0]-'a')
            dp[1][1][i]=0;
    dp[1][0][src[0]-'a']=0;
    for(int i=2;i<=n;++i){
        for(int j=0;j<=k;++j){
            int s=src[i-1]-'a';
            forn(p,26)
                dp[i][j][s]=max(dp[i][j][s],dp[i-1][j][p]+cost[p][s]);
            if(j)
                for(int c=0;c<26;++c){
                    if(c==s)
                        continue;
                    dp[i][j][c]=-iinf;
                    for(int p=0;p<26;++p)
                        dp[i][j][c]=max(dp[i][j][c],dp[i-1][j-1][p]+cost[p][c]);
                }
        }
    }
    int res=-iinf;
    forn(i,26)
        forn(j,k+1)
            res=max(res,dp[n][j][i]);
    cout<<res;

    return 0;
}
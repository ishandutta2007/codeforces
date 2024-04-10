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

char src[1100000];
int n;
pair<int,pair<int,int> > dp[1100000][3];

#define taska "vigenere"
int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
    //freopen(taska".in","r",stdin);freopen(taska".out","w",stdout);
#endif

    //ios_base::sync_with_stdio(false);

    gets(src);
    n=strlen(src);
    reverse(src,src+n);
    src[n++]='0';
    dp[0][1]=mp(0,mp(0,0));
    dp[0][0]=dp[0][2]=mp(iinf,mp(0,0));
    for(int i=1;i<=n;++i){
        forn(c,3){
            dp[i][c]=mp(iinf,mp(0,0));
            int v=src[i-1]-'0';
            forn(cc,3){
                forn(s,3){
                    int t=v+cc-1+s-1;
                    if((c-1)*2!=t)
                        continue;
                    dp[i][c]=min(dp[i][c],mp(dp[i-1][cc].first+abs(s-1),mp(cc,s-1)));
                }
            }
        }
    }
    cout<<dp[n][1].first<<endl;
    int c=1;
    for(int i=n;i>0;--i){
        if(dp[i][c].second.second)
            cout<<((dp[i][c].second.second>0)?'-':'+')<<"2^"<<i-1<<'\n';
        c=dp[i][c].second.first;
    }

    return 0;
}
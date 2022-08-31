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
#define eps 1e-10
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

lng gcd(lng a,lng b){
    return a?gcd(b%a,a):b;
}

int n;
bool src[2100][2100];
bool row[2100];
bool col[2100];
char line[2100];

#define taska "four"
int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
    //freopen(taska".in","r",stdin);freopen(taska".out","w",stdout);
#endif

    //ios_base::sync_with_stdio(false);

    cin>>n;
    memset(src,0,sizeof(src));
    gets(line);
    forn(i,n){
        gets(line);
        forn(j,n)
            src[i+1][j+1]=line[j]=='1';
    }

    int res=0;
    while(n){
        int r=0;
        for(int i=n-2;i>=0;--i){
            if((src[i][n]==row[i])!=(src[i+1][n]==row[i+1])){
                row[i+1]^=1;
                ++r;
            }
            if((src[n][i]==col[i])!=(src[n][i+1]==col[i+1])){
                col[i+1]^=1;
                ++r;
            }
        }
        if(!!(r%2)!=(src[n][n]!=row[n]!=col[n]))
            ++r;
        res+=r;
        --n;
    }
    cout<<res;

    return 0;
}
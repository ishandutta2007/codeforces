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
#define eps 1e-8
#define y1 asdy1
#define y0 asdy0
#define EQ(a,b) abs((a)-(b))<eps
#define PI 3.1415926535897932384626433832795
#define DEG2RAD PI/180
#define ulng unsigned lng
#define dinf = 1e200

int src[60][60];
int tmp[60][60];
int sum[60];
set<int> need;
int n,m;

int solve(){
    if(n<3)
        return 0;
    sum[0]=0;
    forn(i,n){
        sum[i+1]=sum[i];
        forn(j,m)
        sum[i+1]+=src[i][j];
    }
    int res=0;
    for(int i=1;i<n-1;++i)
        for(int j=i+1;j<n;++j){
            set<int> have;
            have.insert(sum[i]);
            have.insert(sum[j]-sum[i]);
            have.insert(sum[n]-sum[j]);
            if(have==need)
                ++res;
        }
    return res;
}

void transpose(){
    memcpy(tmp,src,sizeof(tmp));
    swap(n,m);
    forn(i,n)
        forn(j,m)
            src[i][j]=tmp[j][i];
}

#define taska ""
int main(int argc, char **argv){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
    //freopen(taska".in","r",stdin);freopen(taska".out","w",stdout);
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    
    ios_base::sync_with_stdio(false);
    
    cin>>n>>m;
    forn(i,n)
        forn(j,m)
            cin>>src[i][j];
    int a,b,c;
    cin>>a>>b>>c;
    need.insert(a);
    need.insert(b);
    need.insert(c);
    
    int res=solve();
    transpose();
    res+=solve();
    cout<<res;
    
    return 0;
}
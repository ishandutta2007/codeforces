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
const lng B = 47;
lng powb[1100000];
char src[1100000];
lng hash[1100000];

bool equal(int a,int b,int l){
    if(b<a)
        swap(a,b);
    lng h1=hash[a+l]-hash[a];
    lng h2=hash[b+l]-hash[b];
    return h1*powb[b-a]==h2;
}

int lcp(int a,int b){
    if(b<a)
        swap(a,b);
    int l1=0,l2=n-b+1;
    while(l2>l1+1){
        int l=(l1+l2)/2;
        if(equal(a,b,l))
            l1=l;
        else
            l2=l;
    }
    return l1;
}

#define taska "four"
int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
    //freopen(taska".in","r",stdin);freopen(taska".out","w",stdout);
#endif

    //ios_base::sync_with_stdio(false);

    gets(src);
    n=strlen(src);
    powb[0]=1;
    forn(i,n+10)
        powb[i+1]=powb[i]*B;
    hash[0]=0;
    forn(i,n)
        hash[i+1]=hash[i]+src[i]*powb[i];
    int maxl=0;
    for(int i=1;i<n-1;++i)
        maxl=max(maxl,min(lcp(0,i),n-i-1));

    for(int i=maxl;i>=1;--i)
        if(equal(0,n-i,i)){
            src[i]=0;
            cout<<src;
            return 0;
        }
    cout<<"Just a legend";

    return 0;
}
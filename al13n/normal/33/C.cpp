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
inline lng abs(lng a){return a<0?-a:a;}
#ifdef __ASD__
//#include "my.h"
#endif

int ar[1000000];
int res1[1000000],res2[1000000];
int n;

void solve(int *res){
    res[0]=0;
    int s=0;
    for(int i=1;i<=n;++i){
        s+=ar[i-1];
        res[i]=max(res[i-1]+ar[i-1],-s);
    }
}

#define filename "" 
int main()
{
#ifdef __ASD__
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    cin>>n;
    forn(i,n)
        scanf("%d",ar+i);
    solve(res1);
    reverse(ar,ar+n);
    solve(res2);
    int res=0;
    forn(i,n+1)
        res=max(res,res1[i]+res2[n-i]);
    cout<<res;

    return 0;
}
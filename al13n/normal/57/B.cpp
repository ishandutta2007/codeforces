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
#include <limits>
using namespace std;
#define forn(i,n) for(int i=0;i<n;++i)
#define fornr(i,n) for(int i=(n)-1;i>=0;--i)
#define forv(i,v) forn(i,(int)v.size())
#define time asdtime
#define pb push_back
#define lng long long
#define mp make_pair
#define iinf 1000000000
#define prev asdprev
#define next asdnext
#define all(v) v.begin(),v.end()
#define SQ(a) ((a)*(a))
#define eps 1e-8
#define y1 asdy1
#define y2 asdy2

lng dc[110000];
lng ds[110000];
lng res[110000];
int n;

int main(int argc,char **argv){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int m,k;
    cin>>n>>m>>k;
    forn(i,m){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        --a;
        ++dc[a];
        --dc[b];
        ds[a]+=c-a;
        ds[b]-=c-a;
    }
    lng c=0,s=0;
    forn(i,n){
        c+=dc[i];
        s+=ds[i];
        res[i]=c*i+s;
    }
    lng r=0;
    forn(i,k){
        int p;
        scanf("%d",&p);
        --p;
        r+=res[p];
    }
    cout<<r;

    return 0;
}
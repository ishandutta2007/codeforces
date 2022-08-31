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
//#ifdef __ASD__
//#include <windows.h>
//#endif
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
#define prev asdprev
#define eps 1e-10

int src[1000000];
int n;

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    cin>>n;
    int l=0;
    int p=iinf+2;
    lng res=0;
    forn(i,n){
        int v;
        scanf("%d",&v);
        if(v==p)
            ++l;
        else{
            res+=1LL*l*(l+1)/2;
            p=v;
            l=1;
        }
    }
    res+=1LL*l*(l+1)/2;

    cout<<res;

    return 0;
}
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

int A,B,K;
bool unprime[100000];
vector<int> primes;

lng doit(lng a,lng v){
    lng res=B/v-A/v;
    for(int i=a;;++i){
        lng t=v*primes[i];
        if(primes[i]>=K||t>B)
            break;
        res-=doit(i+1,t);
    }
    return res;
}

int brute(int a,int b,int k){
    int r=0;
    for(int v=a;v<=b;++v){
        bool g=true;
        if(v%k)
            continue;
        for(int i=2;i<k;++i)
            if(v%i==0){
                g=false;
                break;
            }
        if(g)
            ++r;
    }
    return r;
}

int solve(int a,int b,int k){
    A=a;
    B=b;
    K=k;
    for(int i=2;i*i<=K;++i)
        if(K%i==0){
            return 0;
        }

    --A;
    B/=K;
    A/=K;
    return doit(0,1);
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    for(int i=2;i<100000;++i){
        if(unprime[i])
            continue;
        primes.pb(i);
        for(int j=i+i;j<100000;j+=i)
            unprime[j]=true;
    }

    /*forn(qqq,10000){
        int a,b,k;
        a=rand()%20+1;
        b=a+rand()%20;
        k=rand()%20+1;
        int p,q;
        p=solve(a,b,k);
        q=brute(a,b,k);
        if(p!=q)
            cout<<a<<' '<<b<<' '<<k<<endl;
        p=solve(a,b,k);
        q=brute(a,b,k);
    }*/

    cin>>A>>B>>K;

    cout<<solve(A,B,K);

    return 0;
}
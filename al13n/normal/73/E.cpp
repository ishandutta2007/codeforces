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

bool unprime[650000];
vector<int> primes;

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    primes.pb(2);
    for(int i=1;i<650000;++i){
        if(unprime[i])
            continue;
        primes.pb(i*2+1);
        int t;
        for(int j=1;(t=2*i*j+i+j)<650000;++j)
            unprime[t]=true;
    }
    
    int n,x;
    cin>>n>>x;
    set<int> st;
    forn(i,n){
        int t;
        cin>>t;
        st.insert(t);
    }

    if(st.count(1)){
        cout<<(x==2?0:1);
        return 0;
    }

    int res=0;
    for(int i=0;i<primes.size()&&primes[i]<x;++i)
        if(st.count(primes[i]))
            ++res;
        else{
            res=-1;
            break;
        }
    cout<<res;

    return 0;
}
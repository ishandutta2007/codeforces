#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")

#ifdef __APPLE__
# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_map>
# include <unordered_set>
# include <thread>
#else
# include <bits/stdc++.h>
#endif

#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int max_n = 1e6+10, inf = 1000111222;
const int md=1e9+7;

void inc(int& a,int b)
{
    a+=b;
    if (a>=md){
        a-=md;
    }
}

int bpow(int a,int n)
{
    int res=1;
    while (n){
        if (n&1){
            res=1ll*res*a%md;
        }
        n/=2;
        a=1ll*a*a%md;
    }
    return res;
}

int f[max_n];
int rf[max_n];

int C(int n,int k)
{
    return 1ll*f[n]*rf[k]%md*rf[n-k]%md;
}

int rozkid(int x,int y)
{
    return C(x+y-1,y-1);
}

int CC(int n,int x,int k)
{
    if (n-x<1ll*(x-1)*(k-1)){
        return 0;
    }
    int rest = n-x-(x-1)*(k-1);
    return rozkid(rest,x+1);
}

void solve()
{
    int n,k;
    cin>>n>>k;

    int res=0;
    auto lol=[&](int x)
    {
        return 1ll*f[x]*CC(n,x,k)%md*f[n-x]%md*rf[n]%md;
    };
    for (int x=1;x<n;x++){
        inc(res,1ll*x*((lol(x)-lol(x+1)+md)%md)%md);
    }
    inc(res,1);
    cout<<res<<"\n";
}

void ___main___()
{
    f[0]=1;
    for (int i=1;i<max_n;i++){
        f[i]=1ll*f[i-1]*i%md;
    }
    rf[max_n-1]=bpow(f[max_n-1],md-2);
    for (int i=max_n-2;i>=0;i--){
        rf[i]=1ll*rf[i+1]*(i+1)%md;
    }
    int test;
    cin>>test;
    while (test--){
        solve();
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ___main___();

    exit(0);
}
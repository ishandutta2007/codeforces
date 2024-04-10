//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")

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

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
///#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;
const ll inf=1e18+10;

///---program start---///

#define arr (int)(1e6+10)

int bpow(int a,int n)
{
    a%=md;
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

int n,p;
int a[arr];

int get_mult_pow(int p,int step)
{
    ll res=1;
    while (res<n && step>0){
        step--;
        res=res*p;
    }
    return min(res,1ll*n);
}

int mult_diff(int diff,int m)
{
    return min(1ll*diff*m, 1ll*n);
}

void solve()
{
    cin>>n>>p;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    reverse(a,a+n);

    int diff=1;
    int ans=bpow(p,a[0]);

    for (int i=1;i<n;i++){
//        cout<<i<<" "<<a[i]<<" "<<diff<<" "<<ans<<"\n";
        if (p>1){
            diff=mult_diff(diff,get_mult_pow(p,a[i-1]-a[i]));
        }
        if (diff==0){
            diff=1;

            ans+=bpow(p,a[i]);
            if (ans>=md){
                ans-=md;
            }
        }
        else{
            diff--;

            ans-=bpow(p,a[i]);
            if (ans<0){
                ans+=md;
            }
        }
    }
    cout<<ans<<"\n";
}

signed main()
{
    #ifdef __APPLE__
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}
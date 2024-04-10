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

int a[arr];

void solve()
{
    int n,k;
    cin>>n>>k;
    bool any_k=0;
    for (int i=0;i<n;i++){
        cin>>a[i];
        a[i]=(a[i]>k ? 2 : (a[i]==k ? 1 : 0));

        any_k|=(a[i]==1);
    }

    bool flag=0;
    for (int l=2;l<=3;l++){
        for (int i=0;i+l-1<n;i++){
            int cnt_0=0;
            for (int j=0;j<l;j++){
                cnt_0+=(a[i+j]==0);
            }
            if (cnt_0<=(l==2 ? 0 : 1)){
                flag=1;
            }
        }
    }

    bool ans_yes = any_k && (n==1 || flag);

    cout<<(ans_yes ? "yes" : "no")<<"\n";
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
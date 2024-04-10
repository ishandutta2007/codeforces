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
#define int long long

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

#define md (int)(998244353ll)

#define ar (int)(3000+10)

void inc(int& a,int b)
{
    a+=b;
    if (a>=md){
        a-=md;
    }
}

int dp[ar][ar];

signed main()
{
    #ifdef __APPLE__
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    string s,t;
    cin>>s>>t;
    int n=len(s);
    int m=len(t);
    for (int i=0;i<=n-m;i++){
        dp[i][0]=1;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<=i;j++){
            if (1) { /// not left
                int cur_pos_in_res = j + (n - i - 1);
                if (cur_pos_in_res < m && s[n - i - 1] != t[cur_pos_in_res]) {

                }
                else{
                    inc(dp[i + 1][j], dp[i][j]);
                }
            }
            if (1) { /// left
                int cur_pos_in_res = j;
                if (cur_pos_in_res < m && s[n - i - 1] != t[cur_pos_in_res]) {

                }
                else{
                    inc(dp[i + 1][j+1], dp[i][j]);
                }
            }
        }
    }
//    for (int i=0;i<=n;i++){
//        for (int j=0;j<=i;j++){
//            cout<<"dp["<<i<<"]["<<j<<"] :: "<<dp[i][j]<<"\n";
//        }
//    }
    int ans=0;
    for (int i=0;i<=n;i++){
        inc(ans,dp[n][i]);
    }
    cout<<ans<<"\n";
}
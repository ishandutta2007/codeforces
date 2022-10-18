//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")

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

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = 5e4+10, inf = 1000111222;

void maximize(int& a,int b)
{
    if (a<b){
        a=b;
    }
}

int a[max_n];
int dp[max_n][3];

void solve()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int x;
    cin>>x;

    auto ok=[&](int l,int r)
    {
        int sum=0;
        for (int i=r;i>=l;i--){
            sum+=a[i];
            if (i!=r && sum<x*(r-i+1)){
                return 0;
            }
        }
        return 1;
    };

    for (int i=0;i<max_n;i++){
        for (int j=0;j<3;j++){
            dp[i][j]=-inf;
        }
    }
    dp[0][0]=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<3;j++){
            if (dp[i][j]!=-inf){
                /// not take
                maximize(dp[i+1][0],dp[i][j]);
                /// take
                if (ok(i+1-j,i+1)){
                    maximize(dp[i+1][min(2,j+1)],dp[i][j]+1);
                }
            }
        }
    }
    cout<<*max_element(dp[n],dp[n]+3)<<"\n";
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}
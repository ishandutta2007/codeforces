#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")    // WINDOWS ONLY

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

const int max_n = 2000+10, inf = 1000111222;

bitset<2*max_n> dp[2][2*max_n];

int a[2*max_n];

const bool debug=0;

void solve()
{
    int n;
    if (debug){
        n=2000;
        for (int i=0;i<2*n;i++){
            a[i]=i;
        }
    }
    else{
        cin>>n;
        for (int i=0;i<2*n;i++){
            cin>>a[i];
        }
    }
    a[2*n]=inf;
    for (int i=0;i<=2*n;i++){
        dp[0][i].reset();
        dp[1][i].reset();
    }
    dp[0][0][max_n+0]=1;
    for (int i=0;i<2*n;i++){
        int cur_max=-inf;
        for (int j=i;j>=0;j--){
            cur_max=max(cur_max,a[j]);
            if (cur_max<a[i+1]){
                int l=i-j+1;
//                cout<<"go "<<j<<" "<<i+1<<" "<<l<<"\n";
                dp[1][i+1]|=(dp[0][j]<<l);
                dp[0][i+1]|=(dp[1][j]>>l);
            }
        }
    }
    cout<<(dp[0][2*n][max_n+0] || dp[1][2*n][max_n+0]? "YES" : "NO")<<"\n";
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}
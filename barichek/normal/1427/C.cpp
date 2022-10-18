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

const int max_n = 1e5+10, inf = 1000111222;

int pref_dp[max_n];
int dp[max_n];
int t[max_n];
int x[max_n];
int y[max_n];

const int NAIVE=1000;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n>>n;

    t[1]=0;
    x[1]=1;
    y[1]=1;
    dp[1]=0;
    pref_dp[1]=0;
    for (int i=2;i<=n+1;i++){
        cin>>t[i]>>x[i]>>y[i];
    }
    for (int i=2;i<=n+1;i++){
        int max_dp_left=-1e9;
        for (int j=max(1,i-NAIVE);j<i;j++){
            if (t[i]-t[j]>=abs(x[i]-x[j])+abs(y[i]-y[j])){
                max_dp_left=max(max_dp_left,dp[j]);
            }
        }
        if (i-NAIVE>1){
            max_dp_left=max(max_dp_left,pref_dp[i-NAIVE-1]);
        }
        dp[i]=max_dp_left+1;
//        cout<<"dp["<<i<<"] :: "<<dp[i]<<"\n";

        pref_dp[i]=max(pref_dp[i-1],dp[i]);
    }
    cout<<pref_dp[n+1]<<"\n";
}
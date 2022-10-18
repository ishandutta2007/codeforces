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

const int max_n = 100+10, inf = 1000111222;

int dp[2][max_n];

void minimize(int& a,int b)
{
    if (a>b){
        a=b;
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    cin>>test;
    while (test--){
        int n,K;
        cin>>n>>K;
        map<int,int> cnt;
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            cnt[a]++;
        }
        int q1=0,q2=1;
        for (int i=0;i<max_n;i++){
            dp[q1][i]=inf;
        }
        dp[q1][0]=0;

        for (auto i:cnt){
            for (int i=0;i<max_n;i++){
                dp[q2][i]=inf;
            }
            for (int have=0;have<max_n;have++){
                if (dp[q1][have]!=inf){
                    for (int j=0;j<=i.sec;j++){
                        int additional_cost=(j<=K ? 0 : j-K);
                        minimize(dp[q2][have+j],dp[q1][have] + i.fir*(i.sec-j) + additional_cost);
                    }
                }
            }
            swap(q1,q2);
        }

        cout<<dp[q1][2*K]<<"\n";
    }
}
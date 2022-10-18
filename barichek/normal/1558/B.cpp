#pragma GCC optimize("Ofast", "unroll-loops")
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

const int max_n = 4e6+10, inf = 1000111222;

int md;

void inc(int& a,int b)
{
    a+=b;
    if (a>=md){
        a-=md;
    }
}

int dp[max_n];
int to_add_suf[max_n];

void add_on_seg(int l,int r,int value)
{
    if (l<max_n){
        inc(to_add_suf[l],value);
    }
    if (r+1<max_n){
        inc(to_add_suf[r+1],md-value);
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d%d",&n,&md);

    int cur_to_add=0;
    dp[1]=1;
    for (int i=1;i<=n;i++){
        inc(cur_to_add,to_add_suf[i]);
        inc(dp[i],cur_to_add);
        for (int j=2;j*i<max_n;j++){
            add_on_seg(i*j,i*j+j-1,dp[i]);
        }
        add_on_seg(i+1,max_n-1,dp[i]);
    }
    cout<<dp[n]<<"\n";
}
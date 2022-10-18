//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4")

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

#if __APPLE__
#define D for (bool _FLAG = true; _FLAG; _FLAG = false)
#define LOG(...) print(#__VA_ARGS__" ::", __VA_ARGS__) << endl
template <class ...Ts> auto &print(Ts ...ts) { return ((cerr << ts << " "), ...); }
#else
#define D while (false)
#define LOG(...)
#endif

const int max_n = 100+10, inf = 1000111222;

int n;
int a[max_n];
int dp[max_n];

bool buf[max_n];

int get_cost_buf()
{
    int res=0;
    while (buf[res]){
        res++;
    }
    return res;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    cin>>test;
    while (test--){
        cin>>n;
        for (int i=0;i<n;i++){
            cin>>a[i];
            a[i]=min(a[i],max_n-1);
        }
        ll ans=0;
        for (int start=0;start<n;start++){
            dp[start]=0;
            for (int i=start+1;i<=n;i++){
                dp[i]=-inf;
                memset(buf,0,sizeof(buf));
                for (int j=i-1;j>=start;j--){
                    buf[a[j]]=1;
                    dp[i]=max(dp[i],dp[j]+get_cost_buf()+1);
                }
                ans+=dp[i];
            }
        }
        cout<<ans<<"\n";
    }
}
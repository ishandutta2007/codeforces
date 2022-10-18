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

const int max_n = 5e5+10, inf = 1000111222;
const int md=1e9+7;

void inc(int& a,int b)
{
    a+=b;
    if (a>=md){
        a-=md;
    }
}

int cnt[60];
ll a[max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    scanf("%d",&test);
    while (test--){
        memset(cnt,0,sizeof(cnt));
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++){
            scanf("%lld",&a[i]);
//            cout<<a[i]<<" !!\n";
            for (int j=0;j<60;j++){
                if (a[i]&(1ll<<j)){
                    cnt[j]++;
                }
            }
        }

        auto get_sum_or_md=[&](ll val)
        {
            int res=0;
            for (int j=0;j<60;j++){
                if (val&(1ll<<j)){
                    inc(res,1ll* (1ll<<j)%md * n%md);
                }
                else{
                    inc(res,1ll* (1ll<<j)%md * cnt[j]%md);
                }
            }
            return res;
        };

        auto get_sum_and_md=[&](ll val)
        {
            int res=0;
            for (int j=0;j<60;j++){
                if (val&(1ll<<j)){
                    inc(res,1ll* (1ll<<j)%md * cnt[j]%md);
                }
                else{
                    inc(res,0);
                }
            }
            return res;
        };

        int ans=0;
        for (int i=0;i<n;i++){
            int sum_or=get_sum_or_md(a[i]);
            int sum_and=get_sum_and_md(a[i]);
            inc(ans,1ll* sum_or%md *sum_and%md);
        }
        cout<<ans<<"\n";
    }
}
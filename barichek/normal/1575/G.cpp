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

const int max_n = 1e5+10, inf = 1000111222;

const int md=1e9+7;

void inc(int& a,int b)
{
    a+=b;
    if (a>=md){
        a-=md;
    }
}

int a[max_n];
int ans[max_n];

int buf[max_n];
int buf_sz;

int buf_dp[max_n];
int cur_have[max_n];

int get_sum_gcd_of_buf()
{
    const int magic=300;
    if (buf_sz<=magic){
        int res=0;
        for (int i=0;i<buf_sz;i++){
            inc(res,buf[i]);
            for (int j=i+1;j<buf_sz;j++){
                inc(res,2*__gcd(buf[i],buf[j]));
            }
        }
        return res;
    }
    else{
        memset(cur_have,0,sizeof(cur_have));
        for (int i=0;i<buf_sz;i++){
            cur_have[buf[i]]++;
        }
        int res=0;
        for (int i=max_n-1;i>=1;i--){
            int cnt=0;
            for (int j=i;j<max_n;j+=i){
                cnt+=cur_have[j];
            }
            buf_dp[i]=1ll*cnt*cnt%md;
            for (int j=2*i;j<max_n;j+=i){
                inc(buf_dp[i],md-buf_dp[j]);
            }

            inc(res,1ll*buf_dp[i]*i%md);
        }
        return res;
    }
}

const bool gen=0;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    if (gen){
        n=1e5;
    }
    else{
        scanf("%d",&n);
    }
    for (int i=1;i<=n;i++){
        if (gen){
            a[i]=1+rand()%n;
        }
        else{
            scanf("%d",&a[i]);
        }
    }
    
    // auto naive=[&]()
    // {
    //     int res=0;
    //     for (int i=1;i<=n;i++){
    //         for (int j=1;j<=n;j++){
    //             inc(res,1ll*__gcd(a[i],a[j])*__gcd(i,j)%md);
    //         }
    //     }
    //     return res;
    // };
    
    // cout<<"naive :: "<<naive()<<"\n";

    int answer=0;
    for (int i=max_n-1;i>=1;i--){
        buf_sz=0;
        for (int j=i;j<=n;j+=i){
            buf[buf_sz++]=a[j];
        }
        ans[i]=get_sum_gcd_of_buf();
        for (int j=2*i;j<max_n;j+=i){
            inc(ans[i],md-ans[j]);
        }

        inc(answer,1ll*ans[i]*i%md);
    }
    cout<<answer<<"\n";
}
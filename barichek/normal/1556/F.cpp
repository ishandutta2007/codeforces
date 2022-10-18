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

const int max_n = 14, inf = 1000111222;
const int md=1e9+7;

int bpow(int a,int n)
{
    int res=1;
    while (n){
        if (n&1){
            res=1ll*res*a%md;
        }
        n/=2;
        a=1ll*a*a%md;
    }
    return res;
}

int inv(int a)
{
    return bpow(a,md-2);
}

void inc(int& a,int b)
{
    a+=b;
    if (a>=md){
        a-=md;
    }
}

bool get_bit(int mask,int bit)
{
    return (mask>>bit)&1;
}

const int max_states = 4782969; // 3**14

int a[max_n];

int edge[max_n][max_n];

int dp[max_states];

int win_on_mask[max_n][1ll<<max_n];
int lose_on_mask[max_n][1ll<<max_n];
//int win_and_lose[max_n][max_states];

int pow3[max_n];
int pow3_zeroes_to_ones[1ll<<max_n];

int buf[max_n];

const bool debug=0;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    pow3[0]=1;
    for (int i=1;i<max_n;i++){
        pow3[i]=pow3[i-1]*3;
    }

    for (int mask=0;mask<(1ll<<max_n);mask++){
        for (int i=0;i<max_n;i++){
            if (get_bit(mask,i)){
                pow3_zeroes_to_ones[mask]+=pow3[i];
            }
        }
    }

    int n;
    if (debug){
        n=14;
        for (int i=0;i<n;i++){
            a[i]=1+rand()%(1000000);
        }
    }
    else{
        cin>>n;
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (i!=j){
                edge[i][j]=1ll*a[i]*inv(a[i]+a[j])%md;
            }
        }
    }

    for (int i=0;i<n;i++){
        for (int mask=0;mask<(1ll<<n);mask++){
            if (!get_bit(mask,i)){
                int cur=1;
                for (int j=0;j<n;j++){
                    if (get_bit(mask,j)){
                        cur=1ll*cur*edge[i][j]%md;
                    }
                }
                win_on_mask[i][mask]=cur;
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int mask=0;mask<(1ll<<n);mask++){
            if (!get_bit(mask,i)){
                int cur=1;
                for (int j=0;j<n;j++){
                    if (get_bit(mask,j)){
                        cur=1ll*cur*edge[j][i]%md;
                    }
                }
                lose_on_mask[i][mask]=cur;
            }
        }
    }
//    for (int i=0;i<n;i++){
//        int pow3n=1;
//        for (int i=0;i<n;i++){
//            pow3n*=3;
//        }
//        assert(pow3n<=max_states);
//        for (int state=0;state<pow3n;state++){
//            int cur=state;
//            for (int j=0;j<n;j++){
//                buf[j]=cur%3;
//                cur/=3;
//            }
//
//            cur=1;
//            for (int j=0;j<n;j++){
//                if (buf[j]==1){
//                    cur=1ll*cur*edge[i][j]%md;
//                }
//                else if (buf[j]==2){
//                    cur=1ll*cur*edge[j][i]%md;
//                }
//            }
//
//            win_and_lose[i][state]=cur;
//        }
//    }

    for (int i=0;i<n;i++){
        inc(dp[pow3[i]],1);
    }

    auto calc_dp=[&]()
    {
        int pow3n=1;
        for (int i=0;i<n;i++){
            pow3n*=3;
        }
        assert(pow3n<=max_states);

        for (int state=0;state<pow3n;state++){
            int cur=state;
            for (int j=0;j<n;j++){
                buf[j]=cur%3;
                cur/=3;
            }
//            cout<<"dp[";
//            for (int j=0;j<n;j++){
//                cout<<buf[j];
//            }
//            cout<<"] = "<<dp[state]<<"\n";

            int first_to_take=0;
            while (first_to_take<n && buf[first_to_take]!=1){
                first_to_take++;
            }
            if (first_to_take==n){
                continue;
            }

            int zeroes_mask=0;
            for (int j=0;j<n;j++){
                if (buf[j]==0){
                    zeroes_mask+=(1ll<<j);
                }
            }

            for (int mask_to_win=zeroes_mask;;mask_to_win=(mask_to_win-1)&zeroes_mask){
                inc(dp[state+pow3_zeroes_to_ones[mask_to_win|(1ll<<first_to_take)]],1ll*dp[state]*win_on_mask[first_to_take][mask_to_win]%md*lose_on_mask[first_to_take][zeroes_mask^mask_to_win]%md);
//                inc(dp[state+pow3_zeroes_to_ones[mask_to_win|(1ll<<first_to_take)]],1ll*dp[state]*win_and_lose[first_to_take][pow3_zeroes_to_ones[mask_to_win]+2*pow3_zeroes_to_ones[zeroes_mask^mask_to_win]]%md);

                if (mask_to_win==0){
                    break;
                }
            }
        }
    };

    calc_dp();

    cout<<dp[2*pow3_zeroes_to_ones[(1ll<<n)-1]]<<"\n";
}
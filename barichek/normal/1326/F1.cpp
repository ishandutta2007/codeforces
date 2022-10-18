#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC optimize("unroll-loops")

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
#include <bits/stdc++.h>
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
///#define int long long

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

const int N=14;

bool reb[N][N];
int mask_edges[N];

ll ans[(1ll<<N)];

int p1[N];
int p2[N];

int cnt_on_right[1ll<<(N/2)][N];
int sub_sum_right[1ll<<(N/2)][1ll<<N];
int max_bit_id[1ll<<N];

int cur_mask_value[1ll<<N];

int left_cnt[1ll<<(N/2)][N];

signed main()
{
#ifdef __APPLE__
    files("barik");
        freopen("debug.txt","w",stderr);
#endif

    fast;

    for (int i=0;i<(1ll<<N);i++){
        for (int j=0;j<N;j++){
            if (i&(1ll<<j)){
                max_bit_id[i]=j;
            }
        }
    }

    int n;
       cin>>n;
//    n=N;
    for (int i=0;i<n;i++){
        string s="";
          cin>>s;
//        for (int j=0;j<n;j++){
//            s+=char('0'+rand()%2);
//        }
        for (int j=0;j<n;j++){
            reb[i][j]=(s[j]=='1');
            if (reb[i][j]){
                mask_edges[i]|=(1ll<<j);
            }
        }
    }

    int cnt_left=n/2;
    int cnt_right=n-cnt_left;

    for (int left_sub=0;left_sub<(1ll<<n);left_sub++){
        if (__builtin_popcountll(left_sub)==cnt_left){
            int right_sub=((1ll<<n)-1)^left_sub;

            /// make move
            int sz1=0;
            int sz2=0;
            for (int i=0;i<n;i++){
                if (left_sub&(1ll<<i)){
                    p1[sz1++]=i;
                }
                else{
                    p2[sz2++]=i;
                }
            }

            memset(cnt_on_right,0,sizeof(cnt_on_right));

            sort(p2,p2+sz2);
            do{
                int cur_mask=0;
                for (int j=0;j+1<sz2;j++){
                    if (reb[p2[j]][p2[j+1]]){
                        cur_mask|=(1ll<<j);
                    }
                }
                cnt_on_right[cur_mask][p2[0]]++;
            }
            while(next_permutation(p2,p2+sz2));
            sort(p2,p2+sz2);

            for (int m=0;m<(1ll<<sz2);m++){
                cur_mask_value[m]=0;
                for (int j=0;j<sz2;j++){
                    if (m&(1ll<<j)){
                        cur_mask_value[m]|=(1ll<<p2[j]);
                    }
                }
            }

            /// calc sub_sum_right
            for (int mask=0;mask<(1ll<<(sz2-1));mask++){
                for (int mm=1;mm<(1ll<<sz2);mm++){
                    int lols=cur_mask_value[mm];
                    int from = lols^(1ll<<max_bit_id[lols]);
                    sub_sum_right[mask][lols]=sub_sum_right[mask][from]+cnt_on_right[mask][p2[max_bit_id[mm]]];
                }
            }

            memset(left_cnt,0,sizeof(left_cnt));

            sort(p1,p1+sz1);
            do{
                int cur_mask=0;
                for (int j=0;j+1<sz1;j++){
                    if (reb[p1[j]][p1[j+1]]){
                        cur_mask|=(1ll<<j);
                    }
                }
                left_cnt[cur_mask][p1[sz1-1]]++;
            }
            while(next_permutation(p1,p1+sz1));
            sort(p1,p1+sz1);

            for (int mask_right=0;mask_right<(1ll<<(sz2-1));mask_right++) {
                for (int cur_mask=0;cur_mask<(1ll<<(sz1-1));cur_mask++){
                    for (int last_guy=0;last_guy<n;last_guy++){
                        ll rem_value = left_cnt[cur_mask][last_guy];
                        int guys_mask = mask_edges[last_guy];
                        guys_mask &= right_sub;
                        int rev_guys_mask = ((1ll<<n)-1)^guys_mask;
                        rev_guys_mask &= right_sub;
                        ans[cur_mask+(mask_right<<sz1)]+=rem_value*sub_sum_right[mask_right][rev_guys_mask];
                        ans[cur_mask+(1ll<<(sz1-1))+(mask_right<<sz1)]+=rem_value*sub_sum_right[mask_right][guys_mask];
                    }
                }
            }
        }
    }

    for (int i=0;i<(1ll<<(n-1));i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}
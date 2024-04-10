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
 
const int max_n = 2e5+10, inf = 1000111222;
 
int a[max_n];
 
vector<pii> before[max_n];
vector<int> suf_min_r[max_n];
 
vector<ll> dp[max_n];
 
void solve()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
 
    for (int i=0;i<=n;i++){
        before[i].clear();
        suf_min_r[i].clear();
        dp[i].clear();
    }
    for (int i=0;i<m;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        int id=upper_bound(a,a+n,r)-a;
        if (id==0 || a[id-1]<l){
            before[id].pb(mp(l,r));
        }
    }
 
    for (int i=0;i<=n;i++){
        sort(all(before[i]));
    }
 
    for (int i=0;i<=n;i++){
        suf_min_r[i].reserve(len(before[i]));
        for (int j=len(before[i])-1;j>=0;j--){
            suf_min_r[i].pb(min((suf_min_r[i].empty() ? +inf : suf_min_r[i].back()), before[i][j].sec));
        }
        reverse(all(suf_min_r[i]));
    }
 
    vector<pair<int,ll>> cur_dp;
    if (before[0].empty()){
        cur_dp.pb(mp(0,0));
    }
    else{
        int want_r=suf_min_r[0][0];
        cur_dp.pb(mp(a[0]-want_r,a[0]-want_r));
    }
 
    a[n]=+inf;
 
    for (int i=0;i<n;i++){
        //sort(all(cur_dp));
//        cout<<"before "<<i<<" :: ";
//        for (auto q:cur_dp){
//            cout<<"("<<q.fir<<","<<q.sec<<")"<<" ";
//        }
//        cout<<"\n";
        vector<ll> pref_min__dp_plus_l;
        pref_min__dp_plus_l.reserve(len(cur_dp));
        vector<ll> suf_min__dp;
        suf_min__dp.reserve(len(cur_dp));
 
        for (int j=0;j<len(cur_dp);j++){
            pref_min__dp_plus_l.pb(
                    min(
                            (pref_min__dp_plus_l.empty() ? 1ll*inf*inf : pref_min__dp_plus_l.back()),
                            cur_dp[j].fir+cur_dp[j].sec
                    )
                    );
        }
        for (int j=len(cur_dp)-1;j>=0;j--){
            suf_min__dp.pb(
                    min(
                            (suf_min__dp.empty() ? 1ll*inf*inf : suf_min__dp.back()),
                            cur_dp[j].sec
                    )
                    );
        }
        reverse(all(suf_min__dp));
 
        auto get_new_dp=[&](int cur_max_R)
        {
            int next_in_before_i_plus_one = upper_bound(all(before[i+1]),mp(cur_max_R,+inf))-before[i+1].begin();
 
            int to_go_for_next_guy=-1;
 
            if (next_in_before_i_plus_one == len(before[i+1])){
                to_go_for_next_guy=0;
            }
            else{
                to_go_for_next_guy=a[i+1]-suf_min_r[i+1][next_in_before_i_plus_one];
            }
 
//            cout<<"from cur_max_R("<<cur_max_R<<") i have to_go_for_next_guy :: "<<to_go_for_next_guy<<"\n";
 
            ll value_dp_from_left=1ll*inf*inf;
 
            /// if y >= x
            {
                int pref_to_use = upper_bound(all(cur_dp),mp((cur_max_R - a[i])+1,-1ll))-cur_dp.begin();
                if (pref_to_use!=0){
                    value_dp_from_left=min(
                            value_dp_from_left,
                            pref_min__dp_plus_l[pref_to_use-1] + 1ll*(cur_max_R - a[i])
                    );
                }
            }
            /// if y < x
            {
                int suf_to_use = upper_bound(all(cur_dp),mp((cur_max_R - a[i])+1,-1ll))-cur_dp.begin();
                if (suf_to_use!=len(cur_dp)){
                    value_dp_from_left=min(
                            value_dp_from_left,
                            suf_min__dp[suf_to_use] + 2ll*(cur_max_R - a[i])
                    );
                }
            }
 
            ll value_of_dp = 1ll*to_go_for_next_guy + value_dp_from_left;
 
            return mp(to_go_for_next_guy, value_of_dp);
        };
 
        vector<pair<int,ll>> new_dp;
        new_dp.reserve(len(before[i+1])+1);
        new_dp.pb(get_new_dp(a[i]));
        for (auto q:before[i+1]){
            new_dp.pb(get_new_dp(q.fir));
        }
 
        cur_dp=new_dp;
        reverse(all(cur_dp));
    }
 
 
//    cout<<"at the end :: ";
//    for (auto q:cur_dp){
//        cout<<"("<<q.fir<<","<<q.sec<<")"<<" ";
//    }
//    cout<<"\n";
 
    ll ans=1ll*inf*inf;
    for (auto i:cur_dp){
        if (i.fir==0){
            ans=min(ans,i.sec);
        }
    }
    cout<<ans<<"\n";
}
 
int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
 
    int test;
    scanf("%d",&test);
    while (test--){
        solve();
    }
}
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

int F[max_n];

void F_upd(int pos,int val)
{
    for (int i=pos;i<max_n;i|=i+1){
        F[i]=max(F[i],val);
    }
}

int F_get(int pos)
{
    int res=-1e9;
    for (int i=pos;i>=0;i&=i+1,i--){
        res=max(res,F[i]);
    }
    return res;
}

int a[max_n];
int dp[max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    vector<pii> v;
    for (int i=1;i<=n;i++){
        v.pb(mp(a[i],i));
    }
    sort(all(v));
    vector<int> vh;
    vh.pb(0-a[0]);
    for (int i=1;i<=n;i++){
        vh.pb(i-a[i]);
    }
    sort(all(vh));

    auto get_vh_id=[&](int a)
    {
        return lower_bound(all(vh),a)-vh.begin();
    };

    auto upd_dp=[&](int pos,int val)
    {
        F_upd(get_vh_id(pos-a[pos]),val);
    };

    for (int i=0;i<max_n;i++){
        F[i]=-1e9;
    }
    upd_dp(0,0);

    for (int i=0;i<len(v);){
        int j=i;
        while (j+1<len(v)&&v[j+1].fir==v[i].fir){
            j++;
        }
        /// [i;j]

        for (int k=i;k<=j;k++){
            int pos=v[k].sec;
            dp[pos]=F_get(get_vh_id(pos-a[pos]))+1;
//            cout<<"dp["<<pos<<"] :: "<<dp[pos]<<"\n";
        }
        for (int k=i;k<=j;k++){
            int pos=v[k].sec;
            upd_dp(pos,dp[pos]);
        }

        i=j+1;
    }
    cout<<*max_element(dp,dp+n+1)<<"\n";
}
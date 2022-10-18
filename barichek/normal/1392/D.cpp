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

int dp[max_n][4];

bool ok_take(int mask,int bit)
{
    if (mask==0 && bit==0){
        return false;
    }
    if (mask==3 && bit==1){
        return false;
    }
    return true;
}

int new_mask(int mask,int bit)
{
    return (mask>>1)+(bit<<1);
}

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=inf;
    for (int start_mask=0;start_mask<4;start_mask++){
        for (int i=0;i<n+2;i++){
            for (int j=0;j<4;j++){
                dp[i][j]=inf;
            }
        }
        bool bit0=(start_mask&(1ll<<0))>0;
        bool bit1=(start_mask&(1ll<<1))>0;
        dp[1][start_mask]=(((s[0]=='R') ^ bit0) ? 1 : 0) + (((s[1]=='R') ^ bit1) ? 1 : 0);
        for (int i=1;i+1<n+2;i++){
            for (int last_mask=0;last_mask<4;last_mask++){
                for (int take=0;take<2;take++){
                    if (ok_take(last_mask,take)){
                        int cur_new_mask=new_mask(last_mask,take);
                        dp[i+1][cur_new_mask]=min(dp[i+1][cur_new_mask], dp[i][last_mask]+(i+1<len(s) && ((s[i+1]=='R') ^ take) ? 1 : 0));
//                        cout<<"new :: "<<i+1<<" "<<cur_new_mask%2<<" "<<dp[i+1][cur_new_mask]/2<<" :: "<<dp[i+1][cur_new_mask]<<"\n";
                    }
                }
            }
        }
        ans=min(ans,dp[n+1][start_mask]);
    }
    cout<<ans<<"\n";
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}
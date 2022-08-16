#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N  =  2e+5+5;
const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n,k,dp[N][3],t;
string r[] = {"RGB","GBR","BRG"};
string a;

int main(){
    fastio;
    cin>>t;
    while(t--){
        ll minn = N;
        cin>>n>>k>>a;
        dp[0][0] = dp[0][1] = dp[0][2] = 0;
        for(int j = 0; j < 3; j++){
            for(int i = 0; i < k; i++){
                if(a[i] != r[j][i%3]) dp[0][j]++;
            }
            minn = min(minn,dp[0][j]);
        }
        for(int i = 1; i <= n-k; i++){
            dp[i][0] = dp[i-1][2];
            if(a[i-1] != 'B') dp[i][0]--;
            if(a[i+k-1] != r[2][k%3]) dp[i][0]++;
            minn = min(minn,dp[i][0]);

            dp[i][1] = dp[i-1][0];
            if(a[i-1] != 'R') dp[i][1]--;
            if(a[i+k-1] != r[0][k%3]) dp[i][1]++;
            minn = min(minn,dp[i][1]);

            dp[i][2] = dp[i-1][1];
            if(a[i-1] != 'G') dp[i][2]--;
            if(a[i+k-1] != r[1][k%3]) dp[i][2]++;
            minn = min(minn,dp[i][2]);

            //cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
        }
        cout<<minn<<endl;
    }
}
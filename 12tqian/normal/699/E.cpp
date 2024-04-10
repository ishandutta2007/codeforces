#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX = 25;
const int PMAX = (1<<20) +  5;

static double dp[PMAX];
static double p [MAX];
static double sum[PMAX];
static double ans[MAX];

ll countones(ll x){
    return __builtin_popcountll(x);
}
int main(){
    int n, k;
    int nonzero = 0;
    scanf("%d %d", &n, &k);
    for(ll i = 0; i<n; i++){
        double d;
        cin>>d;
        p[i] = d;
        if(d>0){
            nonzero += 1;
        }
    }
    for(ll mask = 0; mask<(1<<n); mask ++){
        for(ll i = 0; i<n; i++){
            if((1<< i)&mask){
                sum[mask] += p[i];
            }
        }
    }
    for(ll mask = 0; mask<(1<<n); mask ++){
       // cout << sum[mask] << " sum" <<  endl;
    }
    dp[0] = 1;
    for(ll mask = 0; mask<(1<<n); mask++){
        for(ll i = 0; i<n; i++){
            if(sum[mask] >= 1){
                continue;
            }
           // cout << mask << " " << (1<< i) <<" " << (mask & (1<<i)) << endl;
            if((mask & (1<< i)) == 0){
                double prob = p[i]/(1- sum[mask]);
                //cout << prob << " prob" << endl;
                dp[mask+ (1<< i)] += dp[mask]*p[i]/(1- sum[mask]);
            }
        }
    }
    for(ll mask = 0; mask<(1<<n); mask ++){
        for(ll i = 0; i<n; i++){
            if(countones(mask) != min(nonzero, k)){
                continue;
            }
            if(mask & (1<<i)){
                ans[i] += dp[mask];
            }
        }
    }
    for(ll i = 0; i<n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
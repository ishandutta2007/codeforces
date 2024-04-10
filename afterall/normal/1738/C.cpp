//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <string>
#include <bitset>
#include <numeric>
#include <iomanip>
#include <limits.h>
#include <tuple>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=150;
ll dp[N][N][2][2];
/// 0 Bob 1 Alice
void Main(){
    ll n;
    cin >> n;
    ll t0=0,t1=0;
    for (int i=1;i<=n;i++){
        ll x;
        cin >> x;
        if (x%2==0) t0++;
        else t1++;
    }
   // cout << t1 << " " << t0 << endl;
    if (dp[t1][t0][0][1]==1){
        cout << "Alice" << endl;
    }
    else cout << "Bob" << endl;
    
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    dp[0][0][0][0]=1;
    dp[0][0][0][1]=1;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (i==0 && j==0) continue;
            for (int z=0;z<=1;z++){
                for (int t=0;t<=1;t++){
                    if (t==0){
                        dp[i][j][z][t]=1;
                        if (i>0) dp[i][j][z][t]=min(dp[i][j][z][t],dp[i-1][j][z][1-t]);
                        if (j>0) dp[i][j][z][t]=min(dp[i][j][z][t],dp[i][j-1][z][1-t]);
                    }
                    else{
                        dp[i][j][z][t]=0;
                        if (i>0) dp[i][j][z][t]=max(dp[i][j][z][t],dp[i-1][j][1-z][1-t]);
                        if (j>0) dp[i][j][z][t]=max(dp[i][j][z][t],dp[i][j-1][z][1-t]);
                    }
                }
            }
        }
    }
    /// dp[i][j][k] : i ta fard
    
    while(t--) Main();
}
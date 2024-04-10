#include<iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

ll c [100001];
ll dp[100001];
int main(){
    ll n,a;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> a;
        c[a]++;
    }
    dp[1] = c[1];
    dp[2] = max(c[1],2*c[2]);
    for(ll i = 3;i<=100000;i++){
        dp[i] = max( (i*c[i])+dp[i-2],(i-1)*(c[i-1])+dp[i-3]);
    }
    cout << dp[100000];
    return 0;
}
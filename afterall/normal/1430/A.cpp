#include <bits/stdc++.h>
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
const int N=1e3+100;
ll dp[N],bk[N];
ll t[10];
ll Main(){
    memset(dp,0,sizeof dp);
    memset(bk,0,sizeof bk);
    memset(t,0,sizeof t);
    dp[0]=1;
    ll n;
    cin >> n;
    for (int i=3;i<=n;i++){
        if (dp[i-3]){
            dp[i]=1;
            bk[i]=i-3;
        }
        if (i-5>=0 && dp[i-5]){
            dp[i]=1;
            bk[i]=i-5;
        }
        if (i-7>=0 && dp[i-7]){
            dp[i]=1;
            bk[i]=i-7;
        }
    }
    if (dp[n]==0) kill(-1);
    while(n){
        ll z=bk[n];
        t[n-z]++;
        n=z;
    }
    cout << t[3] << " " << t[5] << " " << t[7] << endl;
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}
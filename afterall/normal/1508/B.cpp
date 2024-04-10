#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef complex<double> point;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
const int N=2e5+100,inf=(ll)1e18+100;
ll dp[N],par[N];
int Main(){

    ll n,k;
    cin >> n >> k;
    if (dp[n]<k) kill(-1);
    vector <int> ans;
    ll cnt=0;
    while(n){
        for (int i=1;i<=n;i++){
            if (dp[n-i]<k){
                k-=dp[n-i];
                continue;
            }
            for (int j=i;j;j--){
                ans.pb(j+cnt);
            }
            cnt+=i;
            n-=i;
            break;
        }
    }
    for (auto u : ans){
        cout << u << " ";
    }
    cout << endl;
    return 0;
}
int32_t main(){
    ll t=1;
    cin >> t;
    dp[1]=1;
    dp[0]=1;
    par[1]=2;
    par[0]=1;
    for (int i=2;i<N;i++){
        dp[i]=par[i-1];
        par[i]=par[i-1]+dp[i];
        if (par[i]>inf) par[i]=inf;
    }
    while(t--){
        Main();
    }
}
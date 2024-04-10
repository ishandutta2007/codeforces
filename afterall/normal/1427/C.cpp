#include <bits/stdc++.h>
typedef int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=1e5+100;
ll dp[N];
ll mx[N];
int Main(){
    ll r,n;
    cin >> r >> n;
    vector <pair <int,pii> > a;
    a.pb({0,{1,1}});
    for (int i=0;i<n;i++){
        ll t,x,y;
        cin >> t >> x >> y;
        a.pb({t,{x,y}});
    }
    for (int i=0;i<N;i++) dp[i]=-1e9;
    dp[0]=0;
    for (int i=1;i<=n;i++){
        for (int j=i-1;j>=max(i-1020,(ll)0);j--){
            ll z=abs(a[i].S.F-a[j].S.F)+abs(a[i].S.S-a[j].S.S);
            if (a[i].F-a[j].F>=z){
               // if (dp[j]) cout << i << " " << j << endl;
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        if (i-1015>0){
            ll z=i-1015;
            dp[i]=max(dp[i],mx[z]+1);
        }
        mx[i]=max(dp[i],mx[i-1]);
    }
    ll ans=0;
    for (int i=1;i<=n;i++) ans=max(ans,dp[i]);
    cout << ans << endl;

}
int32_t main(){
    sync;
    ll t;
    t=1;
    while(t--){
        Main();
    }
}
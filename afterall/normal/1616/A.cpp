#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
ll vis[200];
int Main(){
    memset(vis,0,sizeof vis);
    ll n;
    cin >> n;
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        x=abs(x);
        vis[x]++;
    }
    ll ans=0;
    if (vis[0]) ans++;
    for (int i=1;i<200;i++){
        ans+=min(vis[i],(ll)2);
    }
    kill(ans);

    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}
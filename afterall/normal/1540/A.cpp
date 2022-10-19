#include <bits/stdc++.h>
/// this time?
typedef long long int ll;
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
using namespace std;

const int N=2e5+100;
int Main(){
    ll n;
    cin >> n;
    vector <int> a;
    ll ans=0;
    for (int i=1;i<=n;i++){
        ll x;
        cin >> x;
        if (i!=1)
            a.pb(x);
    }
    sort(a.begin(),a.end());
    for (int i=n-2;i>0;i--){
        a[i]-=a[i-1];
    }
    for (int i=0;i<n-1;i++){
        ans+=a[i];
        ans-=a[i]*(i+1)*(n-i-1);
    }
    kill(ans);
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--){
        Main();
    }
}
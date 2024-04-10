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

void Main(){
    vector <pii> a;
    ll n;
    cin >> n;
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        a.pb({x,i+1});
    }
    sort(a.begin(),a.end());
    ll ans=-1;
    for (int i=1;i<a.size();i++){
        if (a[i].F==a[i-1].F){
            ans=max(ans,n-a[i].S+a[i-1].S);
        }
    }
    cout << ans << endl;
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}
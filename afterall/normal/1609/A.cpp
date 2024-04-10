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

const int N=2e5+100;
ll Main(){
    ll n;
    cin >> n ;
    vector <int> a;
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        a.pb(x);
    }
    sort(a.begin(),a.end());
    ll ans=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (j==i) continue;
            while(a[j]%2==0){
                a[j]/=2;
                a[i]*=2;
            }
        }
        ll p1=0;
        for (auto u : a) p1+=u;
        ans=max(ans,p1);
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
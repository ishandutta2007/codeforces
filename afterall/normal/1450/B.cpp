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
int Main(){
    ll n,k;
    cin >> n >> k;
    vector <pii> a;
    for (int i=0;i<n;i++){
        ll x,y;
        cin >> x >> y;
        a.pb({x,y});
    }
    for (int i=0;i<n;i++){
        ll p1=0;
        for (int j=0;j<n;j++){
            ll z=abs(a[i].F-a[j].F)+abs(a[i].S-a[j].S);
            if (z>k) p1=1;
        }
        if (p1==0) kill(1);
    }
    kill(-1);

}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--){
        Main();
    }
}
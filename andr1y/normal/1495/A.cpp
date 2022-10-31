// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    cout<<fixed<<setprecision(15);
    while(q--){
        ll n;
        cin >> n;
        priority_queue<ll, vector<ll>, greater<ll>> pqx0, pqy0;
        for(ll i = 0;i<n+n;i++){
            ll x,y;
            cin >> x >> y;
            x*=x, y*=y;
            if(x==0) pqx0.push(y);
            if(y==0) pqy0.push(x);
        }
        ld res=0;
        for(ll i = 0;i<n;i++){
            ll a = pqx0.top(); pqx0.pop();
            ll b = pqy0.top(); pqy0.pop();
            res+=sqrtl(a+b);
        }
        cout<<res<<'\n';
    }
}
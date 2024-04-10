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
const int N=2e5+100 ;

int Main(){
    ll n;
    cin >> n;
    set <pii> s,t;
    pair<pii,int> mx={{0,-1},0};
    for (int i=0;i<n;i++){
        ll l,r,c;
        cin >> l >> r >> c;
        if (r-l+1>mx.F.S-mx.F.F+1){
            mx={{l,r},c};
        }
        if (r-l+1==mx.F.S-mx.F.F+1 && c<mx.S){
            mx={{l,r},c};
        }
        s.insert({l,c});
        t.insert({-r,c});
        ll ans=s.begin()->S+t.begin()->S;
        if (mx.F.F==s.begin()->F && -mx.F.S==t.begin()->F) ans=min(ans,mx.S);
        cout << ans << endl;
    }
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}
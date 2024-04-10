#include <bits/stdc++.h>
/// 500 485 462 A4
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
vector <int> g[N];
ll in[N];
int Main(){
    ll n;
    cin >> n ;
    for (int i=1;i<=n;i++){
        g[i].clear();
        in[i]=0;
    }
    for (int i=1;i<=n;i++){
        ll k;
        cin >> k;
        for (int j=0;j<k;j++){
            ll x;
            cin >> x;
            g[x].pb(i);
            in[i]++;
        }
    }
    ll now=0;
    set <pii> s;
    ll ans=1;
    ll t=0;
    for (int i=1;i<=n;i++){
        if (in[i]==0) s.insert({0,i});
    }
    while(s.size()){
        pii V=*s.begin();
       // cout << v << endl;
        ll v=V.S;
        s.erase(s.begin());
        t++;
        ll p1=0;
        ans=V.F+1;
        for (auto u : g[v]){
            in[u]--;
            if (in[u]==0){
                if (u<v){
                    s.insert({V.F+1,u});
                }
                else s.insert({V.F,u});
            }
        }

    }
    if (t!=n) kill(-1);
    kill(ans);
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--){
        Main();
    }
}
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
vector <int> g[N];
ll mx=0;
ll a[N];
ll dfs(ll v,ll h){
    mx=max(mx,h);
    for (auto u : g[v]){
        dfs(u,h+1);
    }
}
int Main(){
    ll n;
    cin >> n;
    mx=0;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) g[i].clear();
    ll cnt=1;
    for (int i=2;i<=n;i++){
        ll k=i;
        while(k<n && a[k+1]>a[k]) k++;
        for (int j=i;j<=k;j++){
            g[cnt].pb(j);
        }
        i=k;
        cnt++;
    }
    dfs(1,0);
    cout << mx << endl;
}
int32_t main(){
    ll t;
    cin >> t;
    while(t--){
        Main();
    }

}
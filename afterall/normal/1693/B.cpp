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
#define kill(x) cout << x << endl;return ;
using namespace std;
const int N=2e5+100;
vector <int> g[N];
pii dp[N];
ll l[N];
ll r[N];
void dfs(ll v){
    for (auto u : g[v]){
        dfs(u);
        dp[v].F+=dp[u].F;
        dp[v].S+=dp[u].S;
    }
    if (dp[v].S<l[v]) {
        dp[v].F++;
        dp[v].S=r[v];
    }
    dp[v].S=min(dp[v].S,r[v]);
}
void Main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++) {
        dp[i]={0,0};
        g[i].clear();
    }
    for (int i=2;i<=n;i++){
        ll x;
        cin >> x;
        g[x].pb(i);
    }
    for (int i=1;i<=n;i++) cin >> l[i] >> r[i];
        dfs(1);
    cout << dp[1].F << endl;
}
int32_t main(){
    ll q;
    cin >> q;
    while(q--) Main();
}
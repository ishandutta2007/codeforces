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
#define kill(x) cout << x << endl;return;
using namespace std;
const int N=2e5+100;
map <int,int> mp;
vector <pair <int,pii> > g[N];
vector <int> pr[N];
int ted[N];
ll mod=998244353;
ll power(ll n,ll k){
    if (k==0) return 1;
    if (k%2==1){
        ll x=power(n,k/2);
        return x*x%mod*n%mod;
    }
    ll x=power(n,k/2);
    return x*x%mod;
}
ll ans=0;
void dfs(ll v,ll p){
    for (auto U : g[v]){
        int u=U.F,x=U.S.F,y=U.S.S;
        if (u==p) continue;
        for (auto e : pr[x]){
            ted[e]++;
        }
        for (auto e : pr[y]){
            ted[e]--;
            if (ted[e]<0){
           //     cout << e << " e " << endl;
            }
            ted[e]=max(ted[e],(ll)0);

        }
        dfs(u,v);
        for (auto e : pr[y]){
            ted[e]++;
        }
        for (auto e : pr[x]){
            ted[e]--;
        }
    }
}
void dfs2(ll v,ll p,ll K){
    ans+=K;
    ans%=mod;
    for (auto U : g[v]){
        int u=U.F,x=U.S.F,y=U.S.S;
        if (u==p) continue;
        int k=K;
        k*=x;
        k%=mod;
        k*=power(y,mod-2);
        k%=mod;
        dfs2(u,v,k);
    }
}
void Main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++) g[i].clear(),ted[i]=0;
    for (int i=0;i<n-1;i++){
        ll u,v,x,y;
        cin >> v >> u >> x >> y;
        g[u].pb({v,{x,y}});
        g[v].pb({u,{y,x}});
    }
    ans=0;
    dfs(1,1);
    ll z=1;
    for (int i=1;i<=n;i++){
        z*=power(i,ted[i]);
        z%=mod;
    }
  //  cout << "1: " << z << endl;
    dfs2(1,1,z);
    cout << ans << endl;


}
int32_t main(){
    sync;
    for (int i=2;i<N;i++){
        if (pr[i].size()!=0){
            continue;
        }
        for (int j=i;j<N;j+=i){
            ll x=j;
            while(x%i==0){
                x/=i;
                pr[j].pb(i);
            }
        }
    }
    ll t=1;
    cin >> t;
    while(t--) Main();
}
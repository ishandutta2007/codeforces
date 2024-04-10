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

const int N=1e3+100;

vector <int> mol[N];
ll par[N];
ll cnt=1;
void merg(ll u,ll v){
    if (par[u]==par[v]){
        cnt++;
        return ;
    }
    u=par[u];
    v=par[v];
    if (mol[u].size()<mol[v].size()) swap(u,v);
    for (auto k : mol[v]){
        mol[u].pb(k);
        par[k]=u;
    }
    mol[v].clear();
}
int32_t main(){
    sync;
    ll n,d;
    cin >> n >> d;
    for (int i=1;i<=n;i++) mol[i].pb(i),par[i]=i;

    for (int i=0;i<d;i++){
        ll x,y;
        cin >> x >> y;
        merg(x,y);
        vector <int> a;
        for (int i=1;i<=n;i++){
            a.pb(mol[i].size());
        }
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        ll ans=0;
        for (int i=0;i<min(cnt,(ll)a.size());i++) ans+=a[i];
        cout << ans-1 << endl;
    }
}
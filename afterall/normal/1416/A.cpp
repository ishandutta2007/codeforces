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
const int N=3e5+100;
vector <int> ja[N];
ll a[N];
ll par[N];
ll Main(){
    ll n;
    cin >> n;
    par[0]=1e9;
    for (int i=1;i<=n;i++){
        ja[i].clear();
        par[i]=1e9;
        ja[i].pb(0);
    }
    for (int i=1;i<=n;i++){
        cin >> a[i];
        ja[a[i]].pb(i);
    }
    for (int i=1;i<=n+1;i++){
        ja[i].pb(n+1);
    }
    for (int i=1;i<=n;i++){
        ll mi=0;
        for (int j=1;j<ja[i].size();j++){
            mi=max(mi,ja[i][j]-ja[i][j-1]);
        }
        par[mi]=min(par[mi],i);
    }
    for (int i=1;i<=n;i++){
        par[i]=min(par[i],par[i-1]);
        if (par[i]>=1e9) cout << -1 << " ";
        else cout << par[i] << " ";

    }
    cout << endl;
}
int32_t main(){
    ll t;
    cin >> t;
    while(t--) Main();
}
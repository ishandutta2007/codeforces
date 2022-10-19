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
const int N=2e5+100,M=8;
ll dp[N][(1<<M)];
vector <int> tam[N];
vector <int> agh[N];
vector <int> hazf(vector <int> a,ll v){
    vector <int> b;
    for (int i=0;i<a.size();i++){
        if (a[i]!=v) b.pb(a[i]);
    }
    return b;
}
ll id[N];
int32_t main(){
    vector <pii> seg;
    ll n,m,k;
    cin >> n >> m >> k;
    vector <int> a;
    for (int i=1;i<=n;i++){
        ll l,r;
        cin >> l >> r;
        r++;
        seg.pb({l,r});
        a.pb(l);
        a.pb(r);
    }
    a.pb(0);
    sort(a.begin(),a.end());
    a.resize(unique(a.begin(),a.end())-a.begin());
    for (int i=0;i<n;i++){
        ll l=seg[i].F,r=seg[i].S;
        ll z=lower_bound(a.begin(),a.end(),l)-a.begin();
        agh[z].pb(i);
        z=lower_bound(a.begin(),a.end(),r)-a.begin();
        tam[z].pb(i);
    }
    ll cnt=0;
    vector <int> baz;
    for (int i=0;i<a.size()-1;i++){
        for (auto u : tam[i]){
            ll z=id[u];
            for (auto v : baz){
                if (id[v]>z){
                    id[v]--;
                }
            }
            for (int j=0;j<(1<<cnt);j++){
                ll bit=j%(1<<z);
                ll y=j/(1<<(z+1));
                y*=(1<<z);
                bit=y+bit;
                ll x=0;
                if ((j & (1<<z))) x=dp[i][bit];
                dp[i][bit]=max(x,dp[i][j]);
                if (i==5 && j==2){
        //            cout << bit << " fjnr " << id[u]  << " " << dp[i][bit] << endl;
                }
            }
            baz=hazf(baz,u);
            cnt--;
        }
        for (auto u : agh[i]){
            id[u]=baz.size();
            cnt++;
            for (int j=(1<<cnt)-1;j>-1;j--){
                if (( j & (1<<id[u]))){
                    dp[i][j]=dp[i][j-(1<<id[u])];
                }
            }
            baz.pb(u);
        }
        for (int j=0;j<(1<<cnt);j++){
            ll z=__builtin_popcount(j);
            if (i==5 && j==1){
        //        cout << dp[i][j] << " wrkfkjnerk " << a[i+1] << " " << a[i] << endl;
            }
            z%=2;
            dp[i+1][j]=dp[i][j]+z*(a[i+1]-a[i]);
          //  cout << a[i+1] << " " << j << " " << dp[i+1][j] << endl;
        }
        for (auto u : baz){
            //cout << u << " id " << id[u] << "     " ;
        }
        //cout << endl;

    }
    ll ans=0;
    for (int i=0;i<(1<<cnt);i++){
        ans=max(ans,dp[a.size()-1][i]);
    }
    cout << ans << endl;
}
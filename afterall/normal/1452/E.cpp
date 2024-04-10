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
const int N=2e3+100;
ll par[N],rap[N];
ll cnt[N];
ll b[N];
int32_t main(){
    ll n,m,k;
    cin >> m >> n >> k;
    vector <pair <int,pii> > a;
    for (int i=1;i<=n;i++){
        ll l,r;
        cin >> l >> r;
        a.pb({l+r,{l,r}});
    }
    sort(a.begin(),a.end());
    for (int i=0;i<n;i++){
        for (int j=a[i].S.F;j<=a[i].S.S;j++){
            cnt[j]++;
        }
        for (int j=1;j<=m;j++){
            b[j]=cnt[j]+b[j-1];
        }
        for (int j=1;j<=m;j++){
            ll z=0;
            if (j-k>=0){
                z=b[j-k];
            }
            par[i+1]=max(par[i+1],b[j]-z);
        }
    }
    memset(cnt,0,sizeof cnt);
    for (int i=n-1;i>-1;i--){
        for (int j=a[i].S.F;j<=a[i].S.S;j++){
            cnt[j]++;
        }
        for (int j=1;j<=m;j++){
            b[j]=cnt[j]+b[j-1];
        }
        for (int j=1;j<=m;j++){
            ll z=0;
            if (j-k>=0){
                z=b[j-k];
            }
            rap[i+1]=max(rap[i+1],b[j]-z);
        }
    }
    ll ans=0;
    for (int i=0;i<=n;i++){
        ans=max(ans,par[i]+rap[i+1]);
   //     cout << i << " " << par[i] << " " << rap[i+1] << endl;
    }
    cout << ans << endl;
}
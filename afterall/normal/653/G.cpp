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
const int N=3e5+100,M=20;
ll mod=1e9+7;
ll power(ll n,ll k){
    if (k==0) return 1;
    if (k%2==1){
        ll x=power(n,k/2);
        return x*x%mod*n%mod;
    }
    ll x=power(n,k/2);
    return x*x%mod;
}
ll fac[N],fm[N];
ll ent(ll k,ll n){
    if (k<0 || k>n) return 0;
    if (k==0 || k==n) return 1;
    return fac[n]*fm[k]%mod*fm[n-k]%mod;
}
ll a[N];
vector <int> b[N];
vector <int> pr[N];
ll par[N];
ll rap[N];
int32_t main(){
    fac[0]=1;
    for (int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%mod;
        fm[i]=power(fac[i],mod-2);
    }
    for (int i=2;i<N;i++){
        if (b[i].size()==0){
            for (int j=i;j<N;j+=i) b[j].pb(i);
        }
    }
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        for (auto u : b[a[i]]) pr[u].pb(i);
    }
    ll ans=0;
    for (int ii=2;ii<N;ii++){
        if (pr[ii].size()==0) continue;

        ll t0=n-pr[ii].size();
        vector <int> c;
        for (auto u : pr[ii]){
            ll z=a[u];
            ll cnt=0;
            while(z%ii==0){
                z/=ii;
                cnt++;
            }
            c.pb(cnt);
        }
        sort(c.begin(),c.end());
        for (int i=1;i<=c.size();i++){
            par[i]=par[i-1]+ent(i,c.size()+t0-1);
            par[i]%=mod;
        }
        rap[t0]=0;
        rap[c.size()+t0]=0;
        for (int i=c.size()+t0-1;i>=t0;i--){
            rap[i]=rap[i+1]+ent(i,c.size()+t0-1);
        }
       // cout << t0 << " t0" << endl;
        //for (int i=0;i<c.size();i++) cout << c[i] << " c_i ";
        //cout << endl;
        for (int i=0;i<c.size();i++){
            ll z1=t0+i,z2=c.size()-i-1;
            ll k=z2;
            ans-=(par[z2])*c[i]%mod;
            ans+=mod;
            ans%=mod;
            ans+=(power(2,n-1)-rap[z1+1]-1+mod)%mod*c[i]%mod;
            ans%=mod;
         //   cout << ans << " ans" << endl;
        }
        //cout << ans << endl;

    }
    cout << ans << endl;
}
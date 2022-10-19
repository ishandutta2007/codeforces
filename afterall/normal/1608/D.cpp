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
const int N=1e5+100;
ll mod=998244353 ;
ll power(ll n,ll k){
    if (k==0) return 1;
    if (k%2==1){
        ll x=power(n,k/2);
        return x*x%mod*n%mod;
    }
    ll x=power(n,k/2);
    return x*x%mod;
}
ll fac[N];
ll fm[N];
ll ent(ll k,ll n){
    if (k<0 || k>n) return 0;
    if (k==n || k==0) return 1;
    return fac[n]*fm[k]%mod*fm[n-k]%mod;
}
ll a[N][2];
int32_t main(){
    sync;
    fac[0]=1;
    fm[0]=1;
    for (int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%mod;
        fm[i]=power(fac[i],mod-2);
    }
    ll ans=0;
    ll tlb=0,trb=0,tl=0,tr=0;
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        if (s[0]=='W') s[0]='B';
        else if (s[0]=='B') s[0]='W';
        if (s[0]=='?') a[i][0]=-1,tl++;
        if (s[0]=='B') a[i][0]=1,tl++,tlb++;

        if (s[1]=='?') a[i][1]=-1,tr++;
        if (s[1]=='B') a[i][1]=1,tr++,trb++;
    }
    for (int i=0;i<=n;i++){
        ans+=ent(i-trb,tr-trb)*ent(i-tlb,tl-tlb)%mod;
        ans%=mod;
    }
  //  cout << ans << endl;
    ll bad=1;
    for (int i=1;i<=n;i++){
        if (a[i][0]==0 && a[i][1]==1) bad=0;
        if (a[i][0]==1 && a[i][1]==0) bad=0;
        if (a[i][0]==-1 && a[i][1]==-1) {
            bad*=2;
            bad%=mod;
        }
    }
    ans-=bad;
    ans+=mod;
    ans%=mod;

    bad=1;
    for (int i=1;i<=n;i++){
        if (a[i][0]==0 || a[i][1]==0) bad=0;
    }
    ans+=bad;
    bad=1;
    for (int i=1;i<=n;i++){
        if (a[i][1]==1 || a[i][0]==1) bad=0;
    }
    ans+=bad;
    //cout << bad << endl;
    cout << ans%mod << endl;

}
#include <bits/stdc++.h>
/// 500 485
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=5e5+100,M=61;
ll p2[M];
ll mod=(1e9+7);
ll t[M];
ll a[N];
ll o[N];
ll an[N];
int Main(){
    p2[0]=1;
    for (int i=1;i<M;i++){
        p2[i]=p2[i-1]*(ll)2;
    }
    memset(t,0,sizeof t);
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        a[i]=0;
        o[i]=0;
        an[i]=0;
    }
    for (int i=1;i<=n;i++){
        cin >> a[i];
        for (int j=0;j<M;j++){
            if ((a[i] & p2[j])) t[j]++;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<M;j++){
            if ((a[i] & p2[j])){
                o[i]+=(p2[j]%mod)*n%mod;
                o[i]%=mod;
                an[i]+=(p2[j]%mod)*t[j]%mod;
                an[i]%=mod;
            }
            else{
                o[i]+=(p2[j]%mod)*t[j]%mod;
                o[i]%=mod;
            }
        }
    }
    ll ans=0;
    for (int i=1;i<=n;i++){
        ans+=o[i]*an[i]%mod;
        ans%=mod;
    }
    cout << ans << endl;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while (t--) Main();
}
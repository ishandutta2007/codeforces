 #include <bits/stdc++.h>
/// 500 485 462 A4
using namespace std;
typedef long long int ll;
typedef complex<long double> point;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
const int N=2e5+100;
ll a[N];
ll af[N];
ll Main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    af[n+1]=n+1;
    for (int i=n;i;i--){
        if (a[i]!=1) af[i]=i;
        else af[i]=af[i+1];
    }
    vector <int> bad;
    for (int i=1;i<=n;i++){
        if (a[i]!=1) bad.pb(i);
    }
    ll ans=0;
    while(bad.size()){
        ll p1=0;
        ll id=bad[0];
        if (a[id]>n-id+2){
            ans+=a[id]-(n-id+2);
            a[id]=n-id+2;
        }
        ans++;
        while(id<=n){
            a[id]--;
            if (a[id]==1) p1=1;
            id+=a[id]+1;
            if (id<=n) id=af[id];
        }
        if (p1){
            vector <int> ja;
            for (auto u : bad){
                if (a[u]>1) ja.pb(u);
            }
            bad=ja;
            af[n+1]=n+1;
            for (int i=n;i;i--){
                if (a[i]!=1) af[i]=i;
                else af[i]=af[i+1];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
int32_t main(){
    sync;
    ll t;
    t=1;
    cin >> t;
    while(t--) Main();
}
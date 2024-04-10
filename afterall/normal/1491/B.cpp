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
ll Main(){
    ll n,u,v;
    cin >> n >> u >> v;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    ll p1=0;
    ll p2=0;
    for (int i=2;i<=n;i++){
        if (a[i]!=a[i-1]) p1=1;
        if (abs(a[i]-a[i-1])>1) p2=1;
    }
    if (p2) kill(0);
    if (p1==0){
        ll ans=v+min(u,v);
        cout << ans << endl;
    }
    else cout << min(u,v) << endl;
    return 0;
}
int32_t main(){
    sync;
    ll t;
    t=1;
    cin >> t;
    while(t--) Main();
}
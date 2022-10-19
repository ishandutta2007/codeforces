#include <bits/stdc++.h>
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
const int N=2e5+100;
ll a[N];
ll b[N];
int Main(){
    ll n,m;
    cin >> n >> m;
    vector <int> c;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);

    for (int i=1;i<=n;i++){
        if (i>1) c.pb(a[i]-a[i-1]);
    }
    for (int i=1;i<=m;i++){
        cin >> b[i];
    }
    ll g=0;
    for (auto u : c){
        g=(ll)__gcd(g,(ll)u);
    }
    for (int i=1;i<=m;i++){
        cout << __gcd(g,b[i]+a[1]) << " ";
    }

}
int32_t main(){
    sync;
    ll t;
    t=1;
   // cin >> t;
    while(t--){
        Main();
    }
}
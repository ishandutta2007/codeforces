#include <bits/stdc++.h>
/// 500 485 462 A4
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
const int N=3e5+100;

int Main(){
    vector <int> a,b;
    ll n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        ll x;
        cin >> x;
        x--;
        a.pb(x);
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    for (int i=1;i<=m;i++){
        ll x;
        cin >> x;
        b.pb(x);
    }
    ll ans=0,cnt=0;
    for (int i=0;i<a.size();i++){
        ll u=a[i];
        if (cnt>=a[i]){
            ans+=b[a[i]];
            continue;
        }
        ans+=b[cnt];
        cnt++;
    }
    cout << ans << endl;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}
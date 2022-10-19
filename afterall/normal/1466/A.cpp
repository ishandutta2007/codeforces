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
const int N=2e5+100;
map <int,int> mp;
int Main(){
    mp.clear();
    ll n;
    cin >> n;
    vector <int> a;
    for (int i=1;i<=n;i++){
        ll x;
        cin >> x;
        a.pb(x);
    }
    ll ans=0;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (mp[a[j]-a[i]]==0){
                ans++;
                mp[a[j]-a[i]]=1;
            }
        }
    }
    cout << ans << endl;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while (t--) Main();
}
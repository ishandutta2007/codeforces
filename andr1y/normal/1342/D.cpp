//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
const ll inf  = 43204834389743LL;
ll a[N], ob[N], cnt[N];
vector<ll> ans2[N];
signed main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(ll i = 1;i<=k;i++) cin >> ob[i];
    ll ans = 0, e = 0;
    for(ll i = k;i>0;i--){
        e+=cnt[i];
        ans = max(ans, e/ob[i]+(e%ob[i]?1:0));
    }
    sort(a, a+n);
    for(ll i = 0;i<n;i++){
        ans2[i%ans].push_back(a[i]);
    }
    cout << ans << '\n';
    for(ll i = 0;i<ans;i++){
        cout << ans2[i].size() << ' ';
        for(auto j : ans2[i]) cout << j << ' ';
        cout << '\n';
    }
}
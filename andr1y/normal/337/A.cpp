// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, m;
    cin >> m >> n;
    for(ll i = 0;i<n;i++){
        cin >> a[i];
    }
    sort(a, a+n);
    ll e = 0x3fff3fff3fff3fff;
    for(ll i = m-1;i<n;i++){
        e=min(e, a[i]-a[i-m+1]);
    }
    cout<<e;
}
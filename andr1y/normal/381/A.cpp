// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll c[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, a[2]={0};
    cin >> n;
    for(ll i = 0;i<n;i++){
        cin >> c[i];
    }
    ll l = 0, r = n-1;
    for(ll i = 0;i<n;i++){
        a[i&1]+=(c[l]>c[r]?c[l++]:c[r--]);
    }
    cout<<a[0]<<' '<<a[1]<<'\n';
}
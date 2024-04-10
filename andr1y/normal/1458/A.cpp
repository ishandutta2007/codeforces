// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll a[N], b[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    for(ll i = 0;i<n;i++) cin >> a[i];
    ll d2=0, q;
    for(ll i = 1;i<n;i++) d2=__gcd(d2, abs(a[i]-a[i-1]));
    while(m--){
        cin >> q;
        cout<<__gcd(a[0]+q, d2)<<' ';
    }
}
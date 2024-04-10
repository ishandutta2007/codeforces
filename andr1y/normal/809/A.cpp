//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 3e5+228;
const ll M = 1e9+7;
ll a[N], p[N];
ll bpm(ll a, ll b){
    if(b == 0) return 1;
    if(b == 1) return a;
    if(b&1) return (a*bpm((a*a)%M, b>>1))%M;
    else return bpm((a*a)%M, b>>1);
}
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for(ll i =0;i<n;i++) cin >> a[i];
    sort(a, a+n);
    p[0] = a[0];
    for(ll i = 1;i<n;i++) p[i] = (p[i-1]+a[i])%M;
    ll res = 0;
    for(ll k = 2;k<=n;k++){
        ll sk = (M+M+p[n-1]-p[k-2]-p[n-k])%M;
        ll s2 = bpm(2, k-2);
        res += (sk*s2)%M;
        res %= M;
    }
    cout << res << '\n';
}
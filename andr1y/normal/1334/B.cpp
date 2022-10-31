//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, x;
        cin >> n >> x;
        for(ll i =0;i<n;i++) cin >> a[i];
        sort(a, a+n, greater<ll>());
        ll sbx = 0;
        ll i = 0;
        for(;i<n;i++){
            if(a[i]>=x) sbx+=a[i];
            else break;
        }
        while(i<n && sbx+a[i] >= x*(i+1)) sbx+=a[i++];
        cout<<i<<'\n';
    }
}
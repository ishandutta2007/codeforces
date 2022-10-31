//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll a[N], b[N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, k;
        cin >> n >> k;
        for(ll i = 0;i<n;i++) cin >> a[i];
        b[0] = 0;
        for(ll i = 1;i<n-1;i++){
            b[i] = b[i-1]+(a[i]>a[i-1]&&a[i]>a[i+1]?1:0);
        }
        ll mv= 0, mp = 0;
        for(ll i = 0;i<n-k+1;i++){
            ll v= b[i+k-2]-b[i]+1;
            if(v>mv){
                mv=v;
                mp = i;
            }
        }
        cout << mv << ' ' << mp+1 << '\n';
    }
}
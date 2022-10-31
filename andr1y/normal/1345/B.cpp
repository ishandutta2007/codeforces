//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;

signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, cnt= 0;
        cin >> n;
        while(n>1){
            ll l = 0, r = 1e9;
            while(r-l>1){
                ll m = (l+r)>>1;
                ll v = ((m*(m+1))/2)*3-m;
                if(v > n) r = m;
                else l = m;
            }
            ll v = ((l*(l+1))/2)*3-l;
            n-=v;
            cnt++;
        }
        cout << cnt << '\n';
    }
}
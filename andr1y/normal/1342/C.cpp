//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 228*228;
ll o[N], p[N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll a, b, q2;
        cin >> a >> b >> q2;
        if(a>b) swap(a, b);
        ll n = a*b;
        for(ll i = 0;i<n;i++){
            o[i] = (i%a==(i%b)%a?1:0);
            p[i] = (i?p[i-1]:0)+o[i];
        }
        while(q2--){
            ll l, r;
            cin >> l >> r;
            ll bl = l/n, br = r/n, bad = 0;
            ll pl = l%n, pr = r%n;
            if(bl == br) bad = p[pr]-(pl?p[pl-1]:0);
            else if(bl+1 == br) bad = p[pr]+p[n-1]-(pl?p[pl-1]:0);
            else bad = p[pr]+p[n-1]-(pl?p[pl-1]:0)+p[n-1]*(br-bl-1);
            cout << r-l+1-bad << ' ';
        }
        cout << '\n';
    }
}
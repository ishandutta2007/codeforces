// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    ll n = s.length();
    for(ll i = 0;i+1<n;i++){
        ll e = (s[i]==s[i+1]?1:0);
        a[i]=(i?a[i-1]:0)+e;
    }
    ll q;
    cin >> q;
    while(q--){
        ll l, r;
        cin >> l >> r;
        --l, r--;
        cout<<a[r-1]-(l?a[l-1]:0)<<'\n';
    }
}
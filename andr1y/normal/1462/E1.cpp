// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 3e5+228;
const ll M = 1e9+7;
ll a[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, m, k;
        cin >> n;
        for(ll i = 0;i<n;i++) cin >> a[i];
        sort(a, a+n);
        k=2, m=3;
        ll l =0;
        ll res=0;
        for(ll r=0;r<n;r++){
            while(a[r]-a[l]>k) l++;
            if(r-l+1>=m){
                res+=(r-l)*(r-l-1);
            }
        }
        res>>=1;
        cout<<res<<'\n';
    }
}
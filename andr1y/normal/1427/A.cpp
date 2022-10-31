// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, s=0;
        cin >> n;
        for(ll i =0;i<n;i++){
            cin >> a[i];
            s+=a[i];
        }
        if(s==0){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
            if(s>0) sort(a, a+n, greater<ll>());
            else sort(a, a+n);
            for(ll i = 0;i<n;i++) cout<<a[i]<<' ';
            cout<<'\n';
        }
    }
}
// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin>>q;
    while(q--){
        ll n;
        cin>>n;
        for(ll i =0;i<n;i++) cin >> a[i];
        cout<<n*3<<'\n';
        for(ll i = 0;i<n;i+=2){
            ll j = i+1;
            cout<<"1 "<<i+1<<' '<<j+1<<'\n';
            cout<<"2 "<<i+1<<' '<<j+1<<'\n';
            cout<<"1 "<<i+1<<' '<<j+1<<'\n';
            cout<<"2 "<<i+1<<' '<<j+1<<'\n';
            cout<<"1 "<<i+1<<' '<<j+1<<'\n';
            cout<<"2 "<<i+1<<' '<<j+1<<'\n';
        }
    }
}
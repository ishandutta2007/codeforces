// keep calm and eat pizza.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll a[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll q;
	cin >> q;
	while(q--){
        ll n, c0=0, c1=0;
        cin >> n;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            if(a[i]) c1++;
            else ++c0;
        }
        if(c0+c0>=n){
            cout<<c0<<'\n';
            for(ll i = 0;i<c0;i++) cout<<"0 ";
            cout<<'\n';
        }else{
            if(c1&1){
                ll e0=0;
                cout<<c1-(c1&1)<<'\n';
                for(ll i  =0;i<c1-(c1&1);i++) cout<<"1 ";
                cout<<'\n';
            }else{
                cout<<c1<<'\n';
                for(ll i = 0;i<c1;i++) cout<<"1 ";
                cout<<'\n';
            }
        }
	}
}
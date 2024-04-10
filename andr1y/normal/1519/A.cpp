// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll r, b, d;
        cin >> r>>b >> d;
        if(d==0){
            if(r==b) cout<<"YES\n";
            else cout<<"no\n";
        }else{
            if(r>b) swap(r, b);
            ll e = (b-r+d-1)/d;
            if(r>=e) cout<<"YES\n";
            else cout<<"no\n";
        }
    }
}
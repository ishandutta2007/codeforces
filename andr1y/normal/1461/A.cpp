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
        ll n, k;
        cin >> n >> k;
        for(ll i = 0;i<n;i++){
            if(i%3==0) cout<<'b';
            if(i%3==1) cout<<'a';
            if(i%3==2) cout<<'c';
        }
        cout<<'\n';
    }
}
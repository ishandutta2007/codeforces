// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
vector<ll> ec;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    for(ll a = 3;(a*a+1)<=2000000000;a+=2){
        ec.push_back((a*a+1)/2);
    }
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        cout<<upper_bound(begin(ec), end(ec), n)-ec.begin()<<'\n';
    }
}
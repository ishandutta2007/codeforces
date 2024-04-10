// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for(ll i = 0;i<n;i++){
        ll k = abs(n/2-i);
        for(ll j = 0;j<k;j++) cout<<'*';
        for(ll j = 0;j<n-k-k;j++) cout<<'D';
        for(ll j = 0;j<k;j++) cout<<'*';
        cout<<'\n';
    }
}
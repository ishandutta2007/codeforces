// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, mx=0;
    cin >> n;
    for(ll a, i=0;i<n;i++){
        cin >> a;
        mx=max(mx, a);
    }
    cout<<mx;
}
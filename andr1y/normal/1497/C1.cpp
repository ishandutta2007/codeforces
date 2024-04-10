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
        if(__builtin_popcount(n)==1) cout<<(n/2)<<' '<<(n/4)<<' '<<(n/4)<<'\n';
        else{
            ll e = n&-n;
            cout<<e<<' '<<(n-e)/2<<' '<<(n-e)/2<<'\n';
        }
    }
}
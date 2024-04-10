// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;cin>>q;while(q--){
        ll n, m, k;
        cin >> n >> m >> k;
        if(k==n*m-1) cout<<"yes\n";
        else cout<<"no\n";
    }
}
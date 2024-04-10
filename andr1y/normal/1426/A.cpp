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
        ll n, x;
        cin >> n >> x;
        if(n<=2) cout<<"1\n";
        else{
            n-=2;
            cout<<(n-1)/x+2<<'\n';
        }
    }
}
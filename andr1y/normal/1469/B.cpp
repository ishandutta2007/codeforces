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
        ll n, m;
        cin >> n;
        ll mv1 = 0, s=0;
        for(ll a, i = 0;i<n;i++){
            cin >> a;
            s+=a;
            mv1=max(mv1, s);
        }
        ll mv2=0;
        s=0;
        cin >> m;
        for(ll a, i=0;i<m;i++){
            cin >> a;
            s+=a;
            mv2=max(mv2, s);
        }
        cout<<mv1+mv2<<'\n';
    }
}
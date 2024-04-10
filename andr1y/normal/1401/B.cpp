#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll q;
	cin >> q;
	while(q--){
        ll c0, c1, c2, d0, d1, d2;
        cin >> c0 >> c1 >> c2 >> d0 >> d1 >> d2;
        ll pm = min(c2, d1);
        c2-=pm, d1-=pm;
        ll z0 = min(d2, c2);
        d2-=z0, c2-=z0;
        z0 = min(d2, c0);
        d2-=z0, c0-=z0;
        ll z1 = min(c1, d1);
        c1-=z1, d1-=z1;
        z1 = min(c1, d0);
        c1-=z1, d0-=z1;
        ll mm = min(c1, d2);
        cout<<(pm-mm)*2<<'\n';
	}
}
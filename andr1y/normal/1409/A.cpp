// keep calm and eat pizza.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll q;
	cin >> q;
	while(q--){
        ll a, b;
        cin >> a >> b;
        ll c = abs(b-a);
        cout<<(c+9)/10<<'\n';
	}
}
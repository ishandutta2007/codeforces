#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll q;
	cin >> q;
	while(q--){
        ll n, k;
        cin >> n >> k;
        ll sh =0;
        if(n<k){
            sh=k-n;
            n=k;
        }
        n-=k;
        if(n&1) sh++;
        cout<<sh<<'\n';
	}
}
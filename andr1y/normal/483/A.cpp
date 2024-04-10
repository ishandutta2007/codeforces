// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll l, r;
    cin >> l >> r;
    if(r-l+1<3||(r-l+1==3&&__gcd(l, r)==1)){
        cout<<"-1\n";
    }else{
        if(__gcd(l, l+2)!=1) cout<<l<<' '<<l+1<<' '<<l+2<<'\n';
        else cout<<l+1<<' '<<l+2<<' '<<l+3<<'\n';
    }
}
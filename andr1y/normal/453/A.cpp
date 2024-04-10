// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll m, n;
    cin >> m >> n;
    ld res=m;
    for(ll i = 1;i<m;i++){
        res-=pow((ld)i/m, n);
    }
    cout<<fixed<<setprecision(10)<<res;
}
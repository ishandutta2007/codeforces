// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll N = 1e5+228;
const ld EPS = 1e-7;
const ld Pi = 3.1415926535897932384626433832795;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, R, r;
    cin >> n >> R >> r;
    if(n==1){
        if(R>=r) cout<<"YES\n";
        else cout<<"NO\n";
        return 0;
    }
    ld uu = 2*(R-r)*sin(Pi/n);
    if(r+r<uu+EPS) cout<<"YES\n";
    else cout<<"NO\n";
}
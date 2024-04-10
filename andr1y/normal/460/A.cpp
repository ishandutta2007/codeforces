// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    ll res=0;
    while(n>=m){
        ll k = n/m;
        res+=k*m;
        n-=k*m;
        n+=k;
    }
    res+=n;
    cout<<res;
}
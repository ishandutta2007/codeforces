// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll N = 1e5+228;
ll a[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    cout<<fixed<<setprecision(10);
    while(q--){
        ll n, m;
        cin >> n >> m;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
        }
        ll ss=n-1;
        while(ss>=0&&a[ss]==ss+1) ss--;
        ld r=1, ver;
        for(ll i = 0;i<m;i++){
            ll pr;
            cin >> pr >> ver;
            pr--;
            ver=1-ver;
            if(pr>=ss) r*=ver;
        }
        if(ss<0) r=0;
        r=1-r;
        cout<<r<<'\n';
    }
}
// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 228;
ll a[N][2][2];
map<pair<pair<ll, ll>, pair<ll, ll>>, bool> ee;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll q;
	cin >> q;
	while(q--){
        ee.clear();
        ll n, m;
        cin >> n >> m;
        bool ok  =0;
        bool o2  =0;
        for(ll i = 0;i<n;i++){
            cin >> a[i][0][0] >> a[i][0][1] >> a[i][1][0] >> a[i][1][1];
            pair<pair<ll, ll>, pair<ll, ll>> vok = {{a[i][0][0], a[i][0][1]}, {a[i][1][0], a[i][1][1]}};
            pair<pair<ll, ll>, pair<ll, ll>> vin = {{a[i][0][0], a[i][1][0]}, {a[i][0][1], a[i][1][1]}};
            ee[vin]=1;
            if(ee.count(vok)) ok =1;
            if(a[i][0][1]==a[i][1][0]) o2=1;
        }
        ok = ok && ((m&1)==0);
        if(ok&&o2)cout<<"YES\n";
        else cout<<"NO\n";
	}
}
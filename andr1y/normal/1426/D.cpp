// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll a[N];
map<ll, ll> pv;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n;
	cin >> n;
	for(ll i = 0;i<n;i++){
        cin >> a[i];
	}
	ll pf = a[0], r=0;
	pv[pf]=1;
	pv[0]++;
	for(ll i = 1;i<n;i++){
        pf+=a[i];
        if(pv[pf]){
            pf=a[i];
            pv.clear();
            ++r;
            pv[0]++;
        }
        pv[pf]++;
	}
	cout<<r;
}
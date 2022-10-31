//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll a[N];
ll st[N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll n, m, sa = 0;
	cin >> n >> m;
	for(ll i =0;i<m;i++){
		cin >> a[i];
		sa+=a[i];
	}
	ll lp = n+1;
	bool ok = 1;
	if(sa<n){
		cout << "-1\n";
		return 0;
	}
	for(ll i = m-1;i>=0;i--){
		ll k = min(lp-1, n-a[i]+1);
		if(k <= 0){
			ok = 0;
			break;
		}
		st[i] = k;
		lp = k;
	}
	if(!ok || sa < n){
		cout << "-1\n";
		return 0;
	}
	ll stn = 0;
	for(ll i = 0;i<m;i++){
		if(st[i] <= stn+1) break;
		st[i] = stn+1;
		stn+=a[i];
	}
	for(ll i = 0;i<m;i++) cout << st[i] << ' ';
}
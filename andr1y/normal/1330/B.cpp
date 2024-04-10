//password1488
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const ll N = 2e5+228;
ll a[N];
ll cnt1[N], cnt2[N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll q;
	cin >> q;
	while(q--){
		ll n;
		cin >> n;
		bool ok = 1;
		ll c2 = 0;
		ordered_set sx1, sx2;
		for(ll i = 1;i<=n;i++){
			cnt1[i] = cnt2[i] = 0;
		}
		for(ll i = 0;i<n;i++){
			cin >> a[i];
			if(i){
				cnt2[a[i]]++;
				if(cnt2[a[i]] == 2) c2++;
				if(cnt2[a[i]] > 2) ok = 0;
				if(cnt2[a[i]] == 1) sx2.insert(a[i]);
			}
			else{
				cnt1[a[i]]++;
				if(cnt1[a[i]] == 1) sx1.insert(a[i]);
			}
		}
		if(!ok){
			cout << "0\n";
			continue;
		}
		vector<pair<ll, ll>> sp;
		if(sx1.size() == 1 && *sx1.find_by_order(0) == 1 && sx2.size() == n-1 && *sx2.find_by_order(n-2) == n-1){
			sp.push_back({1, n-1});
		}
		for(ll i = 2;i<=n-1;i++){
			ll j = i-1;
			cnt1[a[j]]++;
			if(cnt1[a[j]]>1) break;
			sx1.insert(a[j]);
			cnt2[a[j]]--;
			if(cnt2[a[j]] == 0) sx2.erase(a[j]);
			if(sx1.size() == i && *sx1.find_by_order(i-1) == i && sx2.size() == n-i && *sx2.find_by_order(n-i-1) == n-i){
				sp.push_back({i, n-i});
			}
		}
		cout<<sp.size()<<'\n';
		for(auto i : sp) cout << i.first << ' ' << i.second << '\n';
	}
}
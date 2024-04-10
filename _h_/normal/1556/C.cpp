#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef long long ll;

ll calc(ll sum, ll l, ll r){
	if(l > r) swap(l, r);
	if(sum > r) sum = l+r - sum;
	if(sum < 0) return 0;
	return min(sum+1, l+1);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	unsigned long long ans = 0;

	vector<ll> cs(n);
	trav(c, cs) cin >> c;

	for(int i = 0; i < n; i += 2){
		ll mx = cs[i], mn = 1;
		ll cur = 1;
		for(int j = i+1; j < n; ++j){
			if(j % 2){
				ans += max(0ll, min(cs[j] - cur, mx - mn) + 1);	
			}	
			cur += (j % 2 ? -1 : 1) * cs[j];
			if(cur < 0){
				mn -= cur;
				cur = 0;
			}
			if(mn > mx) break;
		}
	}
	cout << ans << endl;
}
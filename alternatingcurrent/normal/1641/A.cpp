#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll T;
ll n, x;
map<ll, int> cnt;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cnt.clear();
		cin >> n >> x;
		rep(i, n){
			ll a;
			cin >> a;
			cnt[a]++;
		}
		ll ans = 0;
		for(map<ll, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
//			cout << it->first << "] = " << it->second << endl;
			if(cnt.count(it->first * x)){
				int val = min(it->second, cnt[it->first * x]);
				ans += it->second - val;
				cnt[it->first] -= val;
				cnt[it->first * x] -= val;
			} else 
				ans += it->second;
		}
		cout << ans << endl;
	}
	return 0;
}
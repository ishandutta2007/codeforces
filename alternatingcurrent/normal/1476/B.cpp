#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int t;
int n; ll k;
ll p[111];

int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n >> k;
		rep(i, n) cin >> p[i];
		ll sum = p[0];
		ll ans = 0;
		for(int i = 1; i < n; i++){
			ll target = p[i] * 100LL;
			target = (target + k - 1) / k;
			ans = max(ans, target - sum);
			sum += p[i];
		}
		cout << ans << endl;
	}
	return 0;
}
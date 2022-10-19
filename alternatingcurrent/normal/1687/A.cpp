#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll Mod = 998244353;

int T;
int n;
ll k; 
ll a[200200];
ll sum[200200];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> k;
		rep(i, n)
			cin >> a[i];
		sum[0] = 0;
		rep(i, n)
			sum[i + 1] = sum[i] + a[i];
		if(k <= n){
			ll ans = 0;
			for(int i = 0; i + k <= n; i++){
				ans = max(ans, sum[i + k] - sum[i]); 
			}
			ans += 1ll * k * (k - 1) / 2;
			cout << ans << endl;
		} else {
			cout << sum[n] + 1ll * ((k - 1) + (k - n)) * n / 2ll << endl;
		}
	}
	return 0;
}
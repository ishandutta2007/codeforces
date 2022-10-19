#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
ll n, k;
int a[12];
ll pow10[22];

int main(){
	pow10[0] = 1;
	rep(i, 19)
		pow10[i + 1] = pow10[i] * 10LL;
	ios::sync_with_stdio(false);
	cin >> T;
	while(T --> 0){
		cin >> n >> k;
		k++;
		rep(i, n)
			cin >> a[i];
		ll ans = 0;
		rep(i, n - 1){
			ll val = min(k, pow10[a[i + 1] - a[i]] - 1);
			ans += val * pow10[a[i]];
			k -= val;
		}
		ans += pow10[a[n - 1]] * k;
		cout << ans << endl;
	}
	return 0;
}
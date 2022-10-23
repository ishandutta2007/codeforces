# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200051;
int t, n, k;
int a[MAXN];
ll s[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--){
		cin >> n >> k;
		ll ans = 1ll * k * min(n, k) - 1ll * min(n, k) * (min(n, k) + 1) / 2;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			s[i] = s[i - 1] + a[i];
		}
		k = min(n, k);
		ll ans2 = 0;
		for (int i = k; i <= n; i++) ans2 = max(ans2, s[i] - s[i - k]);
		cout << ans + ans2 << '\n';
	}
	return 0;
}
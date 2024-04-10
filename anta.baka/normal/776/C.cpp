#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<ll> pf(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		pf[i] = a[i];
		if(i)
			pf[i] += pf[i - 1];
	}
	ll ans = 0;
	ll pw = 1;
	while(llabs(pw) <= 1LL * n * 1000000000) {
		map<ll, int> cnt;
		cnt[0] = 1;
		for(int i = 0; i < n; i++) {
			cnt[pf[i]]++;
			ans += cnt[pf[i] - pw];
		}
		if(k == 1 || (k == -1 && pw == -1))
			break;
		pw *= k;
	}
	cout << ans;
}
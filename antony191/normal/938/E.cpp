#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <set>
#include <map>


using namespace std;

#define ll long long

const ll mod = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &a[i]);
	vector<ll> fc(n + 1);
	fc[0] = fc[1] = 1;
	for (int i = 1; i <= n; ++i) {
		fc[i] = fc[i - 1] * i;
		if (abs(fc[i]) >= mod)
			fc[i] %= mod;
	}
	vector<int> r(n + 1);
	r[1] = 1;
	for (int i = 2; i <= n; ++i)
		r[i] = (mod - (mod / i) * r[mod % i] % mod) % mod;
	sort(a.begin(), a.end());
	ll sum = 0;
	int l = 0;
	for (int i = 0; i < n && a[i] < a[n - 1]; ++i) {
		if (a[i] != a[l])
			l = i;
		ll x = (ll)l;
		sum += fc[n] * r[n - x] % mod * a[i];
		if (abs(sum) >= mod)
			sum %= mod;
	}
	cout << (sum % mod + mod) % mod;
	return 0;
}
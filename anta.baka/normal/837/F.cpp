#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll k;
vector<ll> a;

int main() {
	cin >> n >> k;
	a.resize(n);
	for(int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		a.push_back(x);
		if(x >= k)
			return cout << 0, 0;
	}
	reverse(a.begin(), a.end());
	while(a.back() == 0)
		a.pop_back();
	reverse(a.begin(), a.end());
	n = a.size();
	if(n == 2)
		return cout << (k - a[1] + a[0] - 1) / a[0], 0;
	if(n == 3) {
		ll bl = 1, br = sqrt(2.0 * k / a[0]) + 1;
		if(a[1])
			br = min(br, k / a[1] + 1);
		while(bl < br) {
			ll bm = (bl + br) / 2;
			if(bm * (bm + 1) / 2 * a[0] + bm * a[1] + a[2] >= k)
				br = bm;
			else
				bl = bm + 1;
		}
		return cout << bl, 0;
	}
	for(int i = 1; ; i++)
		for(int j = 1; j < n; j++) {
			a[j] += a[j - 1];
			if(a[j] >= k)
				return cout << i, 0;
		}
}
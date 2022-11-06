#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

bool f() {

	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;
	sort(a.begin(), a.end());

	bool flip = false;
	for (int i = 0; i + 1 < n; ++i)
		if (a[i] == a[i + 1]) {
			if (flip)
				return false;

			flip = true;
			if(a[i] == 0)
				return false;
			a[i]--;
			if (i > 0) {
				assert(a[i] >= a[i - 1]);
				if (a[i] == a[i - 1])
					return false;
			}
		}

	ll cnt = 0;
	for (int i = 0; i < n; ++i) {
		assert(a[i] >= i);
		cnt += a[i] - i;
	}
	return (cnt & 1) ^ flip;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	bool res = f();
	cout << (res ? "sjfnb" : "cslnb");
	return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 2e5 + 10;
const int mod = 1e9 + 9;
const int base = 11;

int main(){
	ios_base::sync_with_stdio(false);
	vector<ll> a;
	ll now = 1;
	for (int i = 1; i <= 60; i++){
		now ^= (1ll << i);
		for (int j = i - 1; j >= 0; j--)
			a.push_back(now ^ (1ll << j));
	}
	ll l, r;
	cin >> l >> r;
	l = lower_bound(a.begin(), a.end(), l) - a.begin();
	r = upper_bound(a.begin(), a.end(), r) - a.begin();
	cout << r - l << endl;
}
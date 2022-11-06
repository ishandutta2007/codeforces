#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int b, k;
	cin >> b >> k;

	int res = 0;
	for(int i = 0; i < k; ++i) {
		ll x;
		cin >> x;
		if(i == k - 1)
			res ^= x&1;
		else
			res ^= (x&1) * b;
	}
	cout << (res&1 ? "odd" : "even");
	return 0;
}
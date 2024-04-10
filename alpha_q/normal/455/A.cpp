#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 100005;

ll Count[N], DP[N];

ll Call (ll n) {
	if (n == 0) return 0;
	if (n == 1) return Count[1];
	if (DP[n] != -1) return DP[n];
	return DP[n] = max(Call(n - 1), Call(n - 2) + Count[n] * n);
}

int main() {
	memset(DP, -1, sizeof DP);
	memset(Count, 0, sizeof Count);
	ll n, m = 0; cin >> n;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		Count[x]++; 
		m = max(x, m);
	}
	cout << Call(m + 1) << endl;
	return 0;
}
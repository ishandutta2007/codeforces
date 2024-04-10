#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
const ll INF = 3e18;

ll n, l, c[31];

ll rec(ll l) {
	if(l <= 0) return 0;
	ll now;
	for(ll i = 0; i < 31; i++)
		if((1 << i) <= l)
			now = i;

	ll opt = now + 1;
	for(ll i = now + 1; i < 31; i++)
		if(c[i] < c[opt])
			opt = i;

	return min(c[opt], c[now] + rec(l - (1 << now)));
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> l;
	for(int i = 0; i < 31; i++) c[i] = INF;
	for(int i = 0; i < n; i++) cin >> c[i];
	for(int i = 1; i < 31; i++) c[i] = min(2 * c[i - 1], c[i]);
	cout << rec(l);
}
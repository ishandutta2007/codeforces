#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll W;
ll cnt[10];

inline ll mx(set<ll> &s) {
	return *(s.rbegin());
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> W;
	for (int i = 1; i <= 8; ++i)
		cin >> cnt[i];

	set<ll> s = { 0 };

	for (int i = 1; i <= 8; ++i) {
		set<ll> newS;

		const ll M = min(W, mx(s) + i * cnt[i]);

		for(const ll &x : s) {
			ll c = min(cnt[i], (W - x) / i);
			for(; c >= 0; --c) {
				const ll y = x + c*i;
				if(y < M - 100) break;
				newS.insert(y);
			}
		}

		s = move(newS);
	}

	cout << mx(s);

	return 0;
}
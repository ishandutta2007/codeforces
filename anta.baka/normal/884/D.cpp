#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
multiset<ll> sx;
ll ret;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) { int x; cin >> x; sx.insert(x); }
	if(n % 2 == 0) {
		ll w = 0;
		for(int i = 0; i < 2; i++) {
			w += *sx.begin();
			sx.erase(sx.begin());
		}
		ret += w;
		sx.insert(w);
	}
	while(sx.size() != 1) {
		ll w = 0;
		for(int i = 0; i < 3; i++) {
			w += *sx.begin();
			sx.erase(sx.begin());
		}
		ret += w;
		sx.insert(w);
	}
	cout << ret;
}
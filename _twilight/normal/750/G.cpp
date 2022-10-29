#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

const int bzmax = 53, Lmx = 100;

ll sum, ans;
ll pw[bzmax + 3];

void prepare() {
	pw[1] = 1;
	for (int i = 2; i < 54; i++) {
		pw[i] = (pw[i - 1] << 1) | 1;
	}
}

map<ll, ll> G[55][55];
ll dfs(int x, int y, ll v) {
	if (x > y)
		swap(x, y);
	if (v < 0)
		return 0;
	if (!x && !y)
		return !v;
	ll limit = (2ll << x) + (2ll << y) - x - y - 4;
	if (v >= limit) {
		return (v == limit);
	}
	if (G[x][y].count(v)) {
		return G[x][y][v];
	}
	return G[x][y][v] = dfs(x, y - 1, v) + dfs(x, y - 1, v - pw[y]); 
} 

int main() {
	prepare();
	cin >> sum;
	for (int len = 1; len < bzmax; len++) {
		if (sum < pw[len])
			break;
		ll rest = sum % pw[len];
		boolean ok = true;
		for (int i = len - 1; i && ok; i--) {
			if (rest / pw[i] > 1) {
				ok = false;
			}	
			rest %= pw[i];
		}
//		if (ok)
//			cerr << 0 << " " << len - 1 << " " << 1 << '\n';
		if (ok) {
			ans++;
		}
	}
	for (int L = 1; L < 51; L++) {
		for (int R = 1; R <= 51; R++) {
			ll coef = (pw[L + 1] + pw[R + 1]) - 1;
			if (sum < coef) {
				break;
			}
			ll rest = sum % coef - pw[R];
			ans += dfs(L - 1, R - 1, rest);
//			cerr << L << " " << R << " " << dfs(L - 1, R - 1, rest) << '\n';
		}
	}
	cout << ans << '\n';
	return 0;	
}
#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int maxn = 1e5;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int x, d; cin >> x >> d;
	ll cur = 1;
	vector<ll> ans;
	for(int i = 32; i; i--) {
		if((1LL << i) - 1 > x) continue;
		x -= (1LL << i) - 1;
		for(int j = 0; j < i; j++) ans.push_back(cur);
		cur += d;
		i++;
	}
	cout << sz(ans) << '\n';
	for(ll x : ans) cout << x << ' ';
}
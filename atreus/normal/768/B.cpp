#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int mod = 998244353;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	ll n, l, r;
	cin >> n >> l >> r;
	ll answer = 0, x = log2(n);
	for (ll i = l; i <= r; i++){
		int idx = __builtin_ctz(i);
		idx = x - idx;
		if (n & (1ll << idx))
			answer ++;
	}
	cout << answer << endl;
}
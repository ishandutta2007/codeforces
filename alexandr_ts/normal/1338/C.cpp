#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <type_traits>
#include <queue>
#include <cassert>
#include <utility>
#include <functional>
#include <set>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <vector>
#include <memory>
#include <string>
#include <optional>
#include <ostream>
#include <iterator>
#include <new>
#include <cstdlib>
#include <tuple>
#include <unordered_map>
#include <cstring>
#include <array>

#define debug(x) cout << #x << " is " << x << endl;

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 10;
const int N = 1e6 + 10;


int v[N];

void prec() {
	v[1] = 1;
	v[2] = 2;
	v[3] = 3;
	set<int> used = {1, 2, 3};
	for (int i = 4; i < 600; i += 3) {
		int a = 1;
		for (; used.count(a); a++);
		v[i] = a;
		bool fnd = false;
		for (int b = a + 1; !fnd && b < 2000; ++b) {
			if (used.count(b)) continue;
			for (int c = b + 1; !fnd && c < 2000; ++c) {
				if ((a ^ b ^ c) == 0 && !used.count(c)) {
					fnd = true;	
					v[i + 1] = b;
					v[i + 2] = c;
				}	
			}	
		}
		assert(fnd);
		used.insert(v[i]);
		used.insert(v[i + 1]);
		used.insert(v[i + 2]);
	}
	for (int i = 1; i < 450; ++i) {
		cout << i << ": " << v[i] << ", \t";
		if (i % 3 == 0) cout << endl;
	}
}

ll solve(ll n) {
	ll k = 0;
	while ((1ll << (2 + k)) <= n) {
		k += 2;	
	}
	ll pw = (1ll << k);
	ll a = pw + (n - pw) / 3;
	if (n % 3 == 1) return a;
	ll b = 0, c = 0;
	for (ll i = 0; i < 60; i += 2) {
		if (a & (1ll << i))	{
			if (a & (2ll << i)) { // 11
				b += (1ll << i);	
				c += (2ll << i);
			} else { // 01
				b += (2ll << i);
				c += (3ll << i);	
			}
		} else {
			if (a & (2ll << i)) { // 10
				b += (3ll << i);	
				c += (1ll << i);
			} else { // 00 
			}
		}
	}
	if (n % 3 == 2) return b;
	return c;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		cout << solve(n) << "\n";
	}
}
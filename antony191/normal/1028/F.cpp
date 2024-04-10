#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <utility>

#pragma GCC optimize("O3")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi1;
typedef vector<vi1> vi2;
typedef vector<ll> vll1;
typedef vector<vll1> vll2;

const int inf = 1e9;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define all(v) v.begin(), v.end()
#define int ll
int gcd(int a, int b) {
	while (b != 0) {
		a %= b;
		swap(a, b);
	}
	return a;
}
signed main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	unordered_map<ll, set<int>> m;
	unordered_map<ll, int> ans;
	int cnt = 0;
	int q;
	cin >> q;
	while (q--) {
		int tmp;
		cin >> tmp;
		if (tmp < 3) {
			int x, y;
			cin >> x >> y;
			ll w = x * 1ll * x + y * 1ll * y;
			for (auto i = m[w].begin(); i != m[w].end(); ++i) {
				if (*i == x) continue;
				int x1 = *i + x, y1 = sqrt(w - (*i) * (*i)) + y;
				int g = gcd(x1, y1);
				x1 /= g; y1 /= g;
				if (tmp == 1)
					ans[x1 * 1ll * 1000000 + y1] += 2;
				else
					ans[x1 * 1ll * 1000000 + y1] -= 2;
			}
			if (tmp == 1) {
				m[w].insert(x);
				cnt++;
			}
			else {
				m[w].erase(x);
				cnt--;
			}
			int g = gcd(x, y);
			x /= g; y /= g;
			if (tmp == 1)
				ans[x * 1ll * 1000000 + y]++;
			else
				ans[x * 1ll * 1000000 + y]--;
		}
		else {
			int x, y;
			cin >> x >> y;
			int g = gcd(x, y);
			x /= g; y /= g;
			cout << cnt - ans[x * 1ll * 1000000 + y] << '\n';
		}
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}
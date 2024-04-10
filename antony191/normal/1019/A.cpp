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

mt19937 rnd(time(NULL));

signed main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> m >> n;
	vector<int> a(n, 0);
	vector<vector<pair<int, int>>> b(n);
	vector<pair<int, int>> k;
	int mx = 0;
	for (int i = 0; i < m; ++i) {
		int p, c;
		cin >> p >> c;
		p--;
		a[p]++;
		if (p > 0) {
			mx = max(mx, a[p]);
			b[p].push_back({ c, i });
			k.push_back({ c, i });
		}
	}
	for (int i = 0; i < n; ++i) {
		sort(all(b[i]));
	}
	sort(all(k));
	vector<int> pos(m, -1);
	for (int i = 0; i < k.size(); ++i)
		pos[k[i].second] = i;
	if (a[0] > mx)
		return cout << 0, 0;
	ll ans = 1e18, cnt = 0;
	vector<int> l(n, 0);
	vector<int> used(m, 0);
	int curr = 0;
	for (int i = m; i >= a[0] + 1; --i) {
		for (int j = 0; j < n; ++j)
			if (i <= a[j]) {
				curr++;
				cnt += b[j][l[j]].first * 1ll;
				used[pos[b[j][l[j]].second]] = 1;
				l[j]++;
			}
		int cur = curr;
		ll tmp = cnt;
		int r = 0;
		while (i - a[0] > cur) {
			while (used[r]) r++;
			cur++;
			tmp += k[r].first * 1ll;
			r++;
		}
		ans = min(ans, tmp);
	}
	cout << ans;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}
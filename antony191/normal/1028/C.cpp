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

struct pt {
	int x1, y1, x2, y2;
};

pt unite(pt & a, pt & b) {
	pt ans;
	ans.x1 = max(a.x1, b.x1);
	ans.y1 = max(a.y1, b.y1);
	ans.x2 = min(a.x2, b.x2);
	ans.y2 = min(a.y2, b.y2);
	return ans;
}

int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<pt> al(n), pref(n), suf(n);
	for (int i = 0; i < n; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		al[i] = pt{ x1, y1, x2, y2 };
	}
	pref[0] = suf[0] = pt{ -inf, -inf, inf, inf };
	for (int i = 1; i < n; ++i)
		pref[i] = unite(pref[i - 1], al[i - 1]);
	for (int i = n - 1; i; --i)
		suf[n - i] = unite(suf[n - i - 1], al[i]);
	pt ans = pt{ 1, 1, 0, 0 };
	for (int i = 0; i < n; ++i) {
		auto tmp = unite(pref[i], suf[n - 1 - i]);
		if (tmp.x1 <= tmp.x2 && tmp.y1 <= tmp.y2) {
			ans = tmp;
			break;
		}
	}
	cout << ans.x1 << ' ' << ans.y1;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}
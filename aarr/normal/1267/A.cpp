#include <iostream>
#include <algorithm>
#include <set>
#define int long long
using namespace std;

const int N = 200 * 1000 + 5;
const long long inf = 2000ll * 1000 * 1000 * 1000 * 1000 * 1000 + 7;

long long a[N];
long long b[N];
long long t[N];
pair <long long, int> sl[N];
pair <long long, int> sr[N];
pair <long long, long long> c[N];
pair <long long, int> d[N];
set <pair <long long, int> > s1;
set <pair <long long, int> > s2;
int32_t main() {
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> t[i];
		sl[i] = {a[i], i};
		sr[i] = {b[i], i};
		s2.insert({a[i] + t[i], i});
	}
	sort(sl + 1, sl + n + 1);
	sort(sr + 1, sr + n + 1);
	sl[n + 1] = {inf, n + 1};
	sr[n + 1] = {inf, n + 1};
	int L = 0, R = 0;
	long long x = 1, ans = 0;
	s2.insert({inf, n + 2});
	while (R <= n) {
		while (x >= sl[L].first) {
			int y = sl[L].second;
			s2.erase({t[y] + a[y], y});
			s1.insert({t[y], y});
			L++;
			if (L > n + 1)
				break;
		}
		while (x >= sr[R].first) {
			int y = sr[R].second;
			s1.erase({t[y], y});
			R++;
			if (R > n)
				break;
		}
		if (x >= sr[n].first || L > n + 1 || R > n)
			break;
	//	cout << x << " " << L << " " << R << endl;
		if (s1.size() == 0) {
			x = sl[L].first;
			continue;
		}
		pair <int, int> p1 = *(s1.begin()), p2 = *(s2.begin());
		int i = p1.second, j = p2.second;
		while (t[i] + x > b[i]) {
			s1.erase(s1.begin());
			if (s1.size() == 0)
				break;
			p1 = *(s1.begin());
			i = p1.second;
		}
		if (s1.size() == 0) {
			x = sl[L].first;
			continue;
		}
	//	cout << "73 " << x << " " << L << " " << R << endl;
		if (p2.first < x + t[i]) {
			x = sl[L].first;
		//	cout << 49 << " " << x << endl;
		//	ans++;
		}
		else {
			long long r = b[i], l = a[i];
			if (r < sl[L].first) {
			//	cout << "57 " << l << " " << r << endl;
				long long y = (r - x) / t[i];
				ans += y;
				x += y * t[i];
				s1.erase({t[i], i});
			}
			else {
				long long y = (sl[L].first - x) / t[i];
				ans += y;
				x += y * t[i];
				if (x + t[i] <= p2.first && x + t[i] <= r) {
					ans++;
					x += t[i];
				}
			}
		//	if (r < l + t[i]) {
		//		s1.erase({t[i], i});
		//	}
		}
	}
//	cout << x << endl;
	cout << ans << endl;
	return 0;
}
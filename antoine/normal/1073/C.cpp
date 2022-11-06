#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Vec {
	ll x = 0, y = 0;
	Vec operator+(const Vec other) {
		return {x + other.x, y + other.y};
	}
	Vec operator-(const Vec other) {
		return {x - other.x, y - other.y};
	}
	ll norm() {
		return llabs(x) + llabs(y);
	}
};

Vec vec[(int) 2e5 + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		char c;
		cin >> c;
		vec[i] = vec[i - 1];
		switch (c) {
		case 'U':
			vec[i].y++;
			break;
		case 'D':
			vec[i].y--;
			break;
		case 'L':
			vec[i].x--;
			break;
		case 'R':
			vec[i].x++;
			break;
		default:
			assert(false);
		}
	}

	Vec dest;
	cin >> dest.x >> dest.y;

	if((dest - vec[n]).norm()&1) {
		cout << -1;
		return 0;
	}

	int ans = n + 999;
	for (int i = 1; i <= n; ++i) {
		int lo = i - 1;
		int hi = n + 1;
		while(lo < hi) {
			const int mid = (lo + hi) / 2;
			Vec v = dest - vec[i-1] - (vec[n] - vec[mid]);
			if(v.norm() <= mid - i + 1)
				hi = mid;
			else
				lo = mid + 1;
		}
		assert(lo == hi);
		if(lo <= n)
			ans = min(ans, lo - i + 1);
	}
	cout << (ans > n ? -1 : ans);

	return 0;
}
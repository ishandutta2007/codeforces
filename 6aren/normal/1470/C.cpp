#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, k;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

// Vit li hm random  s dng cho thun tin. Hm random ny sinh ngu nhin s trong phm vi long long, s sinh ra >= l v <= h.
long long Rand(long long l, long long h) {
	return l + rand() % (h - l + 1);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;

	int higher = -1;
	int lower = -1;

	int cnt = 0;

	while (true) {
		cnt++;
		int u = Rand(1, n);
		cout << "? " << u << endl;
		int foo;
		cin >> foo;
		if (foo > k) {
			higher = u;
		}
		if (foo < k) {
			lower = u;
		}

		if (cnt == 975) assert(false);

		if (lower != -1 && higher != -1) {
			break;
		}
	}

	if (higher < lower) higher += n;
	while (higher >= lower) {
		cnt++;
		int mid = (higher + lower) / 2;
			
		int foo = mid;

		if (mid > n) foo -= n;
		
		cout << "? " << foo << endl;

		int ans = 0;
		cin >> ans;

		if (ans > k) {
			higher = mid - 1;
		} else if (ans < k) {
			lower = mid + 1;
		} else {
			ans = mid;
			cout << "! " << foo << endl;
			exit(0);
		}
	}

	return 0;
}
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> samepos(n, 0);
	int res = 0;
	int rid = 0;
	int sum;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		res += abs(a[i] - i);
	}
	sum = res;
	int tcnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] <= i) {
			tcnt++;
		}
		samepos[(i - a[i] + n) % n]++;
	}
	for (int i = 1; i < n; i++) {
		tcnt -= samepos[i - 1];
		sum -= tcnt;
		sum += (n - tcnt);
		sum -= (a[i - 1] + 1);
		sum += (n - 1 - a[i - 1]);
		tcnt++;
		if (res > sum) {
			res = sum;
			rid = i;
		}

	}
	cout << res << " " << ((n - rid) % n) <<endl;
	return 0;
}
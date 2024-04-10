#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	int a[3];
	for(int i = 0; i < 3; ++i) {
		a[i] = n / (3 - i);
		n -= a[i];
	}
	sort(a, a + 3, [](const int &x, const int &y) { return x%3 < y%3; });
	const int cnt = count_if(a, a + 3, [](const int &x) { return x%3 == 0; });
	if(cnt == 3) {
		a[0]++;
		a[1]++;
		a[2] -= 2;
	} else if(cnt == 2) {
		a[0]++;
		a[1]--;
	} else if(cnt == 1) {
		if(a[1] % 3 == 2) {
			a[0]++;
			a[1]--;
		} else {
			a[0]--;
			a[1]++;
		}
	}
	for(auto &&x : a)
		cout << x << ' ';
	return 0;
}
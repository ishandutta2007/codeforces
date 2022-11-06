#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int Mx = (int) 4e5;
int a[Mx + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a, a + n);
	int ans = 0;
	for (int i = 0, j = 0; i < n; ++i) {
		while (j < n && a[j] - a[i] <= 5)
			++j;
		ans = max(ans, j - i);
	}

	cout << ans;
	return 0;
}
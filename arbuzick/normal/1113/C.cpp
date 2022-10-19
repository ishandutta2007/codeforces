#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	int i;
	for (i = 0; i < n; i++)
		cin >> a[i];
	vector<int> pr1(n/2 + n % 2), pr2(n / 2 + 1);
	pr1[0] = a[0];
	pr2[0] = pr1[0]^a[1];
	for (i = 2; i < n; i++) {
		if (i % 2 == 0)
			pr1[i / 2] = pr2[i / 2 - 1] ^ a[i];
		else
			pr2[i / 2] = pr1[i / 2] ^ a[i];
	}
	pr2[n / 2] = 0;
	sort(pr1.begin(), pr1.end());
	sort(pr2.begin(), pr2.end());
	long long ans;
	ans = 0;
	long long p;
	p = 1;
	for (i = 1; i < n / 2 + n % 2; i++) {
		if (pr1[i] == pr1[i - 1])
			p += 1;
		else {
			ans = ans + (p - 1) * p / 2;
			p = 1;
		}
	}
	ans = ans + (p - 1) * p / 2;
	p = 1;
	for (i = 1; i < n / 2 + 1; i++) {
		if (pr2[i] == pr2[i - 1])
			p += 1;
		else {
			ans = ans + (p - 1) * p / 2;
			p = 1;
		}
	}
	ans = ans + (p - 1) * p / 2;
	cout << ans;
	return 0;
}
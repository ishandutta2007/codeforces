#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 100;
int a[maxn];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort (a, a + n);
	long long sum = 0;
	for (int i = n - 1; i >= 0; i--)
		if (a[i] > 0)
			sum += a[i];
	if (sum % 2 == 1)
		return cout << sum << endl, 0;
	int q = 1000000;
	for (int i = 0; i < n; i++)
		if (abs(a[i]) % 2 == 1)
			q = min(q, abs(a[i]));
	cout << sum - q << endl;
}
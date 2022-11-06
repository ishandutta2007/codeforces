// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int i = 0, j = n - 1;
	for (; i <= j; ++i)
		if (a[i] > k)
			break;
	for (; i <= j; --j)
		if (a[j] > k)
			break;
	cout << n - (j - i + 1);
	return 0;
}
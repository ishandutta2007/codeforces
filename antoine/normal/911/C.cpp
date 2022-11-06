#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int k1, k2, k3;

bool f(const int x1, const int x2, const int x3) {
	if (x1 && x2 && x3)
		return false;
	vector<int> a(200, 0);
	for (int i = x1; i < a.size(); i += k1)
		a[i] = 1;
	for (int i = x2; i < a.size(); i += k2)
		a[i] = 1;
	for (int i = x3; i < a.size(); i += k3)
		a[i] = 1;
	for (auto &x : a)
		if (!x)
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> k1 >> k2 >> k3;
	for(int x1 = 0; x1 < 25; ++x1)
		for(int x2 = 0; x2 < 25; ++x2)
			for (int x3 = 0; x3 < 25; ++x3) {
				if (f(x1, x2, x3)) {
					cout << "YES";
					return 0;
				}
			}
	cout << "NO";
	return 0;
}
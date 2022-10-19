#include <bits/stdc++.h>

using namespace std;

int main() {
	int k2, k3, k5, k6;
	cin >> k2 >> k3 >> k5 >> k6;
	int res = 0;
	res += min(k2, min(k5, k6)) * 256;
	k2 -= min(k2, min(k5, k6));
	res += min(k2, k3) * 32;
	cout << res;
}
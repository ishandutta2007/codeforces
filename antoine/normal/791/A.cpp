#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a, b;
	cin >> a >> b;
	int ans = 0;
	while (a <= b) {
		a *= 3;
		b *= 2;
		++ans;
	}
	cout << ans;

	return 0;
}
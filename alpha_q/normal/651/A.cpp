#include <bits/stdc++.h>

using namespace std;

long long a, b, ret = 0;

int main() {
	cin >> a >> b;
	while (a > 0 && b > 0) {
		if (a == 1 && b == 1) break;
		if (a > b) a -= 2, b++;
		else b -= 2, a++;
		ret++;
	}
	cout << ret << endl;
	return 0;
}
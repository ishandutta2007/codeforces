#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 1; i <= b; ++i)
		if ((a = (a%b) * 10) / b == c) {
			cout << i;
			return 0;
		}
	cout << -1;
	return 0;
}
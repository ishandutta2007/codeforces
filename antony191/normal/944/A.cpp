#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <bitset>


using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	int l = 0, r = n - 1;
	--a; --b;
	int k = log2(n);
	while (r - l > 1) {
		int m = (l + r) >> 1;
		if (!((a <= m && b <= m) || (a > m && b > m)))
			break;
		--k;
		if (a <= m)
			r = m;
		else
			l = m + 1;
	}
	if (k == log2(n))
		cout << "Final!";
	else
		cout << k;
	return 0;
}
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <array>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x, hh, mm;
	cin >> x >> hh >> mm;
	for (int y = 0;; ++y) {
		if ((mm % 10 == 7 || mm / 10 == 7) || (hh % 10 == 7 || hh / 10 == 7)) {
			cout << y;
			return 0;
		}
		mm -= x;
		while (mm < 0) {
			mm += 60;
			if (--hh < 0)
				hh += 24;
		}
	}
}
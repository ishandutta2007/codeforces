#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

int n;

bool query(const int r1, const int c1, const int r2, const int c2) {
	cout << "? " << r1 + 1 << ' ' << c1 + 1 << ' ' << r2 + 1 << ' ' << c2 + 1 << endl;
	string ans;
	cin >> ans;
	assert(ans == "YES" || ans == "NO");
	return ans == "YES";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;

	string path2;

	int fR = n - 1, fC = n - 1;
	while (fR + fC != n - 1) {
		if (query(0, 0, fR - 1, fC)) {
			fR--;
			path2.push_back('D');
		}
		else {
			fC--;
			path2.push_back('R');
		}
	}
	reverse(path2.begin(), path2.end());

	string path1;
	int sR = 0, sC = 0;
	while (sR + sC != n - 1) {
		if (query(sR, sC + 1, n - 1, n - 1)) {
			sC++;
			path1.push_back('R');
		}
		else {
			sR++;
			path1.push_back('D');
		}
	}
	assert(sR == fR && sC == fC);
	cout << "! " << path1 << path2 << endl;
	return 0;
}
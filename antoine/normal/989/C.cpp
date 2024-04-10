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
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	array<array<char, 50>, 50> grid;
	for (int i = 0; i < 50; ++i)
		for (int j = 0; j < 50; ++j)
			grid[i][j] = i < 25 ? 'A' : 'B';
	--a, --b;


	for(int i = 1; i < 23; i += 2)
		for (int j = 1; j < 50; j += 2) {
			if (b > 0) {
				b--;
				grid[i][j] = 'B';
			}
			else if (c > 0) {
				c--;
				grid[i][j] = 'C';
			}
		}

	for (int i = 28; i < 50; i += 2)
		for (int j = 1; j < 50; j += 2) {
			if (a > 0) {
				a--;
				grid[i][j] = 'A';
			}
			else if (d > 0) {
				d--;
				grid[i][j] = 'D';
			}
		}


	assert(!a && !b && !c && !d);
	cout << "50 50\n";
	for (int i = 0; i < 50; ++i) {
		for (int j = 0; j < 50; ++j)
			cout << grid[i][j];
		cout << '\n';
	}
	return 0;
}
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
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, a, b;
	cin >> n >> a >> b;
	--n, --a, --b;
	int round = 0;
	while (a - b) {
		a >>= 1;
		b >>= 1;
		n >>= 1;
		++round;
	}
	if (n)
		cout << round;
	else
		cout << "Final!";
	return 0;
}
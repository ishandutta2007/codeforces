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

using namespace std;

const int mod = (int)1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long a, b, x, y, z;
	cin >> a >> b >> x >> y >> z;
	a -= x * 2;
	
	a -= y;
	b -= y;

	b -= 3 * z;

	cout << max(0ll, -a) + max(0ll, -b);

	return 0;
}
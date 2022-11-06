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

using namespace std;
typedef long long ll;


int f(ll a, int d) {
	int res = 0;
	while (a%d == 0) {
		a /= d;
		++res;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	while (k--) {
		if (n % 10)
			--n;
		else
			n /= 10;
	}
	cout << n;
	return 0;
}
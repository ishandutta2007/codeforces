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

ll ceil(ll a, ll b) {
	return (a + b - 1) / b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll k, n, s, p;
	cin >> k >> n >> s >> p;
	cout << ceil(k*ceil(n, s), p);


	return 0;
}
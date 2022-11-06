#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <stack>
#include <list>
#include <unordered_map>

using namespace std;

const int mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n, m;
	cin >> n >> m;
	if (n >= 35)
		cout << m;
	else
		cout << (m % (1LL << n));
	return 0;
}
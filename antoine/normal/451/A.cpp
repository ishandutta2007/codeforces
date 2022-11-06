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
#include <queue>

using namespace std;

const int mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	cout << ((min(n, m) & 1) ? "Akshat" : "Malvika");
	return 0;
}
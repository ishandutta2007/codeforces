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

string s;

int f(int x) {
	x = abs(x);
	return x * (x + 1) / 2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	cin >> a >> b;
	int mid = (a + b) / 2;
	cout << f(mid - a) + f(mid - b);
	return 0;
}
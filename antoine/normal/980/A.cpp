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

bool f() {

	string s;
	cin >> s;
	int c1 = count(s.begin(), s.end(), 'o');
	int c2 = count(s.begin(), s.end(), '-');
	if (!c1 || !c2) return true;
	return c2 % c1 == 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << (f() ? "YES" : "NO");
	return 0;
}
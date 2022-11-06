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
#include <assert.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	string s;
	cin >> n >> s;
	if (s == "0")
		cout << 0;
	else {
		s.erase(remove(s.begin(), s.end(), '1'), s.end());
		cout << 1 << s;
	}

	return 0;
}
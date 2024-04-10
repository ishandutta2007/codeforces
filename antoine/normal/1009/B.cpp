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
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	string s;
	cin >> s;
	
	int cnt1 = count(s.begin(), s.end(), '1');
s.erase(remove(s.begin(), s.end(), '1'), s.end());

	const int mid = find(s.begin(), s.end(), '2') - s.begin();
	cout << s.substr(0, mid);
	for (int i = 0; i < cnt1; ++i)
		cout << 1;
	cout << s.substr(mid);
	return 0;
}
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

int n, k;
string ans[50];
bool given[50];

string randStr() {
	string res;
	for (int i = 0; i < 10; ++i)
		res += 'a' + rand() % 26;
	res[0] += 'A' - 'a';
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	int firstYes = n;
	for (int i = 0; i < n - k + 1; ++i) {
		string s;
		cin >> s;
		given[i] = s == "YES";
		if (given[i])
			firstYes = min(firstYes, i);
	}
	if (firstYes == n) {
		for (int i = 0; i < n; ++i)
			cout << "A ";
		return 0;
	}
	for (int i = firstYes; i < firstYes + k; ++i)
		ans[i] = randStr();
	for (int i = firstYes - 1; i >= 0; --i)
		ans[i] = ans[i + 1];
	for (int i = firstYes + 1; i < n - k + 1; ++i)
		if (given[i])
			ans[i + k - 1] = randStr();
		else
			ans[i + k - 1] = ans[i];
	for (int i = 0; i < n; ++i)
		cout << ans[i] << ' ';
	return 0;
}
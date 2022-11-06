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

int choice[10];
long double fact[100];

bool zero() {
	for (int i = 1; i <= 9; ++i)
		if (choice[i])
			return false;
	return true;
}

ll multi() {
	int sum = accumulate(choice, choice + 10, 0);
	long double res = fact[sum];
	for (int i = 0; i <= 9; ++i)
		if (choice[i])
			res /= fact[choice[i]];
	return (ll)(res + .01);
}

int occ[10] = { 0 };

ll f(int i) {
	if (i == 10) {
		if (zero())
			return 1;
		ll ans = 0;
		for (int i = 1; i <= 9; ++i)
			if (choice[i]) {
				--choice[i];
				ans += multi();
				++choice[i];
			}
		return ans;
	}
	else {
		if (!occ[i]) {
			choice[i] = 0;
			return f(i + 1);
		}
		else {
			ll ans = 0;
			for (choice[i] = 1; choice[i] <= occ[i]; ++choice[i])
				ans += f(i + 1);
			return ans;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	fact[0] = 1;
	for (int i = 1; i < 100; ++i)
		fact[i] = fact[i - 1] * i;

	string s;
	cin >> s;
	for (char c : s)
		++occ[c - '0'];
	cout << f(0);
	return 0;
}
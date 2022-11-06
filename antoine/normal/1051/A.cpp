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


char A[] = { 'a', 'A', '0' };

int type(char c) {
	if ('a' <= c && c <= 'z') return 0;
	if ('A' <= c && c <= 'Z') return 1;
	if ('0' <= c && c <= '9') return 2;
}

string f(string s) {
	int occ[3] = { 0, 0, 0 };
	for (char c : s)
		++occ[type(c)];
	
	
	const int cnt = (occ[0] != 0) + (occ[1] != 0) + (occ[2] != 0);

	if (cnt == 3) return s;
	if (cnt == 2) {
		int t = 0;
		while (occ[t] < 2) ++t;

		for(char &c : s)
			if (occ[type(c)] >= 2) {
				int r = 0;
				while (occ[r]) ++r;
				c = A[r];
				return s;
			}
		assert(false);
	}

	assert(cnt == 1);
	for (int i = 1; i <= 2; ++i)
		s[i] = A[(type(s[i]) + i) % 3];
	return s;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << f(s) << endl;
	}
	return 0;
}
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

	int n;
	string s;
	cin >> n >> s;

	int state = 1;
	int ans1 = 0, ans2 = 0;

	int curr1 = 0;
	bool curr2 = false;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			assert(state == 1);
			state = 2;
			ans1 = max(ans1, curr1);
			curr1 = 0;
		}
		else if (s[i] == ')') {
			assert(state == 2);
			state = 1;
			ans2 += curr2;
			curr2 = false;
		}
		else if (state == 1) {
			if (s[i] == '_') {
				ans1 = max(ans1, curr1);
				curr1 = 0;
			}
			else
				curr1++;
		}
		else if(state == 2) {
			if (s[i] == '_') {
				ans2 += curr2;
				curr2 = 0;
			}
			else
				curr2 = true;
		}
		else
			assert(false);
	}
	ans1 = max(ans1, curr1);
	ans2 += curr2;
	cout << ans1 << ' ' << ans2;
	return 0;
}
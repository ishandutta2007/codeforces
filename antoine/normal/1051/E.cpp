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

// Fills Z array for given string str[]
void getZarr(const string &str, int Z[])
{
	int n = str.length();
	int L, R, k;

	// [L,R] make a window which matches with prefix of s
	L = R = 0;
	for (int i = 1; i < n; ++i)
	{
		// if i>R nothing matches so we will calculate.
		// Z[i] using naive way.
		if (i > R)
		{
			L = R = i;

			// R-L = 0 in starting, so it will start
			// checking from 0'th index. For example,
			// for "ababab" and i = 1, the value of R
			// remains 0 and Z[i] becomes 0. For string
			// "aaaaaa" and i = 1, Z[i] and R become 5
			while (R < n && str[R - L] == str[R])
				R++;
			Z[i] = R - L;
			R--;
		}
		else
		{
			// k = i-L so k corresponds to number which
			// matches in [L,R] interval.
			k = i - L;

			// if Z[k] is less than remaining interval
			// then Z[i] will be equal to Z[k].
			// For example, str = "ababab", i = 3, R = 5
			// and L = 2
			if (Z[k] < R - i + 1)
				Z[i] = Z[k];

			// For example str = "aaaaaa" and i = 2, R is 5,
			// L is 0
			else
			{
				// else start from R and check manually
				L = i;
				while (R < n && str[R - L] == str[R])
					R++;
				Z[i] = R - L;
				R--;
			}
		}
	}
}

// prints all occurrences of pattern in text using Z algo
void search(const string &text, const string &pattern, int Z[])
{
	// Create concatenated string "P$T"
	string concat = pattern + text;
	int l = concat.length();

	// Construct Z array
	getZarr(concat, Z);

	for (int i = 0; i < (int)text.size(); ++i)
		Z[i] = Z[i + (int)pattern.size()];

}

const int mod = 998244353;

string a, l, r;
int Z1[(int)2e6 + 5];
int Z2[(int)2e6 + 5];
ll cs[1000000 + 2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> a >> l >> r;

	search(a, l, Z1);
	search(a, r, Z2);

	cs[a.size()] = 1;
	for (int i = (int)a.size() - 1; i >= 0; --i) {

		const ll curr = [&](const int &i) {
			if (a[i] == '0') return l != "0" ? 0 : cs[i + 1] - cs[i + 2];
			int lo = i + (int)l.size();
			int hi = i + (int)r.size();

			if (lo > (int)a.size()) return 0LL;
			if (Z1[i] < (int)l.size() && a[i + Z1[i]] < l[Z1[i]]) lo++;

			if (hi > (int)a.size())
				hi = (int)a.size();
			else {
				if (Z2[i] < (int)r.size()) {
					if (a[i + Z2[i]] > r[Z2[i]]) {
						hi--;
					}
				}
			}

			if (lo > hi) return 0LL;
			return cs[lo] - cs[hi + 1];
		}(i);

		cs[i] = (curr + cs[i + 1]) % mod;
	}

	const ll ans = ((cs[0] - cs[1]) % mod + mod) % mod;
	cout << ans << '\n';
	return 0;
}
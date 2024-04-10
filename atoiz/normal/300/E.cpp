/*input
10 1 1 1 1 1 1 1 1 2 1
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

const int MAXV = 1e7 + 7;
const int64_t INF = 1e15;
int64_t cnt[MAXV];
bool notPrime[MAXV];

int read()
{
	int ans = 0; register char ch = getchar();
	for (; ch == ' ' || ch == '\n'; ch = getchar());
	for (; 47 < ch && ch < 58; ch = getchar()) ans = ans * 10 + ch - 48;
	return ans;
}

int64_t mul(int64_t x, int64_t y)
{
	return (INF / x < y ? INF : x * y);
}

int64_t calc(int64_t x, int i)
{
	int64_t ans = 0;
	for (int64_t pw = i; pw <= x; pw = mul(pw, i)) {
		ans += x / pw;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 2; i < MAXV; ++i) {
		if (notPrime[i]) continue;
		for (int j = i + i; j < MAXV; j += i) notPrime[j] = 1;
	}

	int n = read();
	for (int i = 0; i < n; ++i) {
		++cnt[read()];
	}

	int64_t lo = 1, hi;
	for (int i = MAXV - 2; i >= 2; --i) {
		cnt[i] += cnt[i + 1];
		if (notPrime[i]) continue;

		int64_t x = 0;

		for (int64_t pw = i; pw < MAXV; pw = mul(pw, i)) {
			for (int64_t j = pw; j < MAXV; j += pw) {
				x += cnt[j];
			}
		}

		if (x <= calc(lo, i)) continue;

		hi = (int64_t) MAXV * n;

		while (lo < hi) {
			int64_t mid = (lo + hi) >> 1;

			if (x <= calc(mid, i)) hi = mid;
			else lo = mid + 1;
		}
	}

	cout << lo << endl;
}
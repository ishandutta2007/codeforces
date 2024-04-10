#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_set>

using namespace std;

#ifdef LOCAL
int64_t __N, __C;
unordered_set<int64_t> __S;
#endif

bool ask(int64_t cur)
{
	cout << "? " << cur << endl;

	#ifdef LOCAL
	assert(__S.find(cur) == __S.end());
	assert(1 <= cur && cur <= __N);
	__S.insert(cur);
	static int64_t __last = 0;
	bool __ans = abs(cur - __last) >= __C;
	__last = cur;
	return __ans;

	#else
	int ans;
	cin >> ans;
	return ans;

	#endif
}

void answer(int64_t ans)
{
	cout << "= " << ans << endl;

	#ifdef LOCAL
	assert(ans == __C);
	#endif
}

int T;

void solve(int64_t N)
{
	if (N == 1) return answer(1);
	vector<int64_t> vec;
	for (int64_t x = N - 1; x > 0; x /= 2) vec.push_back(x - x / 2);
	int64_t cur = 1;
	for (int i = 0; i < (int) vec.size(); i += 2) cur += vec[i];
	ask(cur);
	int64_t ans = 0;
	for (int i = 0; i < (int) vec.size(); ++i) {
		if (i & 1) cur += ans + vec[i];
		else cur -= ans + vec[i];
		if (!ask(cur)) ans += vec[i];
		else if (vec[i] == 1) break;
	}
	answer(ans + 1);
}

int main()
{
	#ifdef LOCAL
	for (__N = 1; __N <= 125; ++__N) {
		for (__C = 1; __C <= __N; ++__C) {
			__S.clear();
			cout << "solve " << __N << ' ' << __C << endl;
			solve(__N);
		}
	}
	#endif

	cin >> T;
	while (T--) {
		int64_t N;
		cin >> N;

		#ifdef LOCAL
		__N = N; cin >> __C; __S.clear();
		#endif

		solve(N);
	}
}
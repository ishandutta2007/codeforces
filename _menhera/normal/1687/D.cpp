#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	vector<long long> A(N);
	for (long long &a : A)
		cin >> a;
	for (long long x = 1;; x++)
	{
		long long s = x * x, e = x * (x + 1);
		if (e < A[0])
			continue;
		// cout << x << " " << s << " " << e << endl;
		long long minK = max(0LL, s - A[0]), maxK = e - A[0];
		// cout << minK << " " << maxK << endl;
		int cnt = 0;
		for (long long y = x; minK <= maxK; y++)
		{
			long long from = y * y - maxK, to = y * (y + 1) - minK;
			// cout << from << " " << to << " " << minK << " " << maxK << endl;

			if (from > A.back())
				break;
			auto i1 = lower_bound(A.begin(), A.end(), from);
			auto i2 = prev(upper_bound(A.begin(), A.end(), to));
			cnt += i2 - i1 + 1;
			// cout << "?" << endl;
			// cout << i2 - A.begin() << endl;
			long long lo = *i1, hi = *i2;
			minK = max(minK, y * y - lo);
			maxK = min(maxK, y * (y + 1) - hi);
			// cout << "???" << endl;
			// cout << lo << " " << hi << endl;
			// cout << minK << " " << maxK << endl;
		}
		if (minK <= maxK && cnt == N)
		{
			cout << minK << endl;
			return 0;
		}
	}
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> ans, rans;

bool ps(long long n, long long m, long long x)
{
	if (x == 1) return true;
	for (int i = 0; i < 16; i++) {
		bool f = true;
		for (int j = 0; j < 4; j++) {
			long long t = n;
			int nj = (j + 1) % 4;
			if (j & 1) t = m;
			if ((1 << j) & i) t--;
			if (!((1 << nj) & i)) t--;
			if (t % x != 0) {
				f = false;
				break;
			}
		}
		if (f) return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		ans.clear(); rans.clear();
		long long n, m; cin >> n >> m;
		long long s = 2LL * (n + m) - 4LL;
		for (long long i = 1; i * i <= s; i++) {
			if (s % i != 0) continue;
			if (ps(n, m, i))
				ans.push_back(i);
			if (i * i != s && ps(n, m, s / i))
				rans.push_back(s / i);
		}
		for (int i = (int)rans.size() - 1; i >= 0; i--)
			ans.push_back(rans[i]);
		cout << ans.size() << " ";
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << '\n';
	}
	return 0;
}
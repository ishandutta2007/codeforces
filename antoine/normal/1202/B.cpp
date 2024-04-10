#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int occ[10];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	{
		string s;
		cin >> s;
		for (int i = 0; i + 1 < (int) s.size(); ++i)
			++occ[(s[i + 1] - s[i] + 10) % 10];
	}
	// memset(ans, -1, sizeof ans);

	const int Inf = 999999;

	for (int x = 0; x < 10; ++x) {
		for (int y = 0; y < 10; ++y) {
			int res = 0;
			for (int k = 0; k < 10; ++k) {
				if (!occ[k])
					continue;
				int temp = Inf;
				for (int i = 0; i < 100; ++i)
					for (int j = !i; j < 100; ++j)
						if ((i * x + j * y) % 10 == k)
							temp = min(temp, i + j - 1);
				if (temp == Inf) {
					res = -1;
					break;
				}
				res += temp * occ[k];
			}
			cout << res << " \n"[y == 9];
		}
	}

	return 0;
}
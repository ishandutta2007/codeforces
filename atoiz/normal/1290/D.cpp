#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	k = (k == 1 ? k : (k >> 1));
	int m = n / k;

	vector<int> nxt(m);
	iota(nxt.begin(), nxt.end(), 1);

	vector<int> dup(n, 0);

	auto ask = [&](int x)
	{
		cout << "? " << x + 1 << endl;
		char is_dup;
		cin >> is_dup;
		if (is_dup == 'Y') {
			dup[x] = 1;
		}
	};

	// if there is only 1 block ...
	if (m == 1) {
		for (int i = 0; i < n; ++i) {
			ask(i);
		}

		cout << "! " << count(dup.begin(), dup.end(), 0) << endl;
		return 0;
	}

	for (int x = 0; x < m; ++x) {
		while (nxt[x] < m) {
			for (int y = x; y < m; y = nxt[y]++) {
				for (int i = 0; i < k; ++i) {
					ask(y * k + i);
				}
			}
			cout << "R" << endl;
		}
	}

	cout << "! " << count(dup.begin(), dup.end(), 0) << endl;
}
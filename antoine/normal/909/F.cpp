#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool f(const int &N, vector<int> &a) {
	const int mask = 1 << (int)floor(log2(N));
	int i = mask, j = mask - 1;
	for (; i <= N; ++i, --j) {
		if (j <= 0)
			return{};
		a[i] = j;
		a[j] = i;
	}
	return j == 0 || f(j, a);
}

bool g(const int N, vector<int> &a) {
	if (N <= 10) {
		for (int i = 1; i <= N; ++i)
			a[i] = i;
		do {
			bool violates = false;
			for(int i = 1; i <= N; ++i)
				if ((a[i] & i) == 0 || a[i] == i) {
					violates = true;
					break;
				}
			if (!violates)
				return true;
		} while (next_permutation(a.begin() + 1, a.begin() + N + 1));
		return false;
	}

	const int mask = 1 << (int)floor(log2(N));
	if (N == mask)
		return false;

	if (N == mask + 1) {
		a[mask + 1] = mask;
		a[mask] = mask + 1;
		return g(N - 2, a);
	}

	for (int i = mask; i < N; ++i)
		a[i] = i + 1;
	a[N] = mask;
	return g(mask - 1, a);
}

void output(const bool &ans, const vector<int> &v) {
	if (!ans) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	cout << v[1];
	for (int i = 2; i < v.size(); ++i)
		cout << ' ' << v[i];
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<int> v(N + 1);
	bool ans = f(N, v);
	output(ans, v);
	ans = g(N, v);
	output(ans, v);
	return 0;
}
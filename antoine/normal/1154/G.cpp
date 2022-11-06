#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MxN = (int) 1e6 + 9;
const int MxX = (int) 1e7 + 9;
pair<int, int> table[MxX + 9];
int a[MxN + 9];
int spf[MxX + 9];

void getDivisorsHelper(int i, int curr, const vector<pair<int, int>> &v, int idx) {
	if (i == (int) v.size()) {
		pair<int, int> &p = table[curr];
		if (!p.first)
			p.first = idx;
		else if (!p.second)
			p.second = idx;

	} else {
		getDivisorsHelper(i + 1, curr, v, idx);
		for (int j = 0; j < v[i].second; ++j) {
			curr *= v[i].first;
			getDivisorsHelper(i + 1, curr, v, idx);
		}
	}
}

void getDivisors(int x, const int idx) {
	vector<pair<int, int>> v;
	while (x > 1) {
		int d = spf[x], cnt = 0;
		do {
			x /= d;
			cnt++;
		} while (x % d == 0);
		v.push_back( { d, cnt });
	}
	getDivisorsHelper(0, 1, v, idx);
}

inline bool comp(int i, int j) {
	return a[i] < a[j];
}

void buildSieve() {
	vector<int> primes;
	spf[0] = spf[1] = 1;
	for (int i = 2; i < MxX; ++i) {
		if (spf[i] == 0) {
			primes.push_back(i);
			spf[i] = i;
		}
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < MxX; ++j) {
			spf[i * primes[j]] = primes[j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	buildSieve();

	int n;
	cin >> n;

	vector<int> indexes(n);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		indexes[i - 1] = i;
	}

	sort(indexes.begin(), indexes.end(), comp);

	for (const int i : indexes)
		getDivisors(a[i], i);

	pair<ll, pair<int, int>> res = { 1LL << 60, { -10, -20 } };

	for (int d = 1; d <= MxX; ++d) {
		const pair<int, int> &p = table[d];
		if (!p.second)
			continue;
		res = min(res, { a[p.first] / d * (ll) a[p.second], p });
	}
	cerr << res.first << endl;

	int i = res.second.first;
	int j = res.second.second;
	if (i > j)
		swap(i, j);
	cout << i << ' ' << j << endl;
	return 0;
}
/*input
19 5
1001001001100000110
2
2 3
2
5 6
2
8 9
5
12 13 14 15 16
1
19


*/

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cassert>

using namespace std;

struct DSU
{
	int n;
	vector<int> root, diff, val;
	vector<array<int, 2>> cnt;	
	int total;

	DSU(int _n)
	{
		n = _n;
		
		root.resize(n);
		iota(root.begin(), root.end(), 0);

		diff.assign(n, 0);
		val.assign(n, -1);
		cnt.assign(n, {0, 1});
		total = 0;
	}

	void compress(int x)
	{
		if (x != root[x]) {
			compress(root[x]);
			diff[x] ^= diff[root[x]];
			root[x] = root[root[x]];
			assert(root[x] == root[root[x]]);
		}
	}

	int get(int x)
	{
		return (val[x] == -1 ? min(cnt[x][0], cnt[x][1]) : cnt[x][val[x]]);
	}

	void join(int x, int y, int d)
	{
		if (x != root[x]) {
			compress(x);
			d ^= diff[x];
			x = root[x];
		}
		assert(root[x] == x);

		if (y != root[y]) {
			compress(y);
			d ^= diff[y];
			y = root[y];
		}
		assert(root[y] == y);

		if (x == y) {
			assert(d == 0);
			return;
		}

		if (cnt[x][0] + cnt[x][1] < cnt[y][0] + cnt[y][1]) {
			swap(x, y);
		}

		assert(diff[x] == 0);
		assert(diff[y] == 0);

		total -= get(x) + get(y);

		root[y] = x;
		diff[y] ^= d;

		cnt[x][0] += cnt[y][0 ^ diff[y]];
		cnt[x][1] += cnt[y][1 ^ diff[y]];
		if (val[y] != -1) {
			assert(val[x] == -1 || val[x] == (val[y] ^ diff[y]));
			val[x] = (val[y] ^ diff[y]);
		}

		total += get(x);
	}

	void enforce(int x, int v)
	{
		if (x != root[x]) {
			compress(x);
			v ^= diff[x];
			x = root[x];
		}
		assert(root[x] == x);

		assert(val[x] == -1 || val[x] == v);
		total -= get(x);
		val[x] = v; 
		total += get(x);
	}
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	string lamps;
	cin >> lamps;

	DSU dsu(k);
	vector<vector<int>> switches(n);

	for (int s = 0; s < k; ++s) {
		int num;
		cin >> num;
		while (num--) {
			int l;
			cin >> l;
			--l;

			switches[l].push_back(s);
		}
	}

	for (int l = 0; l < n; ++l) {
		assert(switches[l].size() < 3);
		int v = (lamps[l] == '0');

		if (switches[l].empty()) {
			assert(v == 0);
		} else if (switches[l].size() == 1) {
			dsu.enforce(switches[l][0], v);
		} else {
			dsu.join(switches[l][0], switches[l][1], v);
		}

		cout << dsu.total << '\n';
	}
}
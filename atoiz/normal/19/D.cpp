#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
#include <cstring>
#include <map>

using namespace std;

const int MAXN = 200007;
map<int, int> lis[MAXN];
int N, it[MAXN * 4];
vector<tuple<int, int, int>> queries;
vector<int> valX;

int pos(int x) { return (int) (lower_bound(valX.begin(), valX.end(), x) - valX.begin()); }

void relax(int x)
{
	int rt = 1, lo = 0, hi = (int) valX.size() - 1;
	while (lo < hi) {
		int md = (lo + hi) >> 1;
		(x <= md) ? (rt = rt << 1, hi = md) : (rt = rt << 1 | 1, lo = md + 1);
	}

	it[rt] = (lis[x].empty() ? -1 : lis[x].rbegin()->first);
	for (rt >>= 1; rt > 0; rt >>= 1) it[rt] = max(it[rt << 1], it[rt << 1 | 1]);
}

int get(int x, int y, int rt = 1, int lo = 0, int hi = (int) valX.size() - 1)
{
	if (hi <= x || it[rt] <= y) return -1;
	if (lo == hi) return lo;
	int lc = rt << 1, rc = rt << 1 | 1, md = (lo + hi) >> 1;
	int can = get(x, y, lc, lo, md);
	if (~can) return can;
	return get(x, y, rc, md + 1, hi);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	memset(it, -1, sizeof(it[0]) * (N + 3) * 4);

	queries.reserve(N + 1), valX.reserve(N);
	queries.resize(1);
	for (int i = 0; i < N; ++i) {
		string str;
		int x, y;
		cin >> str >> x >> y;
		if (str == "add") queries.emplace_back(0, x, y);
		else if (str == "remove") queries.emplace_back(1, x, y);
		else queries.emplace_back(2, x, y);
		valX.push_back(x);
	}
	sort(valX.begin(), valX.end()), valX.erase(unique(valX.begin(), valX.end()), valX.end());

	for (int id = 1; id <= N; ++id) {
		int t, x, y;
		tie(t, x, y) = queries[id];
		int px = pos(x);
		if (t == 0) {
			lis[px][y] = id;
			relax(px);
		} else if (t == 1) {
			int i = lis[px][y];
			lis[px].erase(y);
			relax(px);
		} else {
			int x0 = get(pos(x), y);
			if (x0 == -1) {
				cout << "-1\n";
				continue;
			}
			int y0 = lis[x0].upper_bound(y)->first;
			cout << valX[x0] << ' ' << y0 << '\n';
		}
	}
}
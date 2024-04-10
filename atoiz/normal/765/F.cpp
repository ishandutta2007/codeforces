/*input
8
3 1 4 1 5 9 2 6
4
1 8
1 3
4 8
5 7

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <array>
#include <map>

using namespace std;

const int MAXN = 100007, INF = 1e9 + 8;

struct segment_tree 
{
	struct node_t
	{
		array<int, 2> ch;
		int val;

		node_t()
		{
			ch[0] = -1, ch[1] = -1, val = INF;
		}
	};

	int limit, last_id;
	array<node_t, MAXN * 19> nodes;

	segment_tree(int _limit)
	{
		limit = _limit;
		nodes[0] = node_t();
		last_id = 0;
	}

	void create(int& nd)
	{
		if (nd == -1) {
			nd = ++last_id;
			nodes[nd] = node_t();
		}
	}

	void upd(int pos, int val, bool do_assign, int id, int lo, int hi)
	{
		auto &nd = nodes[id];
		int mid = (lo + hi) >> 1;

		if (lo == hi) {
			if (do_assign) {
				nd.val = val;
			} else {
				nd.val = min(nd.val, val);
			}
			return;
		}

		if (pos <= mid) {
			create(nd.ch[0]);
			assert(nd.ch[0] >= 0);
			upd(pos, val, do_assign, nd.ch[0], lo, mid);
		} else {
			create(nd.ch[1]);
			assert(nd.ch[1] >= 0);
			upd(pos, val, do_assign, nd.ch[1], mid + 1, hi);
		}

		nd.val = INF;
		for (int d = 0; d < 2; ++d) {
			if (nd.ch[d] >= 0) {
				nd.val = min(nd.val, nodes[nd.ch[d]].val);
			}
		}
	}
	void upd(int pos, int val, bool do_assign)
	{ upd(pos, val, do_assign, 0, 0, limit); }

	int get_min(int from, int to, int id, int lo, int hi)
	{
		auto &nd = nodes[id];
		int mid = (lo + hi) >> 1;

		if (hi < from || to < lo) return INF;
		if (from <= lo && hi <= to) return nd.val;

		int ans = INF;
		if (nd.ch[0] >= 0) {
			ans = min(ans, get_min(from, to, nd.ch[0], lo, mid));
		}
		if (nd.ch[1] >= 0) {
			ans = min(ans, get_min(from, to, nd.ch[1], mid + 1, hi));
		}
		return ans;
	}
	int get_min(int from, int to)
	{ return get_min(from, to, 0, 0, limit); }
};

struct query_t
{ int from, to; };

vector<int> solve(vector<int> arr, vector<query_t> queries)
{
	int n = (int) arr.size(), m = (int) queries.size();

	// build replace_as
	vector<int> replace_as(n);
	map<int, int> last_app;
	for (int i = n - 1; i >= 0; --i) {
		if (last_app.find(arr[i]) == last_app.end()) {
			replace_as[i] = INF;
		} else {
			replace_as[i] = last_app[arr[i]];
		}

		last_app[arr[i]] = i;
	}

	// build tree
	int max_val = *max_element(arr.begin(), arr.end());
	segment_tree indexes(max_val); // keep index (> i) for each value
	for (auto p : last_app) {
		indexes.upd(p.first, p.second, true);
	}

	// sort queries
	vector<int> ans(m);
	vector<vector<int>> queries_by_to(n);
	for (int i = 0; i < m; ++i) {
		queries_by_to[queries[i].to].push_back(i);
	}

	// solve
	vector<vector<pair<int, int>>> updates(n);
	segment_tree vals(n);
	for (int i = 0; i < n; ++i) {
		// replace
		indexes.upd(arr[i], replace_as[i], true);
		// cout << i << endl;

		// find pairs
		int lim = INF;
		while (true) {
			int j = indexes.get_min(arr[i], lim);
			if (j >= n) break;

			updates[j].emplace_back(i, arr[j] - arr[i]);
			lim = (arr[i] + arr[j]) / 2;
			if (arr[j] == arr[i]) break;
		}

		lim = 0;
		while (true) {
			int j = indexes.get_min(lim, arr[i]);
			if (j >= n) break;

			updates[j].emplace_back(i, arr[i] - arr[j]);
			lim = (arr[i] + arr[j] + 1) / 2;
			if (arr[j] == arr[i]) break;
		}

		// updates
		for (auto p : updates[i]) {
			vals.upd(p.first, p.second, false);
		}

		// deal with queries
		for (int id : queries_by_to[i]) {
			ans[id] = vals.get_min(queries[id].from, queries[id].to);
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	// read from input
	int n, m;
	cin >> n;
	vector<int> arr(n);
	for (auto &x : arr) cin >> x;

	cin >> m;
	vector<query_t> queries(m);
	for (int i = 0; i < m; ++i) {
		cin >> queries[i].from >> queries[i].to;
		--queries[i].from, --queries[i].to;
	}

	// solve
	auto ans = solve(arr, queries);
	for (auto &x : ans) {
		cout << x << '\n';
	}

	return 0;

	// auto forward_ans = solve(arr, queries);
	// int max_val = *max_element(arr.begin(), arr.end());
	// for (auto &x : arr) x = max_val - x;
	// auto backward_ans = solve(arr, queries);

	// for (int i = 0; i < m; ++i) {
	// 	cout << min(forward_ans[i], backward_ans[i]) << '\n';
	// }
}
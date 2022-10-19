/*input
15
bcabcabcabcabca

*/

// https://codeforces.com/group/sd4r2IvEfL/contest/289090/problem/B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct SuffixArrayLCP
{
	int N;
	string S;
	vector<int> sa, lcp, order;
	vector<vector<int>> rmq;

	void getSA()
	{
		int M = max(26, N);
		vector<int> start(M), last(M), nxt(M), tmp;
		tmp.assign(2 * N, -1);
		order.reserve(N);
		sa.resize(N); 
		for (int i = 0; i < N; ++i) sa[i] = S[i] - 'a';

		auto insert = [&](int i, int r) { (~last[r] ? nxt[last[r]] : start[r]) = i, last[r] = i; };
		auto reset = [&]() {
			fill(start.begin(), start.end(), -1);
			fill(last.begin(), last.end(), -1);
			fill(nxt.begin(), nxt.end(), -1);
		};
		auto push = [&]() {
			order.clear();
			for (int r = 0; r < M; ++r) for (int i = start[r]; ~i; i = nxt[i]) order.push_back(i);
		};

		for (int z = 1; z < N; z <<= 1) {
			reset();
			for (int i = z; i < N; ++i) insert(i, sa[i]);
			push();
			
			reset();
			for (int i = N - z; i < N; ++i) insert(i, sa[i]);
			for (int i : order) insert(i - z, sa[i - z]);
			push();

			int cur = -1;
			copy(sa.begin(), sa.end(), tmp.begin());
			for (int i = 0; i < N; ++i) {
				if (i == 0 || tmp[order[i - 1]] < tmp[order[i]] || tmp[order[i - 1] + z] < tmp[order[i] + z]) ++cur;
				sa[order[i]] = cur;
			}
			if (cur == N - 1) break;
		}

		reset();
		for (int i = 0; i < N; ++i) insert(i, sa[i]);
		push();

	}

	void kasai()
	{
		lcp.resize(N);
		int cur = 0;
		for (int l = 0; l < N; ++l) {
			if (sa[l] == N - 1) {
				lcp[l] = 0;
				cur = 0;
				continue;
			}

			int k = order[sa[l] + 1];
			for (cur = max(0, cur - 1); max(k, l) + cur < N && S[k + cur] == S[l + cur]; ++cur);
			lcp[l] = cur;
		}
	}

	void buildRMQ()
	{
		int lg = __lg(N);
		rmq.assign(lg + 1, vector<int>(N, 0));
		for (int i = 0; i < N; ++i) rmq[0][i] = lcp[order[i]];
		for (int j = 1; j <= lg; ++j) for (int i = 0; i <= N - (1 << j); ++i) rmq[j][i] = min(rmq[j - 1][i], rmq[j - 1][i + (1 << (j - 1))]);
	}

	SuffixArrayLCP(string _S): S(_S)
	{
		N = (int) S.size();

		getSA();
		kasai();
		buildRMQ();
	}

	int getLCP(int i, int j)
	{
		i = sa[i], j = sa[j];
		if (i > j) swap(i, j);
		int lg = __lg(j - i);
		return min(rmq[lg][i], rmq[lg][j - (1 << lg)]);
	}
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	string S;
	cin >> N >> S;
	SuffixArrayLCP lcp(S);
	vector<int> ans((N + 1) / 2);

	int cur = -1;
	for (int i = (N - 1) / 2; i >= 0; --i) {
		cur += 2;
		for (; cur > 0; cur -= 2) {
			if (cur < N - 2 * i && lcp.getLCP(i, N - i - cur) >= cur) break;
		}
		ans[i] = cur;
	}

	for (int x : ans) cout << x << ' ';
	cout << endl;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 100007;
int ans[MAXN], N, A[MAXN], S[MAXN], Q;
vector<pair<int, int>> queries[MAXN];
int st[MAXN], top = 0;

int opt(int i, int j) // last diagonal where from i is better than from j
{
	if (A[i] >= A[j]) return 0;
	int ans = ((A[j] * j - S[j - 1]) - (A[i] * i - S[i - 1])) / (A[j] - A[i]);
	if (ans >= i) return i;
	if (ans <= 0) return 0;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> A[i], S[i] = S[i - 1] + A[i];
	cin >> Q;
	for (int i = 1; i <= Q; ++i) {
		int r, c;
		cin >> r >> c;
		queries[c].emplace_back(r, i);
	}

	for (int j = 1; j <= N; ++j) {
		while (top > 0 && opt(st[top], j) == 0) --top;
		while (top > 1 && opt(st[top - 1], st[top]) >= opt(st[top], j)) --top;
		st[++top] = j;

		for (auto &p : queries[j]) {
			int cur = j - (p.first - 1);
			int lo = 1, hi = top;
			while (lo < hi) {
				int md = (lo + hi) >> 1;
				if (cur <= opt(st[md], st[md + 1])) hi = md;
				else lo = md + 1;
			}
			int f = st[lo];
			ans[p.second] = (S[j] - S[f]) + A[f] * (p.first - j + f);
		}
	}
	for (int i = 1; i <= Q; ++i) cout << ans[i] << '\n';
}
/*input
4 2 1
abac


*/

#include <iostream>

using namespace std;

const int MAXN = 1004;
const int64_t INF = 1e18 + 7;
int N, M;
int64_t K;
string S;
int64_t dp[MAXN][MAXN];
int trie[MAXN * MAXN][26], order[MAXN * MAXN], num_nodes = 1;

void add(int64_t &x, int64_t y)
{ x = ((x += y) >= INF ? INF : x); }

void find_order(int x)
{
	static int next_id = 0;
	// cout << "order " << x << ' ' << next_id << endl;
	order[x] = next_id++;

	for (int c = 0; c < 26; ++c) {
		if (trie[x][c]) {
			find_order(trie[x][c]);
		}
	}
}

int64_t solve(int min_order)
{
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= M; ++j) {
			dp[i][j] = 0;
		}
	}

	dp[0][0] = 1, dp[1][0] = -1;
	for (int i = 0; i <= N; ++i) {
		int from = N + 1;
		int x = 1;
		for (int j = i; j < N; ++j) {
			x = trie[x][(int) (S[j] - 'a')];
			if (order[x] >= min_order) {
				from = j + 1;
				break;
			}
		}
		// cout << "from " << i << ": " << from << endl;

		for (int j = 0; j <= M; ++j) {
			if (i > 0) add(dp[i][j], dp[i - 1][j]);
			if (from <= N) add(dp[from][j + 1], dp[i][j]);
		}
	}
	// cout << min_order << ": " << dp[N][M] << endl;
	return dp[N][M];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K >> S;

	for (int i = 0; i < N; ++i) {
		int x = 1;
		for (int j = i; j < N; ++j) {
			int &y = trie[x][(int) (S[j] - 'a')];
			if (y == 0) y = ++num_nodes;
			// cout << x << " -> " << y << ": " << S[j] << endl;
			x = y;
		}
	}

	find_order(1);

	int lo = 1, hi = num_nodes - 1;
	while (lo < hi) {
		int mid = (lo + hi + 1) >> 1;

		if (solve(mid) >= K) lo = mid;
		else hi = mid - 1;
	}

	for (int x = 1; order[x] != lo; ) {
		for (int c = 25; c >= 0; --c) {
			if (trie[x][c] && order[trie[x][c]] <= lo) {
				cout << char('a' + c);
				x = trie[x][c];
				break;
			}
		}
	}

	return 0;
}
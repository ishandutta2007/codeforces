#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = 40;
int dp[MxN + 1][MxN + 1][MxN + 1][MxN + 1][2];
int cnt[MxN + 1][MxN + 1][MxN + 1][MxN + 1][2];
int deg[MxN + 1][MxN + 1][MxN + 1][MxN + 1][2];
int n, m;

bool connected(const int r1, const int c1, const int r2, const int c2) {
	const int dr = abs(r1 - r2);
	const int dc = abs(c1 - c2);
	return dr && dc && dr + dc == 3;
}

struct State {
	int r1, c1, r2, c2, turn;

	bool end() const {
		if (r1 == r2 && c1 == c2)
			return true;
		if (connected(r1, c1, r2, c2))
			return false;
		return turn ? r1 == n / 2 && c1 == m / 2 : r2 == n / 2 + 1 && c2 == m / 2;
	}

	vector<State> adj() const {
		vector<State> res;
		if (end())
			return res;
		const int r = turn ? r2 : r1;
		const int c = turn ? c2 : c1;
		for (int adr : { 1, 2 }) {
			const int adc = 3 - adr;
			for (int dr : { -adr, adr })
				if (1 <= r + dr && r + dr <= n)
					for (int dc : { -adc, adc })
						if (1 <= c + dc && c + dc <= m) {
							State state = *this;
							state.turn ^= 1;
							(turn ? state.r2 : state.r1) += dr;
							(turn ? state.c2 : state.c1) += dc;
							res.push_back(state);
						}
		}
		return res;
	}

	int adjSz() const {
		int res = 0;
		if (end())
			return res;
		const int r = turn ? r2 : r1;
		const int c = turn ? c2 : c1;
		for (int adr : { 1, 2 }) {
			const int adc = 3 - adr;
			for (int dr : { -adr, adr })
				if (1 <= r + dr && r + dr <= n)
					for (int dc : { -adc, adc })
						if (1 <= c + dc && c + dc <= m) {
							State state = *this;
							state.turn ^= 1;
							(turn ? state.r2 : state.r1) += dr;
							(turn ? state.c2 : state.c1) += dc;
							++res;
						}
		}
		return res;
	}

	const vector<State> &adjInv() const {
		static vector<State> res;
		res.clear();
		res.reserve(8);

		const int r = turn ? r1 : r2;
		const int c = turn ? c1 : c2;
		for (int adr : { 1, 2 }) {
			const int adc = 3 - adr;
			for (int dr : { -adr, adr })
				if (1 <= r + dr && r + dr <= n)
					for (int dc : { -adc, adc })
						if (1 <= c + dc && c + dc <= m) {
							State state = *this;
							state.turn ^= 1;
							(turn ? state.r1 : state.r2) += dr;
							(turn ? state.c1 : state.c2) += dc;
							if (!state.end())
								res.push_back(state);
						}
		}
		return res;
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	memset(dp, -1, sizeof dp);

	cin >> n >> m;
	queue<State> q;
	for (int r1 = 1; r1 <= n; ++r1)
		for (int c1 = 1; c1 <= m; ++c1)
			for (int r2 = 1; r2 <= n; ++r2)
				for (int c2 = 1; c2 <= m; ++c2)
					for (int turn = 0; turn < 2; ++turn) {
						State state { r1, c1, r2, c2, turn };
						int &d = deg[r1][c1][r2][c2][turn] = (int) state.adjSz();
						int &res = dp[r1][c1][r2][c2][turn];
						if (state.end()) {
							res = 0;
							assert(d == 0);
							q.push(state);
						}
					}

	cerr << "t 1" << endl;
	while (!q.empty()) {
		const State s = q.front();
		q.pop();
		int &res = dp[s.r1][s.c1][s.r2][s.c2][s.turn];
		assert(res == 0 || res == 1);
		{
			int &d = deg[s.r1][s.c1][s.r2][s.c2][s.turn];
			assert(d == 0 || (d >= 0 && res == 1));
		}
		for (const State o : s.adjInv()) {
			int &r = dp[o.r1][o.c1][o.r2][o.c2][o.turn];
			int &d = --deg[o.r1][o.c1][o.r2][o.c2][o.turn];
			assert(d >= 0);

			if (!res) {
				if (r != 1) {
					assert(r == -1);
					r = 1;
					q.push(o);
					cnt[o.r1][o.c1][o.r2][o.c2][o.turn] = cnt[s.r1][s.c1][s.r2][s.c2][s.turn] + 1;
				}
			} else if (d == 0 && r == -1) {
				r = 0;
				q.push(o);
				cnt[o.r1][o.c1][o.r2][o.c2][o.turn] = cnt[s.r1][s.c1][s.r2][s.c2][s.turn] + 1;
			}
		}
	}

	cerr << "t 2" << endl;
	/*
	 for (int r1 = 1; r1 <= n; ++r1)
	 for (int c1 = 1; c1 <= m; ++c1)
	 for (int r2 = 1; r2 <= n; ++r2)
	 for (int c2 = 1; c2 <= m; ++c2)
	 for (int turn = 0; turn < 2; ++turn) {
	 int &res = dp[r1][c1][r2][c2][turn];
	 assert(res != -1);
	 }
	 */

	cerr << "t 3" << endl;
	int r1, c1, r2, c2, color;
	cin >> r1 >> c1 >> r2 >> c2;

	if (dp[r1][c1][r2][c2][0]) {
		cout << "WHITE" << endl;
		color = 0;
	} else {
		cout << "BLACK" << endl;
		color = 1;
	}

	for (int turn = 0;; turn ^= 1) {
		int &r = turn ? r2 : r1;
		int &c = turn ? c2 : c1;

		State state { r1, c1, r2, c2, turn };
		// cerr << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << endl;
		if (state.end())
			break;

		assert(dp[r1][c1][r2][c2][turn] == (turn == color));
		if (turn == color) {

			const int Inf = (int) 1e9 + 9;
			int minCnt = Inf;

			for (const State o : state.adj())
				if (dp[o.r1][o.c1][o.r2][o.c2][o.turn] == 0)
					minCnt = min(minCnt, cnt[o.r1][o.c1][o.r2][o.c2][o.turn]);
			assert(minCnt < Inf);
			for (const State o : state.adj())
				if (dp[o.r1][o.c1][o.r2][o.c2][o.turn] == 0 && cnt[o.r1][o.c1][o.r2][o.c2][o.turn] == minCnt) {
					r1 = o.r1;
					c1 = o.c1;
					r2 = o.r2;
					c2 = o.c2;
					break;
				}
			cout << r << ' ' << c << endl;
		} else {
			cin >> r >> c;
			if (r == -1) {
				return 0;
			}

			bool found = false;
			for (State o : state.adj())
				if (r1 == o.r1 && c1 == o.c1 && r2 == o.r2 && c2 == o.c2) {
					found = true;
					break;
				}
			assert(found);
		}
	}
	return 0;
}
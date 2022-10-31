#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

namespace testgen {


#define each(it,o) for(auto it = (o).begin(); it != (o).end(); ++ it)
	int bipartiteMatching(const vector<vector<int> > &g) {
		int nleft = g.size(), nright = 0;
		each(es, g) if (!es->empty()) nright = max(nright, *max_element(es->begin(), es->end()) + 1);
		vi matchL(nleft, -1), matchR(nright, -1), prev(nleft), seen(nleft, -1);
		rep(i, nleft) {
			vi stk; stk.push_back(i);
			seen[i] = i; prev[i] = -1;
			while (!stk.empty()) {
				int v = stk.back(); stk.pop_back();
				each(ui, g[v]) {
					int u = *ui;
					int j = matchR[u];
					if (j == -1) {
						while (v != -1) {
							matchR[u] = v;
							swap(u, matchL[v]);
							v = prev[v];
						}
						goto break_;
					} else if (seen[j] < i) {
						seen[j] = i; prev[j] = v;
						stk.push_back(j);
					}
				}
			}
		break_:;
		}
		return (int)matchL.size() - count(matchL.begin(), matchL.end(), -1);
	}

	void randomMatching(int n, int m, vector<string> &res, mt19937 &re) {
		res.assign(n, string(m, '?'));
		auto check = [&]() -> bool {
			vector<vi> g(n * m);
			int t = 0;
			rep(i, n) rep(j, m) if (res[i][j] == '?') {
				++ t;
				if ((i + j) % 2 == 0) {
					if (i + 1 < n && res[i + 1][j] == '?')
						g[i * m + j].push_back((i + 1) * m + j);
					if (j + 1 < m && res[i][j + 1] == '?')
						g[i * m + j].push_back(i * m + (j + 1));
					if (i - 1 >= 0 && res[i - 1][j] == '?')
						g[i * m + j].push_back((i - 1) * m + j);
					if (j - 1 >= 0 && res[i][j - 1] == '?')
						g[i * m + j].push_back(i * m + (j - 1));
				}
			}
			int match = bipartiteMatching(g);
			return match * 2 == t;
		};
		rep(k, n * m / 2) {
			while (1) {
				int ay, ax, by, bx;
				while (1) {
					ay = re() % n, ax = re() % m;
					if (re() % 2)
						by = ay, bx = ax + 1;
					else
						by = ay + 1, bx = ax;
					if (by >= n || bx >= m) continue;
					if (res[ay][ax] != '?' || res[by][bx] != '?')
						continue;
					break;
				}
				if (by == ay + 1) {
					res[ay][ax] = 'U';
					res[by][bx] = 'D';
				} else {
					res[ay][ax] = 'L';
					res[by][bx] = 'R';
				}
				if (!check()) {
					res[ay][ax] = res[by][bx] = '?';
					continue;
				}
				break;
			}
		}
	}

}

bool execop0(vector<string> &str, vpii &ops, int i, int j) {
	if (str[i][j] == 'L' && str[i + 1][j] == 'L') {
		str[i][j] = str[i][j + 1] = 'U';
		str[i + 1][j] = str[i + 1][j + 1] = 'D';
		ops.emplace_back(i, j);
		return true;
	}
	return false;
}

bool execop1(vector<string> &str, vpii &ops, int i, int j) {
	if (str[i][j] == 'U' && str[i][j + 1] == 'U') {
		str[i][j] = str[i + 1][j] = 'L';
		str[i][j + 1] = str[i + 1][j + 1] = 'R';
		ops.emplace_back(i, j);
		return true;
	}
	return false;
}

void solve(vector<string> str, vpii &ops) {
	int n = (int)str.size(), m = (int)str[0].size();

	auto phase0 = [&]() {
		bool upd = false;
		rep(i, n - 1) rep(j, m - 1)
			upd |= execop0(str, ops, i, j);
		return upd;
	};

	auto phase1 = [&]() {
		bool upd = false;
		rep(i, n - 1) rep(j, m - 1)
			upd |= execop1(str, ops, i, j);
		return upd;
	};


	mt19937 re;
	while (1) {
		//cerr << ops.size() << ":" << endl;
		//rep(i, n)
		//	cerr << str[i] << '\n';
		int upd = 0;
		if (re() % 2) {
			phase0();
			phase1();
		} else {
			phase1();
			phase0();
		}
		bool alllr = true;
		rep(i, n) rep(j, m)
			alllr &= str[i][j] == 'L' || str[i][j] == 'R';
		if (alllr) {
			break;
		}
	}
}

int main() {
	int n; int m;
	mt19937 re;
	while (~scanf("%d%d", &n, &m)) {
		vector<string> start(n);
		rep(i, n) {
			char buf[51];
			scanf("%s", buf);
			buf[m] = 0;
			start[i] = buf;
		}
		//testgen::randomMatching(n, m, start, re);
		vector<string> goal(n);
		rep(i, n) {
			char buf[51];
			scanf("%s", buf);
			buf[m] = 0;
			goal[i] = buf;
		}
		//testgen::randomMatching(n, m, goal, re);

		vpii ans;
		if (m % 2 != 0) {
			vector<string> startT(m, string(n, '?')), goalT = startT;
			auto trans = [](char c) {
				return c == 'U' ? 'L' : c == 'D' ? 'R' : c == 'L' ? 'U' : 'D';
			};
			rep(i, n) rep(j, m) {
				startT[j][i] = trans(start[i][j]);
				goalT[j][i] = trans(goal[i][j]);
			}
			vpii ops1;
			solve(startT, ops1);
			vpii ops2;
			solve(goalT, ops2);
			reverse(ops2.begin(), ops2.end());
			for (auto p : ops1)
				ans.emplace_back(p.second, p.first);
			for (auto p : ops2)
				ans.emplace_back(p.second, p.first);
		} else {
			vpii ops1;
			solve(start, ops1);
			vpii ops2;
			solve(goal, ops2);
			ans.insert(ans.end(), ops1.begin(), ops1.end());
			ans.insert(ans.end(), ops2.rbegin(), ops2.rend());
		}

		auto str = start;
		vpii ops;
		for (auto op : ans) {
			if(!execop0(str, ops, op.first, op.second))
				execop1(str, ops, op.first, op.second);
		}
		//cerr << ops.size() << " vs " << ans.size() << endl;
		assert(str == goal);

		printf("%d\n", (int)ans.size());
		for (int i = 0; i < (int)ans.size(); ++ i)
			printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
	}
	return 0;
}
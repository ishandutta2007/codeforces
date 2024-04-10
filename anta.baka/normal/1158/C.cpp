#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string.h>
#include <string>
#include <cassert>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()

struct Fen {
	int n;
	vi t;
	Fen(int n) : n(n), t(n, 0) {}
	void upd(int v) {
		for (int i = v; i < n; i |= i + 1) {
			t[i]++;
		}
	}
	int get(int v) {
		int r = 0;
		for (int i = v; i >= 0; i = (i & (i + 1)) - 1) {
			r += t[i];
		}
		return r;
	}
	int get(int l, int r) {
		return get(r) - get(l - 1);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//ifstream cin("in.txt");
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vi nxt(n);
		for (int& x : nxt) {
			cin >> x;
			if (x != -1) {
				--x;
			}
		}
		bool okok = true;
		for (int i = 0; i < n; i++) {
			if (nxt[i] != -1 && nxt[i] <= i) {
				okok = false;
				break;
			}
		}
		if (!okok) {
			cout << -1 << '\n';
			continue;
		}
		Fen t(n + 1);
		for (int i = 0; i < n; i++) {
			if (nxt[i] != -1) {
				int v = nxt[i];
				if (i + 1 < v && t.get(i + 1, v - 1) != 0) {
					okok = false;
					break;
				}
				t.upd(v);
			}
		}
		if (!okok) {
			cout << -1 << '\n';
		} else {
			vi deg(n + 1, 0);
			for (int x : nxt) {
				if (x != -1) {
					deg[x]++;
				}
			}
			set<int> q;
			for (int i = 0; i < n; i++) {
				if (deg[i] == 0) {
					q.insert(-i);
				}
			}
			vi ans(n, -1);
			int num = 0;
			while(!q.empty()) {
				int v = -(*q.begin());
				q.erase(q.begin());
				ans[v] = ++num;
				if (nxt[v] != -1) {
					if (--deg[nxt[v]] == 0) {
						if (nxt[v] != n) {
							q.insert(-nxt[v]);
						}
					}
				}
			}
			for (int x : ans) {
				cout << x << ' ';
			}
			cout << '\n';
		}
	}
}
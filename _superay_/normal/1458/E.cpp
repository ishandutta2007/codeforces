#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct Node {
	int x, y, id;
	inline bool operator < (const Node &oth) const {
		if (x != oth.x) return x < oth.x;
		if (y != oth.y) return y < oth.y;
		return id < oth.id;
	}
};
int n, m, ans[N];
vector<Node> buck;
set<pair<int, int> > ST, st;
inline void Ins(int x, int y) {
	if (x <= y) st.insert(make_pair(x, y));
}
int main() {
	scanf("%d%d", &n, &m);
	bool flag = 0;
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (!x && !y) flag = 1;
		Node tmp;
		tmp.x = x;
		tmp.y = y;
		tmp.id = 0;
		buck.push_back(tmp);
		ST.insert(make_pair(x, y));
	}
	if (!flag) {
		Node tmp;
		tmp.x = 0;
		tmp.y = 0;
		tmp.id = 0;
		buck.push_back(tmp);
		ST.insert(make_pair(0, 0));
	}
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (ST.count(make_pair(x, y))) {
			ans[i] = 0;
			continue;
		}
		Node tmp;
		tmp.x = x;
		tmp.y = y;
		tmp.id = i;
		buck.push_back(tmp);
	}
	sort(buck.begin(), buck.end());
	int lstx = -1;
	st.insert(make_pair(0, 1e9));
	for (int i = 0, j; i < (int)buck.size(); i = j) {
		for (j = i; j < (int)buck.size() && buck[j].x == buck[i].x; j++);
		int x = buck[i].x, cur = -1;
		if (lstx != -1) {
			int rem = x - lstx;
			while (rem && st.size()) {
				pair<int, int> P = *st.begin();
				st.erase(st.begin());
				int mn = min(P.second - P.first + 1, rem);
				P.first += mn;
				cur = P.first - 1;
				rem -= mn;
				if (P.first <= P.second) st.insert(P);
			}
			if (rem) cur = -1;
			if (cur != -1) {
				int flagle = 0, flageq = 0;
				for (int k = i; k < j; k++) {
					if (!buck[k].id) {
						if (cur == buck[k].y) {
							flageq = 1;
						}
						if (cur > buck[k].y) {
							flagle = 1;
						}
					}
				}
				if (!flageq) {
					if (flagle) {
						Ins(cur, cur);
						cur = -1;
					}
				}
			}
		}
		lstx = x;
		for (int k = i; k < j; k++) {
			if (!buck[k].id) {
				set<pair<int, int> >::iterator it = st.lower_bound(make_pair(buck[k].y + 1, -1));
				if (it != st.begin()) {
					--it;
					if (it -> second >= buck[k].y) {
						int L = it -> first, R = it -> second;
						st.erase(it);
						Ins(L, buck[k].y - 1), Ins(buck[k].y + 1, R);
					}
				}
			}
		}
		for (int k = i; k < j; k++) {
			if (buck[k].id) {
				ans[buck[k].id] = (buck[k].y == cur ? 0 : 1);
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		puts(ans[i] ? "WIN" : "LOSE");
	}
	return 0;
}
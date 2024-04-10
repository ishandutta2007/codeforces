#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, m;
set<pair<pair<int, int>, char> > st;
set<pair<int, int> > fe, ge;
int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		char op;
		scanf(" %c", &op);
		if (op == '+') {
			int u, v;
			char c;
			scanf("%d%d %c", &u, &v, &c);
			st.insert(make_pair(make_pair(u, v), c));
			auto it = st.lower_bound(make_pair(make_pair(v, u), 0));
			if (it != st.end() && it -> first == make_pair(v, u)) {
				fe.emplace(min(u, v), max(u, v));
				if (c == it -> second) ge.emplace(min(u, v), max(u, v));
			}
		} else if (op == '-') {
			int u, v;
			scanf("%d%d", &u, &v);
			auto it = st.lower_bound(make_pair(make_pair(u, v), 0));
			st.erase(it);
			auto P = make_pair(min(u, v), max(u, v));
			if (fe.count(P)) fe.erase(P);
			if (ge.count(P)) ge.erase(P);
		} else {
			int k;
			scanf("%d", &k);
			int ans = 0;
			if (k % 2 == 1) {
				if (fe.size()) ans = 1;
			} else {
				if (ge.size()) ans = 1;
			}
			puts(ans ? "YES" : "NO");
		}
	}
	return 0;
}
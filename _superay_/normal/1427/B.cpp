#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, k, r1, l2;
char s[N];
vector<pair<int, pair<int, int> > > vec;
inline void Add(int l, int r) {
	if (l == 1) {
		r1 = r;
	} else if (r == n) {
		l2 = l;
	} else {
		vec.push_back(make_pair(r - l + 1, make_pair(l, r)));
	}
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d %s", &n, &k, s + 1);
		vec.clear();
		r1 = 0;
		l2 = n + 1;
		for (int i = 1, lst = 1; i <= n; i++) {
			if (s[i] == 'W') {
				if (lst < i) {
					Add(lst, i - 1);
				}
				lst = i + 1;
			} else if (i == n) {
				Add(lst, i);
			}
		}
		sort(vec.begin(), vec.end());
		vector<int> li;
		for (auto &P : vec) {
			int l = P.second.first, r = P.second.second;
			for (int i = l; i <= r; i++) li.push_back(i);
		}
		for (int i = r1; i >= 1; i--) li.push_back(i);
		for (int i = l2; i <= n; i++) li.push_back(i);
		for (int i = 0; i < min((int)li.size(), k); i++) s[li[i]] = 'W';
		int ans = 0;
		for (int i = 1; i <= n; i++) if (s[i] == 'W') ans += (i != 1 && s[i - 1] == 'W' ? 2 : 1);
		printf("%d\n", ans);
	}
	return 0;
}
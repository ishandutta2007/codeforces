#include <bits/stdc++.h>
using namespace std;
int n, a[105], l[105], ss[105], b[105], ans;
inline void gao(const vector<int> &ng, const vector<int> &ps, const vector<int> &vec, int lim) {
	for (int i = 0; i < (int)vec.size(); i++) {
		a[vec[i]] = (i < lim) ? ng[i] : ((i < lim + (int)ps.size()) ? ps[i - lim] : ng[i - ps.size()]);
	}
	ss[0] = 0;
	int k = 0;
	for (int i = 1; i <= n; i++) {
		ss[i] = ss[i - 1] + a[i];
		if (ss[i] < 0) k = i;
	}
	if (ans > k) {
		ans = k;
		for (int i = 1; i <= n; i++) b[i] = a[i];
	}
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		vector<int> ps, ng, vec;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &l[i]);
			if (!l[i]) {
				vec.push_back(i);
				if (a[i] >= 0) ps.push_back(a[i]);
				else ng.push_back(a[i]);
			}
		}
		sort(ps.begin(), ps.end());
		reverse(ps.begin(), ps.end());
		sort(ng.begin(), ng.end());
		ans = n + 1;
		for (int tmp = 0; tmp < 2; tmp++) {
			for (int i = 0; i <= (int)ng.size(); i++) {
				for (int t1 = 0; t1 < 2; t1++) {
					for (int t2 = 0; t2 < 2; t2++) {
						gao(ng, ps, vec, i);
						if (i < (int)ng.size()) reverse(ng.begin() + i, ng.end());
					}
					if (i) reverse(ng.begin(), ng.begin() + i);
				}
			}
			reverse(ng.begin(), ng.end());
		}
		for (int i = 1; i <= n; i++) printf("%d%c", b[i], " \n"[i == n]);
	}
	return 0;
}
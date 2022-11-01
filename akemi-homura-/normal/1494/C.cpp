#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
namespace F {
	int n, m, a[N], b[N], psa[N];
	inline int gao(vector<int> va, vector<int> vb) {
		n = va.size();
		m = vb.size();
		for (int i = 1; i <= n; i++) a[i] = va[i - 1];
		set<int> stb;
		for (int i = 1; i <= m; i++) b[i] = vb[i - 1], stb.insert(b[i]);
		psa[n + 1] = 0;
		for (int i = n; i >= 1; i--) {
			psa[i] = psa[i + 1] + stb.count(a[i]);
		}
		int ans = psa[1];
		for (int i = 1; i <= n; i++) {
			int ql = a[i], qr = (i < n ? a[i + 1] - 1 : 1000000010), mx = 0;
			int l = lower_bound(b + 1, b + 1 + m, ql - i + 1) - b;
			int r = upper_bound(b + 1, b + 1 + m, ql) - b - 1;
			while (r <= m && b[r] <= qr) {
				while (l <= r && b[r] - b[l] + 1 > i) l++;
				mx = max(mx, r - l + 1);
				r++;
			}
			ans = max(ans, psa[i + 1] + mx);
		}
		return ans;
	}
}
int n, m, a[N], b[N];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		vector<int> a1, a2, b1, b2;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			if (a[i] < 0) a1.push_back(-a[i]);
			else a2.push_back(a[i]);
		}
		for (int i = 1; i <= m; i++) {
			scanf("%d", &b[i]);
			if (b[i] < 0) b1.push_back(-b[i]);
			else b2.push_back(b[i]);
		}
		reverse(a1.begin(), a1.end());
		reverse(b1.begin(), b1.end());
		printf("%d\n", F::gao(a1, b1) + F::gao(a2, b2));
	}
	return 0;
}
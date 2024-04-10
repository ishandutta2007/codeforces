#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

int get_k(int n) {
	int k = 0;
	while (((k * (k + 1)) >> 1) <= n)
		k++;
	return k - 1;
}

int q[N];
vector<int> a[N];
vector<int> L, LIS;
vector<vector<int>> ans;
void dividing(vector<int> p) {
	if (!p.size())
		return;
	for (int i = 0; i < (signed) p.size(); i++)
		q[p[i]] = i;
 	L.clear();
	for (auto x : p) {
		if (!L.size() || x > L.back()) {
			a[L.size()].push_back(x);
			L.push_back(x);
		} else {
			vector<int>::iterator it = lower_bound(L.begin(), L.end(), x);
			*it = x;
			a[it - L.begin()].push_back(x);
		}
	}
	int k = get_k(p.size());
	if ((signed) L.size() <= k) {
		for (int i = 0; i < (signed) L.size(); i++) {
			ans.push_back(a[i]);
		}
		for (int i = 0; i < (signed) L.size(); i++) {
			a[i].clear();
		}
	} else {
		int ls = p.size();
		for (int i = (signed) L.size() - 1; ~i; i--) {
			while (q[a[i].back()] > ls) {
				a[i].pop_back();
			}
			LIS.push_back(a[i].back());
			ls = q[a[i].back()];
			a[i].clear();
		}
		reverse(LIS.begin(), LIS.end());
		ans.push_back(LIS);
		vector<int> np;
		reverse(p.begin(), p.end());
		for (auto x : p) {
			if (!LIS.empty() && LIS.back() == x) {
				LIS.pop_back();
			} else {
				np.push_back(x);
			}
		}
		reverse(np.begin(), np.end());
		dividing(np);
	}
}

int T, n;
int p[N];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", p + i);
		ans.clear();
		dividing(vector<int>(p + 1, p + n + 1));
		printf("%d\n", (signed) ans.size());
		for (auto& vec : ans) {
			printf("%d", (signed) vec.size());
			for (auto x : vec)
				printf(" %d", x);
			putchar('\n');
		}
	}
	return 0;
}
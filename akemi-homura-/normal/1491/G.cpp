#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, a[N], vis[N];
vector<pair<int, int> > ans;
vector<vector<int> > vc;
void gao(vector<int> v1, vector<int> v2) {
	ans.emplace_back(v1.back(), v2.back());
	for (int i = 0; i < (int)v2.size() - 1; i++) ans.emplace_back(v1.back(), v2[i]);
	for (int i = 0; i < (int)v1.size() - 1; i++) ans.emplace_back(v2.back(), v1[i]);
	ans.emplace_back(v1.back(), v2.back());
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) if (!vis[i]) {
		int j = i;
		vector<int> v;
		while (!vis[j]) {
			v.push_back(j);
			vis[j] = 1;
			j = a[j];
		}
		if (v.size() > 1) vc.push_back(v);
	}
	while (vc.size() > 1) {
		vector<int> v1 = vc.back(); vc.pop_back();
		vector<int> v2 = vc.back(); vc.pop_back();
		gao(v1, v2);
	}
	if (vc.size()) {
		vector<int> v = vc[0];
		if (v.size() > 2) {
			ans.emplace_back(v[0], v[1]);
			ans.emplace_back(v[1], v[2]);
			ans.emplace_back(v[0], v[2]);
			for (int i = 3; i < (int)v.size(); i++) ans.emplace_back(v[1], v[i]);
			ans.emplace_back(v[0], v[1]);
		} else {
			int p1 = v[0], p2 = v[1], p3 = ((p1 != 1 && p2 != 1) ? 1 : ((p1 != 2 && p2 != 2) ? 2 : 3));
			ans.emplace_back(p1, p3);
			ans.emplace_back(p2, p3);
			ans.emplace_back(p1, p3);
		}
	}
	printf("%d\n", (int)ans.size());
	for (auto &P : ans) printf("%d %d\n", P.first, P.second);
	return 0;
}
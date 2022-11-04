#include <bits/stdc++.h>
using namespace std;
const int N = 15005;
int n;
vector<pair<int, int> > ans;
int main() {
	scanf("%d", &n);
	int t = n;
	vector<int> vec;
	for (int b = 2; b <= t; b <<= 1) {
		int r = t % b;
		if (r) vec.push_back(b >> 1);
		t -= r;
		for (int i = 1; i <= t; i += b) {
			for (int j = 0; j < (b >> 1); j++) {
				ans.emplace_back(i + j, i + j + (b >> 1));
			}
		}
	}
	if (t) vec.push_back(t);
	vector<int> ps(vec.size() + 1);
	ps.back() = 0;
	for (int i = vec.size() - 1; i >= 0; i--) ps[i] = ps[i + 1] + vec[i];
	vector<int> bu;
	t = vec[0];
	for (int i = 0; i < vec[0]; i++) bu.push_back(n - i);
	int c = 1;
	for (int i = 1; i < (int)vec.size() - 1; i++) {
		while (t < vec[i]) {
			for (int j = 0; j < t; j++) {
				ans.emplace_back(bu[j], c);
				bu.push_back(c);
				c++;
			}
			t <<= 1;
			assert((int)bu.size() == t);
		}
		for (int j = 0; j < t; j++) {
			ans.emplace_back(bu[j], ps[i] - j);
			bu.push_back(ps[i] - j);
		}
		t <<= 1;
	}
	printf("%d\n", (int)ans.size());
	for (auto &P : ans) printf("%d %d\n", P.first, P.second);
	return 0;
}
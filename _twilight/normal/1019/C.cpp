#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e6 + 5;

int n, m;
boolean rem[N], sec[N];
vector<int> Gi[N], Go[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		Gi[v].push_back(u);
		Go[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		if (!rem[i]) {
			for (auto e : Go[i]) {
				(e > i) && (rem[e] = true);
			}
		}
	}
	vector<int> ans;
	for (int i = n; i; i--) {
		if (!rem[i]) {
			boolean aflag = true;
			for (auto e : Gi[i]) {
				if (sec[e]) {
					aflag = false;
					break;
				}
			}
			if (aflag) {
				ans.push_back(i);
				sec[i] = true;
			}
		}
	}
	printf("%d\n", (signed) ans.size());
	for (auto x : ans)
		printf("%d ", x);
	return 0;
}
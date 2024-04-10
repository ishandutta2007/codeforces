#include "bits/stdc++.h"
using namespace std;

int main() {
	int n; int K;
	while (~scanf("%d%d", &n, &K)) {
		vector<int> ps(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &ps[i]);
		vector<int> cs(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &cs[i]);
		vector<pair<int, int>> ord(n);
		for (int i = 0; i < n; ++ i) ord[i] = { ps[i], i };
		sort(ord.begin(), ord.end());
		priority_queue<int> pq;
		vector<long long> ans(cs.begin(), cs.end());
		for (int i = 0, j = 0; i != n; i = j) {
			for (; j != n && ord[j].first == ord[i].first; ++ j) {
				vector<int> v;
				for (int k = 0; k < K && !pq.empty(); ++ k) {
					v.push_back(pq.top());
					pq.pop();
				}
				ans[ord[j].second] += accumulate(v.begin(), v.end(), 0LL);
				for (int c : v) pq.push(c);
			}
			for (int k = i; k < j; ++ k)
				pq.push(cs[ord[k].second]);
		}
		for (int i = 0; i < (int)ans.size(); ++ i) {
			if (i != 0) putchar(' ');
			printf("%lld", ans[i]);
		}
		puts("");
	}
}